/**
* Sample code for the CreateAuthorizedReturn Canada Post service.
* 
* The CreateAuthorizedReturn service is used to create a return shipping label 
* when the sender address and approximate package weight are known. This type of 
* label is typically emailed through a self-serve or service agent process to the
* individual returning the item.
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

namespace CreateAuthReturn
{
    class CreateAuthReturn
    {
        static void Main(string[] args)
        {
            // Your username, password and customer number are imported from the following file
            // CPCWS_Returns_DotNet_Samples\REST\returns\user.xml 
            var username = ConfigurationSettings.AppSettings["username"];
            var password = ConfigurationSettings.AppSettings["password"];
            var mailedBy = ConfigurationSettings.AppSettings["customerNumber"];
            var mobo = ConfigurationSettings.AppSettings["customerNumber"];

            var url = "https://ct.soa-gw.canadapost.ca/rs/" + mailedBy + "/" + mobo + "/authorizedreturn"; // REST URL
            var method = "POST"; // HTTP Method
            var responseAsString = "";

            // Create AuthorizedReturnType object to contain xml request
            AuthorizedReturnType authReturn = new AuthorizedReturnType();
            authReturn.returner = new ReturnerType();
            authReturn.returner.domesticaddress = new DomesticAddressDetailsType();
            authReturn.receiver = new ReceiverType();
            authReturn.receiver.domesticaddress = new DomesticAddressDetailsType();
            authReturn.parcelcharacteristics = new ParcelCharacteristicsType();
            authReturn.parcelcharacteristics.dimensions = new ParcelCharacteristicsTypeDimensions();
            authReturn.printpreferences = new PrintPreferencesType();
            authReturn.settlementinfo = new AuthSettlementInfoType();

            // Populate AuthorizedReturnType object
            authReturn.returner.domesticaddress.addressline1 = "502 MAIN ST N";
            authReturn.returner.domesticaddress.city = "MONTREAL";
            authReturn.returner.domesticaddress.province = "QC";
            authReturn.returner.domesticaddress.postalcode = "H2B1A0";
            authReturn.returner.name = "Bulma";
            authReturn.returner.company = "Capsule Corp.";
            authReturn.receiver.domesticaddress.addressline1 = "123 Postal Drive";
            authReturn.receiver.domesticaddress.city = "Ottawa";
            authReturn.receiver.domesticaddress.province = "ON";
            authReturn.receiver.domesticaddress.postalcode = "K1P5Z9";
            authReturn.receiver.name = "John Doe";
            authReturn.receiver.company = "ACME Corp.";
            authReturn.parcelcharacteristics.dimensions.height = 6;
            authReturn.parcelcharacteristics.dimensions.length = 12;
            authReturn.parcelcharacteristics.dimensions.width = 9;
            authReturn.parcelcharacteristics.weight = 5;
			authReturn.parcelcharacteristics.weightSpecified = true;
            authReturn.printpreferences.encoding = PrintPreferencesTypeEncoding.PDF;
            authReturn.printpreferences.outputformat = PrintPreferencesTypeOutputformat.Item85x11;
            authReturn.settlementinfo.contractid = "0042708517";
            authReturn.servicecode = "DOM.EP";

            try
            {

                // Serialize AuthorizedReturnType object to String
                StringBuilder authReturnSb = new StringBuilder();
                XmlWriter authReturnXml = XmlWriter.Create(authReturnSb);
                authReturnXml.WriteProcessingInstruction("xml", "version=\"1.0\" encoding=\"UTF-8\"");
                XmlSerializer serializerRequest = new XmlSerializer(typeof(AuthorizedReturnType));
                serializerRequest.Serialize(authReturnXml, authReturn);

                // Create REST Request
                HttpWebRequest request = (HttpWebRequest)WebRequest.Create(url);
                request.Method = method;

                // Set Basic Authentication Header using username and password variables
                string auth = "Basic " + Convert.ToBase64String(Encoding.Default.GetBytes(username + ":" + password));
                request.Headers = new WebHeaderCollection();
                request.Headers.Add("Authorization", auth);

                // Write Post Data to Request
                UTF8Encoding encoding = new UTF8Encoding();
                byte[] buffer = encoding.GetBytes(authReturnSb.ToString());
                request.ContentLength = buffer.Length;
                request.Headers.Add("Accept-Language", "en-CA");
                request.Accept = "application/vnd.cpc.authreturn-v2+xml";
                request.ContentType = "application/vnd.cpc.authreturn-v2+xml";
                Stream PostData = request.GetRequestStream();
                PostData.Write(buffer, 0, buffer.Length);
                PostData.Close();

                // Execute REST Request
                HttpWebResponse response = (HttpWebResponse)request.GetResponse();

                responseAsString += "HTTP Response Status: " + (int)response.StatusCode + "\r\n\r\n";

                // Deserialize response to AuthorizedReturnInfoType object
                XmlSerializer serializer = new XmlSerializer(typeof(AuthorizedReturnInfoType));
                TextReader reader = new StreamReader(response.GetResponseStream());
                AuthorizedReturnInfoType authReturnInfo = (AuthorizedReturnInfoType)serializer.Deserialize(reader);

                // Retrieve values from AuthorizedReturnInfoType object
                responseAsString += "Tracking Pin: " + authReturnInfo.trackingpin + "\r\n";
                foreach (LinkType link in authReturnInfo.links)
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
