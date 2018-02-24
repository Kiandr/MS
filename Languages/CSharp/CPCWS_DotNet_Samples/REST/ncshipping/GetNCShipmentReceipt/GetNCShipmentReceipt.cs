/**
* Sample code for the GetNonContractShipmentReceipt Canada Post service.
* 
* The GetNonContractShipmentReceipt service is used to retrieve XML details 
* regarding the shipment paid for in the Create Non-Contract Shipment call. 
*
* This sample is configured to access the Developer Program sandbox environment. 
* Use your development key username and password for the web service credentials.
* 
**/

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Configuration;
using System.Net;
using System.Xml.Serialization;
using System.IO;

namespace GetNCShipmentReceipt
{
    class GetNCShipmentReceipt
    {
        static void Main(string[] args)
        {
            // Your username, password and customer number are imported from the following file
            // CPCWS_NCShipping_DotNet_Samples\REST\noncontractshipping\user.xml 
            var username = ConfigurationSettings.AppSettings["username"];
            var password = ConfigurationSettings.AppSettings["password"];
            var mailedBy = ConfigurationSettings.AppSettings["customerNumber"];

            // REST URI
            var url = "https://ct.soa-gw.canadapost.ca/rs/" + mailedBy + "/ncshipment/406951321983787352/receipt";

            var method = "GET"; // HTTP Method
            String responseAsString = ".NET Framework " + Environment.Version.ToString() + "\r\n\r\n";

            try
            {
                // Create REST Request
                HttpWebRequest request = (HttpWebRequest)WebRequest.Create(url);
                request.Method = method;

                // Set Basic Authentication Header using username and password variables
                string auth = "Basic " + Convert.ToBase64String(Encoding.Default.GetBytes(username + ":" + password));
                request.Headers = new WebHeaderCollection();
                request.Headers.Add("Authorization", auth);
                request.Headers.Add("Accept-Language", "en-CA");
                request.Accept = "application/vnd.cpc.ncshipment-v4+xml";

                // Execute REST Request
                HttpWebResponse response = (HttpWebResponse)request.GetResponse();

                responseAsString += "HTTP Response Status: " + (int)response.StatusCode + "\r\n\r\n";

                // Deserialize xml response to NCShipmentReceiptType object
                XmlSerializer serializer = new XmlSerializer(typeof(NonContractShipmentReceiptType));
                TextReader reader = new StreamReader(response.GetResponseStream());
                NonContractShipmentReceiptType shipmentReceipt = (NonContractShipmentReceiptType)serializer.Deserialize(reader);

                // Retrieve values from NCShipmentReceiptType object
                responseAsString += "Shipping Point Name: " + shipmentReceipt.shippingpointname + "\r\n";
                responseAsString += "Service Code: " + shipmentReceipt.servicecode + "\r\n";
                responseAsString += "Merchant Name: " + shipmentReceipt.ccreceiptdetails.merchantname + "\r\n";
            }
            catch (WebException webEx)
            {
                HttpWebResponse response = (HttpWebResponse)webEx.Response;

                if (response != null)
                {
                    responseAsString += "HTTP  Response Status: " + webEx.Message + "\r\n";

                    // Retrieve errors from messages object
                    try
                    {
                        // Deserialize xml response to messages object
                        XmlSerializer serializer = new XmlSerializer(typeof(messages));
                        TextReader reader = new StreamReader(response.GetResponseStream());
                        messages myMessages = (messages)serializer.Deserialize(reader);


                        if (myMessages.message != null)
                        {
                            foreach (var item in myMessages.message)
                            {
                                responseAsString += "Error Code: " + item.code + "\r\n";
                                responseAsString += "Error Msg: " + item.description + "\r\n";
                            }
                        }
                    }
                    catch (Exception ex)
                    {
                        // Misc Exception
                        responseAsString += "ERROR: " + ex.Message;
                    }
                }
                else
                {
                    // Invalid Request
                    responseAsString += "ERROR: " + webEx.Message;
                }

            }
            catch (Exception ex)
            {
                // Misc Exception
                responseAsString += "ERROR: " + ex.Message;
            }

            Console.WriteLine(responseAsString);
            Console.WriteLine("Press any key to continue...");
            Console.ReadKey(true);
        }

    }
}
