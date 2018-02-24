/**
* Sample code for the GetCustomerInformation Canada Post service.
* 
* The GetCustomerInformation service retrieves general information about a Canada Post 
* customer, including contract number, the valid payers, the allowed methods of 
* payment for each payer and links to mailed-on-behalf-of customers (if they exist), 
* both past and present. (The customer is identified by the mailed-by customer number.)
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

namespace GetCustomerInformation
{
    class GetCustomerInformation
    {
        static void Main(string[] args)
        {
            // Your username, password and customer number are imported from the following file
            // CPCWS_Shipping_DotNet_Samples\REST\shipping\user.xml 
            var username = ConfigurationSettings.AppSettings["username"];
            var password = ConfigurationSettings.AppSettings["password"];
            var mailedBy = ConfigurationSettings.AppSettings["customerNumber"];

            // REST URI
            var url = "https://ct.soa-gw.canadapost.ca/rs/customer/" + mailedBy;

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
                request.Accept = "application/vnd.cpc.customer+xml";

                // Execute REST Request
                HttpWebResponse response = (HttpWebResponse)request.GetResponse();

                responseAsString += "HTTP Response Status: " + (int)response.StatusCode + "\r\n\r\n";

                // Deserialize xml response to customer object
                XmlSerializer serializer = new XmlSerializer(typeof(customer));
                TextReader reader = new StreamReader(response.GetResponseStream());
                customer customer = (customer)serializer.Deserialize(reader);

                // Retrieve values from customer object
                responseAsString += "Customer Number: " + customer.customernumber + "\r\n";
                responseAsString += "\r\nContract Ids:\r\n";

                foreach (String contractId in customer.contracts)
                {
                    responseAsString += "- " + contractId + "\r\n";
                }
                responseAsString += "\r\nPayers:\r\n";                
                foreach (PayerType payer in customer.authorizedpayers)
                {
                    responseAsString += "- Customer Number: " + payer.payernumber + "\r\n";                   
                    var i = 0;
                    foreach (String methodOfPayment in payer.methodsofpayment)
                    {
                        if (i == 0)
                        {
                            responseAsString += "  Payment Method:\r\n";
                        }
                        i++;
                        responseAsString += "  - " + methodOfPayment + "\r\n";
                    }
                    responseAsString += "\r\n";
                }

                if (customer.links != null)
                {
                    foreach (LinkType link in customer.links)
                    {
                        responseAsString += link.rel + ": " + link.href + "\r\n";
                    }
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
