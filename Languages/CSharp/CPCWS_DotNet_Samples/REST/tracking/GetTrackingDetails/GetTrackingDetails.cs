/**
* Sample code for the GetTrackingDetails Canada Post service.
* 
* The GetTrackingDetails service  returns all tracking events recorded for a specified 
* parcel. (The parcel is identified using a PIN or DNC).
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
using System.Configuration;

namespace GetTrackingDetails
{
    class GetTrackingDetails
    {
        static void Main(string[] args)
        {
            // Your username and password are imported from the following file
            // CPCWS_Tracking_DotNet_Samples\REST\tracking\user.xml 
            var username = ConfigurationSettings.AppSettings["username"];
            var password = ConfigurationSettings.AppSettings["password"];

            // PIN Details URI
            var url = "https://ct.soa-gw.canadapost.ca/vis/track/pin/1371134583769923/detail";
            // DNC Details URI
            // var url = "https://ct.soa-gw.canadapost.ca/vis/track/dnc/315052413796541/detail";

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
                request.Accept = "application/vnd.cpc.track+xml";

                // Execute REST Request
                HttpWebResponse response = (HttpWebResponse)request.GetResponse();

                // Deserialize xml response to trackingdetail object
                XmlSerializer serializer = new XmlSerializer(typeof(trackingdetail));
                TextReader reader = new StreamReader(response.GetResponseStream());
                trackingdetail trackingDetail = (trackingdetail)serializer.Deserialize(reader);

                responseAsString += "PIN Number: " + trackingDetail.pin + "\r\n";
                responseAsString += "Signature Exists: " + trackingDetail.signatureimageexists + "\r\n";
                responseAsString += "Suppress Signature: " + trackingDetail.suppresssignature + "\r\n";
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
