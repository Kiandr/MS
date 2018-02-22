using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Net;
using System.Xml.Serialization;
using System.IO;
using System.Xml;
using System.Configuration;

/**
 * Sample code for the UpdatePickupRequest Canada Post service.
 * 
 * The UpdatePickupRequest service modifies the characteristics of a pickup request (i.e. contact, pickup times, etc.).
 * 
 * This sample is configured to access the Developer Program sandbox environment. 
 * Use your development key username and password for the web service credentials.
 * 
 */
namespace UpdatePickupRequest
{
    class UpdatePickupRequest
    {
        static void Main(string[] args)
        {
            // Your username and password are imported from the following file
            // CPCWS_Pickup_DotNet_Samples\REST\pickup\user.xml 
            var username = ConfigurationSettings.AppSettings["username"];
            var password = ConfigurationSettings.AppSettings["password"];
            var customerNumber = ConfigurationSettings.AppSettings["customerNumber"];

            var url = "https://ct.soa-gw.canadapost.ca/enab/" + customerNumber + "/pickuprequest/0074703712"; // REST URL

            var method = "PUT"; // HTTP Method
            String responseAsString = ".NET Framework " + Environment.Version.ToString() + "\r\n\r\n";

            PickupRequestUpdateDetailsType pickuprequestUpdateDetails = new PickupRequestUpdateDetailsType();

            ContactInfoType contactInfoType = new ContactInfoType();
            contactInfoType.contactname = "John Smith";
            contactInfoType.email = "john.smith@host.com";
            contactInfoType.contactphone = "123-456-7890";

            LocationDetailsType locationDetailsType = new LocationDetailsType();
            locationDetailsType.pickupinstructions = "Door at back";

            OnDemandPickupTimeType onDemand = new OnDemandPickupTimeType();
            onDemand.date = new DateTime(2015, 5, 5);
            onDemand.preferredtime = "13:00";
            onDemand.closingtime = "17:00";

            PickupTimesType pickupTimesType = new PickupTimesType();
            pickupTimesType.Item = onDemand;

            pickuprequestUpdateDetails.contactinfo = contactInfoType;
            pickuprequestUpdateDetails.locationdetails = locationDetailsType;
            pickuprequestUpdateDetails.pickupvolume = "5 parcels";
            pickuprequestUpdateDetails.pickuptimes = pickupTimesType;

            try
            {
                // Serialize shipment object to String
                StringBuilder pickupRequestUpdateSb = new StringBuilder();
                XmlWriter pickuprequestUpdateDetailsXml = XmlWriter.Create(pickupRequestUpdateSb);
                pickuprequestUpdateDetailsXml.WriteProcessingInstruction("xml", "version=\"1.0\" encoding=\"UTF-8\"");
                XmlSerializer serializerRequest = new XmlSerializer(typeof(PickupRequestUpdateDetailsType));
                serializerRequest.Serialize(pickuprequestUpdateDetailsXml, pickuprequestUpdateDetails);

                // Create REST Request
                HttpWebRequest request = (HttpWebRequest)WebRequest.Create(url);
                request.Method = method;

                // Set Basic Authentication Header using username and password variables
                string auth = "Basic " + Convert.ToBase64String(Encoding.Default.GetBytes(username + ":" + password));
                request.Headers = new WebHeaderCollection();
                request.Headers.Add("Authorization", auth);

                // Write Post Data to Request
                UTF8Encoding encoding = new UTF8Encoding();
                byte[] buffer = encoding.GetBytes(pickupRequestUpdateSb.ToString());
                request.ContentLength = buffer.Length;
                request.Headers.Add("Accept-Language", "en-CA");
                request.ContentType = "application/vnd.cpc.pickuprequest+xml";
                Stream PostData = request.GetRequestStream();
                PostData.Write(buffer, 0, buffer.Length);
                PostData.Close();

                // Execute REST Request
                HttpWebResponse response = (HttpWebResponse)request.GetResponse();

                responseAsString += "HTTP Response Status: " + (int)response.StatusCode + "\r\n\r\n";

                if ((int)response.StatusCode == 200)
                {
                    responseAsString += "Pickup Request successfully updated.\r\n";
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
