/**
* Sample code for the GetSignatureImage Canada Post service.
* 
* The GetSignatureImage  service  returns a signature image captured at delivery 
* of the parcel if available. (The parcel is identified using a PIN only). Please note 
* the following:
*   - U.S.A. and international services do not support signature retrieval.
*   - Signature images are available for 45 days after the last scan.
*   - Recipients of parcels may request suppression of their signature image from view.
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

namespace GetSignatureImage
{
    class GetSignatureImage
    {
        static void Main(string[] args)
        {
            // Your username and password are imported from the following file
            // CPCWS_Tracking_DotNet_Samples\REST\tracking\user.xml 
            var username = ConfigurationSettings.AppSettings["username"];
            var password = ConfigurationSettings.AppSettings["password"];

            var url = "https://ct.soa-gw.canadapost.ca/vis/signatureimage/1371134583769923"; // REST URL

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

                // Deserialize xml response to signatureimage object
                XmlSerializer serializer = new XmlSerializer(typeof(signatureimage));
                TextReader reader = new StreamReader(response.GetResponseStream());
                signatureimage signature = (signatureimage)serializer.Deserialize(reader);

                // Retrieve values from signatureimage object
                var fileName = signature.filename;
                var encodedImage = signature.image;
                responseAsString += "Base64 Encoded: " + encodedImage + "\r\n";
                responseAsString += "File name: " + fileName + "\r\n";
                responseAsString += "Mime type: " + signature.mimetype + "\r\n";
                byte[] decodedImage = Convert.FromBase64String(encodedImage);
                FileStream fileStream = File.Create(fileName);
                fileStream.Write(decodedImage, 0, decodedImage.Length);
                responseAsString += "Decoding to " + Directory.GetCurrentDirectory() + "\\" + fileName + "\r\n";
                fileStream.Close();
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
