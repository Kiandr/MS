/**
* Sample code for the GetManifestArtifact Canada Post service.
* 
* The GetManifestArtifact service is used to retrieve the rendered manifest document(s). 
* May be called more than once to perform a reprint.
*
* This sample is configured to access the Developer Program sandbox environment. 
* Use your development key username and password for the web service credentials.
* 
**/

using System;
using System.Configuration;
using System.IO;
using System.Net;
using System.Text;
using System.Xml.Serialization;

namespace GetManifestArtifact
{
    class GetManifestArtifact
    {
        static void Main(string[] args)
        {
            // Your username and password are imported from the following file
            // CPCWS_Shipping_DotNet_Samples\REST\shipping\user.xml 
            var username = ConfigurationSettings.AppSettings["username"];
            var password = ConfigurationSettings.AppSettings["password"];

            var url = "https://ct.soa-gw.canadapost.ca/ers/artifact/" + username + "/444/0"; // REST URL

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
                request.Accept = "application/pdf";

                // Execute REST Request
                HttpWebResponse response = (HttpWebResponse)request.GetResponse();

                responseAsString += "HTTP Response Status: " + (int)response.StatusCode + "\r\n\r\n";

                // Write Artifact to file
                var mediaStr = response.ContentType;

                String fileName = "manifestArtifact.pdf";
                FileStream fileStream = File.Create(fileName);

                // Create a 4K buffer to chunk the file  
                byte[] buffer = new byte[4096];

                int BytesRead;
                responseAsString += "Writing response to " + Directory.GetCurrentDirectory() + "\\" + fileName + "\r\n";
                // Read the chunk of the web response into the buffer
                while (0 < (BytesRead = response.GetResponseStream().Read(buffer, 0, buffer.Length)))
                {
                    // Write the chunk from the buffer to the file  
                    fileStream.Write(buffer, 0, BytesRead);
                }
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
