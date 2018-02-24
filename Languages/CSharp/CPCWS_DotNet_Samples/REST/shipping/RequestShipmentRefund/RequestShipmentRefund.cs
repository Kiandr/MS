/**
* Sample code for the ShipmentRefundRequest Canada Post service.
* 
* The ShipmentRefundRequest service is used to request a refund for 
* a shipment that has been transmitted. Making this call indicates 
* that the previously printed label is spoiled or will otherwise not be used.
* 
* Note that these are â€œrequests for refundâ€?, as refunding a shipment requires 
* proper verification before being actioned (i.e. ensure label has not been used, for example).
*
* This sample is configured to access the Developer Program sandbox environment. 
* Use your development key username and password for the web service credentials.
**/

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Net;
using System.Xml.Serialization;
using System.IO;
using System.Xml;
using System.Configuration;

namespace RequestShipmentRefund
{
    class RequestShipmentRefund
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
            var url = "https://ct.soa-gw.canadapost.ca/rs/" + mailedBy + "/" + mobo + "/shipment/242281375808077657/refund";
            var method = "POST"; // HTTP Method
            String responseAsString = "";

            try
            {
                // Create shipment object to contain xml request
                ShipmentRefundRequestType shipmentRefundRequest = new ShipmentRefundRequestType();
                shipmentRefundRequest.email = "user@host.com";

                // Serialize shipment object to String
                StringBuilder shipmentRefundRequestSb = new StringBuilder();
                XmlWriter shipmentXml = XmlWriter.Create(shipmentRefundRequestSb);
                shipmentXml.WriteProcessingInstruction("xml", "version=\"1.0\" encoding=\"UTF-8\"");
                XmlSerializer serializerRequest = new XmlSerializer(typeof(ShipmentRefundRequestType));
                serializerRequest.Serialize(shipmentXml, shipmentRefundRequest);

                // Create REST Request
                HttpWebRequest request = (HttpWebRequest)WebRequest.Create(url);
                request.Method = method;

                // Set Basic Authentication Header using username and password variables
                string auth = "Basic " + Convert.ToBase64String(Encoding.Default.GetBytes(username + ":" + password));
                request.Headers = new WebHeaderCollection();
                request.Headers.Add("Authorization", auth);

                // Write Post Data to Request
                UTF8Encoding encoding = new UTF8Encoding();
                byte[] buffer = encoding.GetBytes(shipmentRefundRequestSb.ToString());
                request.ContentLength = buffer.Length;
                request.Headers.Add("Accept-Language", "en-CA");
                request.Accept = "application/vnd.cpc.shipment-v8+xml";
                request.ContentType = "application/vnd.cpc.shipment-v8+xml";
                Stream PostData = request.GetRequestStream();
                PostData.Write(buffer, 0, buffer.Length);
                PostData.Close();

                // Execute REST Request
                HttpWebResponse response = (HttpWebResponse)request.GetResponse();

                responseAsString += "HTTP Response Status: " + (int)response.StatusCode + "\r\n\r\n";

                // Deserialize xml response to ShipmentRefundRequestType object
                XmlSerializer serializer = new XmlSerializer(typeof(ShipmentRefundRequestInfoType));
                TextReader reader = new StreamReader(response.GetResponseStream());
                ShipmentRefundRequestInfoType shipmentRefundRequestInfo = (ShipmentRefundRequestInfoType)serializer.Deserialize(reader);

                // Retrieve values from ShipmentReceiptType object
                responseAsString += "Service Ticket Id: " + shipmentRefundRequestInfo.serviceticketid + "\r\n";
                responseAsString += "Service Ticket Date: " + shipmentRefundRequestInfo.serviceticketdate + "\r\n";
                
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
