﻿/**
* Sample code for the GetPostOfficeDetail Canada Post service.
* 
* The GetPostOfficeDetail service returns Post Office details such as the daily 
* hours of operation for a given Post Office as determined by the first call.
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

namespace GetPostOfficeDetail
{
    class GetPostOfficeDetail
    {
        static void Main(string[] args)
        {
            // Your username and password are imported from the following file
            // CPCWS_PostOffice_DotNet_Samples\REST\postoffice\user.xml  
            var username = ConfigurationSettings.AppSettings["username"];
            var password = ConfigurationSettings.AppSettings["password"];

            // REST URI
            var url = "https://ct.soa-gw.canadapost.ca/rs/postoffice/102978/detail";

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

                // Deserialize xml response to postoffice object
                XmlSerializer serializer = new XmlSerializer(typeof(postofficedetail));
                TextReader reader = new StreamReader(response.GetResponseStream());
                postofficedetail postOffice = (postofficedetail)serializer.Deserialize(reader);

                // Retrieve values from postoffice object
                responseAsString += "Office Name: " + postOffice.name + "\r\n";
                responseAsString += "Address: " + postOffice.address.officeaddress + "\r\n\r\n";

                foreach (var hoursListItem in postOffice.hourslist)
                {
                    responseAsString += "Weekday: " + hoursListItem.day.ToString().Substring(4) + "\r\n";
                    foreach (var timeItem in hoursListItem.time)
                    {
                        responseAsString += "Time: "  + timeItem + "\r\n";
                    }
                    responseAsString += "\r\n";
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
