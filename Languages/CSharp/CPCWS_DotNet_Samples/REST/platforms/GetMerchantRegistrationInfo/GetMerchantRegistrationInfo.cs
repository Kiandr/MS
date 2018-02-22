/**
* Sample code for the GetMerchantRegistrationInfo Canada Post service.
* 
* The GetMerchantRegistrationInfo service is called by the ecommerce platform after 
* the merchant has completed the Canada Post sign-up process. This call returns
* merchant data such as customer number and merchant username and password. This
* information is necessary for the platform to perform web service shipping
* transactions for the merchant.
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

namespace GetMerchantRegistrationInfo
{
    class GetMerchantRegistrationInfo
    {
        static void Main(string[] args)
        {
            // Your username and password are imported from the following file
            // CPCWS_Platforms_DotNet_Samples\REST\platforms\user.xml  
            var username = ConfigurationSettings.AppSettings["username"];
            var password = ConfigurationSettings.AppSettings["password"];

            // REST URI
            var url = "https://ct.soa-gw.canadapost.ca/ot/token/1111111111111111111111";

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
                request.Accept = "application/vnd.cpc.registration+xml";

                // Execute REST Request
                HttpWebResponse response = (HttpWebResponse)request.GetResponse();

                // Deserialize xml response to merchantinfo object
                XmlSerializer serializer = new XmlSerializer(typeof(merchantinfo));
                TextReader reader = new StreamReader(response.GetResponseStream());
                merchantinfo merchantInfo = (merchantinfo)serializer.Deserialize(reader);

                // Retrieve values from merchantinfo object
                if ( merchantInfo.customernumber != null )
                {
                    responseAsString += "Customer Number: " + merchantInfo.customernumber + "\r\n";
                }
                if (merchantInfo.contractnumber != null)
                {
                    responseAsString += "Contract Number: " + merchantInfo.contractnumber + "\r\n";
                }
                if (merchantInfo.merchantusername != null)
                {
                    responseAsString += "Merchant Username: " + merchantInfo.merchantusername + "\r\n";
                }
                if (merchantInfo.merchantpassword != null)
                {
                    responseAsString += "Merchant Password: " + merchantInfo.merchantpassword + "\r\n";
                }
                responseAsString += "Has Default CC: " + merchantInfo.hasdefaultcreditcard + "\r\n";

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
