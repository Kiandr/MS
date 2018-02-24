/**
* Sample code for the GetShipmentReceipt Canada Post service.
* 
* The GetShipmentReceipt service is used to retrieve the shipment credit card receipt in XML 
* format for a shipment created by a prior no-manifest "create shipment" call with method of payment = CreditCard.
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

namespace GetShipmentReceipt
{
    class GetShipmentReceipt
    {
        static void Main(string[] args)
        {
            // Your username, password and customer number are imported from the following file
            // CPCWS_Shipping_DotNet_Samples\REST\shipping\user.xml 
            var username = ConfigurationSettings.AppSettings["username"];
            var password = ConfigurationSettings.AppSettings["password"];
            var mailedBy = ConfigurationSettings.AppSettings["customerNumber"];
            var mobo = ConfigurationSettings.AppSettings["customerNumber"];

            // REST URI
            var url = "https://ct.soa-gw.canadapost.ca/rs/" + mailedBy + "/" + mobo + "/shipment/242281375808077657/receipt";

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
                request.Accept = "application/vnd.cpc.shipment-v8+xml";

                // Execute REST Request
                HttpWebResponse response = (HttpWebResponse)request.GetResponse();

                responseAsString += "HTTP Response Status: " + (int)response.StatusCode + "\r\n\r\n";

                // Deserialize xml response to ShipmentReceiptType object
                XmlSerializer serializer = new XmlSerializer(typeof(ShipmentReceiptType));
                TextReader reader = new StreamReader(response.GetResponseStream());
                ShipmentReceiptType shipmentReceipt = (ShipmentReceiptType)serializer.Deserialize(reader);

                // Retrieve values from ShipmentReceiptType object
                if (shipmentReceipt.Item.GetType() == typeof(ShipmentReceiptTypeCcreceiptdetails))
                {
                    ShipmentReceiptTypeCcreceiptdetails receiptDetails = (ShipmentReceiptTypeCcreceiptdetails)shipmentReceipt.Item;
                    responseAsString += "Auth Code: " + receiptDetails.authcode + "\r\n";
                    responseAsString += "Auth Timestamp: " + receiptDetails.authtimestamp + "\r\n";
                    responseAsString += "Charge Amount: " + receiptDetails.chargeamount + "\r\n";
                    responseAsString += "Currency: " + receiptDetails.currency + "\r\n";
                    responseAsString += "Merchant Name: " + receiptDetails.merchantname + "\r\n";
                    responseAsString += "Merchant URL: " + receiptDetails.merchanturl + "\r\n";
                    responseAsString += "Name on Card: " + receiptDetails.nameoncard + "\r\n";
                    responseAsString += "Card Type: " + receiptDetails.cardtype + "\r\n";
                    responseAsString += "Transaction Type: " + receiptDetails.transactiontype + "\r\n";
                }
                else
                {
                    ShipmentReceiptTypeSupplieraccountreceiptdetails receiptDetails = (ShipmentReceiptTypeSupplieraccountreceiptdetails)shipmentReceipt.Item;
                    responseAsString += "Auth Code: " + receiptDetails.authcode + "\r\n";
                    responseAsString += "Auth Timestamp: " + receiptDetails.authtimestamp + "\r\n";
                    responseAsString += "Charge Amount: " + receiptDetails.chargeamount + "\r\n";
                    responseAsString += "Currency: " + receiptDetails.currency + "\r\n";
                    responseAsString += "Merchant Name: " + receiptDetails.merchantname + "\r\n";
                    responseAsString += "Merchant URL: " + receiptDetails.merchanturl + "\r\n";
                    responseAsString += "Supplier Id: " + receiptDetails.supplierid + "\r\n";
                    responseAsString += "Transaction Type: " + receiptDetails.transactiontype + "\r\n";
                }
                
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
