/**
* Sample code for the CreateOpenReturnTemplate Canada Post service.
* 
* The CreateOpenReturnTemplate service is used to request creation of generic
* labels for retrieval and printing. The sender address and parcel weight are
* unknown. Each label has a unique barcode, but the rest of the data is the same.
* The labels can be distributed as part of the original shipment, or sent to a
* specific individual. 
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
using System.Xml;
using System.Xml.Serialization;
using System.Net;
using System.IO;

namespace CreateOpenReturnTemplate
{
    class CreateOpenReturnTemplate
    {
        static void Main(string[] args)
        {
            // Your username, password and customer number are imported from the following file
            // CPCWS_Returns_DotNet_Samples\REST\returns\user.xml 
            var username = ConfigurationSettings.AppSettings["username"];
            var password = ConfigurationSettings.AppSettings["password"];
            var mailedBy = ConfigurationSettings.AppSettings["customerNumber"];
            var mobo = ConfigurationSettings.AppSettings["customerNumber"];

            var url = "https://ct.soa-gw.canadapost.ca/rs/" + mailedBy + "/" + mobo + "/openreturn"; // REST URL
            var method = "POST"; // HTTP Method
            var responseAsString = "";

            // Create OpenReturnType object to contain xml request
            OpenReturnType openReturn = new OpenReturnType();
            openReturn.receiver = new DomesticAddressType();
            openReturn.receiver.domesticaddress = new DomesticAddressDetailsType();
            openReturn.printpreferences = new PrintPreferencesType();
            openReturn.settlementinfo = new SettlementInfoType();

            // Populate OpenReturnType object
            openReturn.maxnumberofartifacts = "10";
            openReturn.receiver.domesticaddress.addressline1 = "123 Postal Drive";
            openReturn.receiver.domesticaddress.city = "Ottawa";
            openReturn.receiver.domesticaddress.province = "ON";
            openReturn.receiver.domesticaddress.postalcode = "K1P5Z9";
            openReturn.receiver.name = "John Doe";
            openReturn.receiver.company = "ACME Corp.";
            openReturn.printpreferences.encoding = PrintPreferencesTypeEncoding.PDF;
            openReturn.printpreferences.outputformat = PrintPreferencesTypeOutputformat.Item85x11;
            openReturn.settlementinfo.contractid = "0042708517";
            openReturn.servicecode = "DOM.EP";

            try
            {

                // Serialize OpenReturnType object to String
                StringBuilder openReturnSb = new StringBuilder();
                XmlWriter openReturnXml = XmlWriter.Create(openReturnSb);
                openReturnXml.WriteProcessingInstruction("xml", "version=\"1.0\" encoding=\"UTF-8\"");
                XmlSerializer serializerRequest = new XmlSerializer(typeof(OpenReturnType));
                serializerRequest.Serialize(openReturnXml, openReturn);

                // Create REST Request
                HttpWebRequest request = (HttpWebRequest)WebRequest.Create(url);
                request.Method = method;

                // Set Basic Authentication Header using username and password variables
                string auth = "Basic " + Convert.ToBase64String(Encoding.Default.GetBytes(username + ":" + password));
                request.Headers = new WebHeaderCollection();
                request.Headers.Add("Authorization", auth);

                // Write Post Data to Request
                UTF8Encoding encoding = new UTF8Encoding();
                byte[] buffer = encoding.GetBytes(openReturnSb.ToString());
                request.ContentLength = buffer.Length;
                request.Headers.Add("Accept-Language", "en-CA");
                request.Accept = "application/vnd.cpc.openreturn-v2+xml";
                request.ContentType = "application/vnd.cpc.openreturn-v2+xml";
                Stream PostData = request.GetRequestStream();
                PostData.Write(buffer, 0, buffer.Length);
                PostData.Close();

                // Execute REST Request
                HttpWebResponse response = (HttpWebResponse)request.GetResponse();

                responseAsString += "HTTP Response Status: " + (int)response.StatusCode + "\r\n\r\n";

                // Deserialize response to OpenReturnInfoType object
                XmlSerializer serializer = new XmlSerializer(typeof(OpenReturnInfoType));
                TextReader reader = new StreamReader(response.GetResponseStream());
                OpenReturnInfoType openReturnInfo = (OpenReturnInfoType)serializer.Deserialize(reader);

                // Retrieve values from OpenReturnInfoType object
                responseAsString += "Artifacts Remaining: " + openReturnInfo.artifactsremaining + "\r\n";
                foreach (LinkType link in openReturnInfo.links)
                {
                    responseAsString += link.rel + ":  " + link.href + "\r\n";
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
