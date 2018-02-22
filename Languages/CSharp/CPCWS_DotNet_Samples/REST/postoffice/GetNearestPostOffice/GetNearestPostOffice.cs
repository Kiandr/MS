/**
* Sample code for the GetNearestPostOffice Canada Post service.
* 
* The GetNearestPostOffice service returns a list of Post Offices 
* near a given location including information such as address and phone number.
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

namespace GetNearestPostOffice
{
    class GetNearestPostOffice
    {
        static void Main(string[] args)
        {
            // Your username and password are imported from the following file
            // CPCWS_PostOffice_DotNet_Samples\REST\postoffice\user.xml  
            var username = ConfigurationSettings.AppSettings["username"];
            var password = ConfigurationSettings.AppSettings["password"];

            // REST URI
            var url = "https://ct.soa-gw.canadapost.ca/rs/postoffice?postalCode=K2B8J6&maximum=4";

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
                request.Headers.Add("Accept-Language", "fr-CA");
                request.Accept = "application/vnd.cpc.postoffice+xml";

                // Execute REST Request
                HttpWebResponse response = (HttpWebResponse)request.GetResponse();

                // Deserialize xml response to postofficelist object
                XmlSerializer serializer = new XmlSerializer(typeof(postofficelist));
                TextReader reader = new StreamReader(response.GetResponseStream());
                postofficelist postOfficeList = (postofficelist)serializer.Deserialize(reader);

                // Retrieve values from postofficelist object
                foreach (var postOffice in postOfficeList.postoffice)
                {
                    responseAsString += "Office Name: " + postOffice.name + "\r\n";
                    responseAsString += "Office Id: " + postOffice.officeid + "\r\n";
                    responseAsString += "Address: " + postOffice.address.officeaddress + "\r\n\r\n";
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
