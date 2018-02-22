using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Net;
using System.Xml.Serialization;
using System.IO;
using System.Configuration;

/**
 * Sample code for the GetPickupRequestDetails Canada Post service.
 * 
 * The GetPickupRequestDetails service gets all available details on a given Pickup Request.
 * 
 * This sample is configured to access the Developer Program sandbox environment. 
 * Use your development key username and password for the web service credentials.
 * 
 */
namespace GetPickupRequestDetails
{
    class GetPickupRequestDetails
    {
        static void Main(string[] args)
        {
            // Your username and password are imported from the following file
            // CPCWS_Pickup_DotNet_Samples\REST\pickup\user.xml 
            var username = ConfigurationSettings.AppSettings["username"];
            var password = ConfigurationSettings.AppSettings["password"];
            var customerNumber = ConfigurationSettings.AppSettings["customerNumber"];

            var url = "https://ct.soa-gw.canadapost.ca/enab/" + customerNumber + "/pickuprequest/0074698052/details"; // REST URL

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
                request.Accept = "application/vnd.cpc.pickuprequest+xml";

                // Execute REST Request
                HttpWebResponse response = (HttpWebResponse)request.GetResponse();

                responseAsString += "HTTP Response Status: " + (int)response.StatusCode + "\r\n\r\n";

                // Deserialize xml response to PickupRequestsType object
                XmlSerializer serializer = new XmlSerializer(typeof(PickupRequestDetailedInfoType));
                TextReader reader = new StreamReader(response.GetResponseStream());
                PickupRequestDetailedInfoType pickupRequestDetailedInfo = (PickupRequestDetailedInfoType)serializer.Deserialize(reader);

                // Retrieve values from PickupRequestDetailedInfoType object
                PickupRequestHeaderType header = pickupRequestDetailedInfo.pickuprequestheader;
                PickupRequestResponseDetailsType details = pickupRequestDetailedInfo.pickuprequestdetails;
                responseAsString += "Request Id: " + header.requestid + "\r\n";
                responseAsString += "Request Status: " + header.requeststatus + "\r\n";
                responseAsString += "Pickup Type: " + header.pickuptype + "\r\n";
                responseAsString += "Request Date: " + header.requestdate.ToString("yyyy-MM-dd") + "\r\n";
                responseAsString += "Pickup Volume: " + details.pickupvolume + "\r\n";
                responseAsString += "Pickup Instructions: " + details.locationdetails.pickupinstructions + "\r\n";
                
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
