﻿/**
 * Sample code for the GetPickupAvailability Canada Post service.
 * 
 * The GetPickupAvailability service identifies if pickup services 
 * are available for a given Postal Code. This call also provides information 
 * related to the type of pickup available and the cut-off times for pickup service 
 * requests.
 * 
 * This sample is configured to access the Developer Program sandbox environment. 
 * Use your development key username and password for the web service credentials.
 * 
 */

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Net;
using System.Xml.Serialization;
using System.IO;
using System.Configuration;

namespace pickup
{
    class GetPickupAvailability
    {
        static void Main(string[] args)
        {
            // Your username and password are imported from the following file
            // CPCWS_Pickup_DotNet_Samples\REST\pickup\user.xml 
            var username = ConfigurationSettings.AppSettings["username"];
            var password = ConfigurationSettings.AppSettings["password"];

            var url = "https://ct.soa-gw.canadapost.ca/ad/pickup/pickupavailability/K2B8J6"; // REST URL

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
                request.Accept = "application/vnd.cpc.pickup+xml";

                // Execute REST Request
                HttpWebResponse response = (HttpWebResponse)request.GetResponse();

                // Deserialize xml response to pickupavailability object
                XmlSerializer serializer = new XmlSerializer(typeof(pickupavailability));
                TextReader reader = new StreamReader(response.GetResponseStream());
                pickupavailability pickUp = (pickupavailability)serializer.Deserialize(reader);

                // Retrieve values from pickupavailability object
                responseAsString += "Postal Code: " + pickUp.postalcode + "\r\n";
                responseAsString += "On Demand Tour: " + pickUp.ondemandtour + "\r\n";
                responseAsString += "On Demand Cut Off: " + pickUp.ondemandcutoff + "\r\n";
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
