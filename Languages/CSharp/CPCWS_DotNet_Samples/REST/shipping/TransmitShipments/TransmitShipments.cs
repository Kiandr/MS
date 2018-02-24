/**
* Sample code for the TransmitShipments Canada Post service.
* 
* The TransmitShipments service is used to specify shipments to be included in a manifest. 
* Inclusion in a manifest is specified by group. Specific shipments may be excluded if 
* desired.
*
* This sample is configured to access the Developer Program sandbox environment. 
* Use your development key username and password for the web service credentials.
* 
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

namespace TransmitShipments
{
    class TransmitShipments
    {
        static void Main(string[] args)
        {
            // Your username, password and customer number are imported from the following file
            // CPCWS_Shipping_DotNet_Samples\REST\shipping\user.xml 
            var username = ConfigurationSettings.AppSettings["username"];
            var password = ConfigurationSettings.AppSettings["password"];
            var mailedBy = ConfigurationSettings.AppSettings["customerNumber"];
            var mobo = ConfigurationSettings.AppSettings["customerNumber"];

            var url = "https://ct.soa-gw.canadapost.ca/rs/" + mailedBy + "/" + mobo + "/manifest"; // REST URL
            var method = "POST"; // HTTP Method
            var responseAsString = "";

            // Create transmit object to contain xml request
            ShipmentTransmitSetType transmit = new ShipmentTransmitSetType();
            transmit.groupids = new String[1];
            transmit.manifestaddress = new ManifestAddressType();
            transmit.manifestaddress.addressdetails = new AddressDetailsType();

            // Populate transmit object
            transmit.groupids[0] = "4326432";
            transmit.requestedshippingpoint = "K1K4T3";
            transmit.cpcpickupindicator = true;
            transmit.cpcpickupindicatorSpecified = true;
            transmit.detailedmanifests = true;
            transmit.methodofpayment = "Account";
            transmit.manifestaddress.manifestcompany = "MajorShop";
            transmit.manifestaddress.phonenumber = "514 829 5879";
            transmit.manifestaddress.addressdetails.addressline1 = "1230 Tako RD.";
            transmit.manifestaddress.addressdetails.city = "Ottawa";
            transmit.manifestaddress.addressdetails.provstate = "ON";
            transmit.manifestaddress.addressdetails.postalzipcode = "K2B8J6";            
           
            try
            {

                // Serialize transmit object to String
                StringBuilder transmitSb = new StringBuilder();
                XmlWriter transmitXml = XmlWriter.Create(transmitSb);
                transmitXml.WriteProcessingInstruction("xml", "version=\"1.0\" encoding=\"UTF-8\"");
                XmlSerializer serializerRequest = new XmlSerializer(typeof(ShipmentTransmitSetType));
                serializerRequest.Serialize(transmitXml, transmit);

                // Create REST Request
                HttpWebRequest request = (HttpWebRequest)WebRequest.Create(url);
                request.Method = method;

                // Set Basic Authentication Header using username and password variables
                string auth = "Basic " + Convert.ToBase64String(Encoding.Default.GetBytes(username + ":" + password));
                request.Headers = new WebHeaderCollection();
                request.Headers.Add("Authorization", auth);

                // Write Post Data to Request
                UTF8Encoding encoding = new UTF8Encoding();
                byte[] buffer = encoding.GetBytes(transmitSb.ToString());
                request.ContentLength = buffer.Length;
                request.Headers.Add("Accept-Language", "en-CA");
                request.Accept = "application/vnd.cpc.manifest-v8+xml";
                request.ContentType = "application/vnd.cpc.manifest-v8+xml";
                Stream PostData = request.GetRequestStream();
                PostData.Write(buffer, 0, buffer.Length);
                PostData.Close();

                // Execute REST Request
                HttpWebResponse response = (HttpWebResponse)request.GetResponse();

                responseAsString += "HTTP Response Status: " + (int)response.StatusCode + "\r\n\r\n";

                // Deserialize response to manifests object
                XmlSerializer serializer = new XmlSerializer(typeof(ManifestsType));
                TextReader reader = new StreamReader(response.GetResponseStream());
                ManifestsType manifests = (ManifestsType)serializer.Deserialize(reader);

                // Retrieve values from manifests object
                foreach (LinkType link in manifests.link)
                {
                    responseAsString += link.rel + ":  " + link.href + "\r\n";
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
