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
 * Sample code for the CreatePickupRequest Canada Post service.
 * 
 * The CreatePickupRequest service creates a request for a one-time on-demand pickup or to set up scheduled pickups.
 * 
 * This sample is configured to access the Developer Program sandbox environment. 
 * Use your development key username and password for the web service credentials.
 * 
 */
namespace CreatePickupRequest
{
    class CreatePickupRequest
    {
        static void Main(string[] args)
        {
            // Your username and password are imported from the following file
            // CPCWS_Pickup_DotNet_Samples\REST\pickup\user.xml 
            var username = ConfigurationSettings.AppSettings["username"];
            var password = ConfigurationSettings.AppSettings["password"];
            var customerNumber = ConfigurationSettings.AppSettings["customerNumber"];

            var url = "https://ct.soa-gw.canadapost.ca/enab/" + customerNumber + "/pickuprequest"; // REST URL

            var method = "POST"; // HTTP Method
            String responseAsString = ".NET Framework " + Environment.Version.ToString() + "\r\n\r\n";

            PickupRequestDetailsType pickuprequestDetailsType = new PickupRequestDetailsType();

            PickupLocationType pickupLocationType = new PickupLocationType();
            pickupLocationType.businessaddressflag = true;

            ContactInfoType contactInfoType = new ContactInfoType();
            contactInfoType.contactname = "John Smith";
            contactInfoType.email = "john.smith@host.com";
            contactInfoType.contactphone = "123-456-7890";

            LocationDetailsType locationDetailsType = new LocationDetailsType();
            locationDetailsType.pickupinstructions = "Door at back";

            OnDemandPickupTimeType onDemand = new OnDemandPickupTimeType();
            onDemand.date = new DateTime(2015, 5, 28);
            onDemand.preferredtime = "13:00";
            onDemand.closingtime = "17:00";

            PickupTimesType pickupTimesType = new PickupTimesType();
            pickupTimesType.Item = onDemand;

            pickuprequestDetailsType.pickuptype = PickupTypeType.OnDemand;
            pickuprequestDetailsType.pickuplocation = pickupLocationType;
            pickuprequestDetailsType.contactinfo = contactInfoType;
            pickuprequestDetailsType.locationdetails = locationDetailsType;
            pickuprequestDetailsType.pickupvolume = "5 parcels";
            pickuprequestDetailsType.pickuptimes = pickupTimesType;
            
            try
            {
                // Serialize shipment object to String
                StringBuilder pickupRequestSb = new StringBuilder();
                XmlWriter pickuprequestDetailsTypeXml = XmlWriter.Create(pickupRequestSb);
                pickuprequestDetailsTypeXml.WriteProcessingInstruction("xml", "version=\"1.0\" encoding=\"UTF-8\"");
                XmlSerializer serializerRequest = new XmlSerializer(typeof(PickupRequestDetailsType));
                serializerRequest.Serialize(pickuprequestDetailsTypeXml, pickuprequestDetailsType);

                // Create REST Request
                HttpWebRequest request = (HttpWebRequest)WebRequest.Create(url);
                request.Method = method;

                // Set Basic Authentication Header using username and password variables
                string auth = "Basic " + Convert.ToBase64String(Encoding.Default.GetBytes(username + ":" + password));
                request.Headers = new WebHeaderCollection();
                request.Headers.Add("Authorization", auth);

                // Write Post Data to Request
                UTF8Encoding encoding = new UTF8Encoding();
                byte[] buffer = encoding.GetBytes(pickupRequestSb.ToString());
                request.ContentLength = buffer.Length;
                request.Headers.Add("Accept-Language", "en-CA");
                request.Accept = "application/vnd.cpc.pickuprequest+xml";
                request.ContentType = "application/vnd.cpc.pickuprequest+xml";
                Stream PostData = request.GetRequestStream();
                PostData.Write(buffer, 0, buffer.Length);
                PostData.Close();

                // Execute REST Request
                HttpWebResponse response = (HttpWebResponse)request.GetResponse();

                responseAsString += "HTTP Response Status: " + (int)response.StatusCode + "\r\n\r\n";

                // Deserialize response to pickupRequestInfo object
                XmlSerializer serializer = new XmlSerializer(typeof(PickupRequestInfoType));
                TextReader reader = new StreamReader(response.GetResponseStream());
                PickupRequestInfoType pickupRequestInfo = (PickupRequestInfoType)serializer.Deserialize(reader);

                // Retrieve values from pickupRequestInfo object
                PickupRequestHeaderType header = pickupRequestInfo.pickuprequestheader;
                responseAsString += "Request ID: " + header.requestid + "\r\n";
                responseAsString += "Request Status: " + header.requeststatus + "\r\n";
                responseAsString += "Pickup Type: " + header.pickuptype + "\r\n";
                responseAsString += "Request Date: " + header.requestdate + "\r\n";
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
