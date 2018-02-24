/**
* Sample code for the CreateShipment Canada Post service.
* 
* The CreateShipment service is used to create a new shipping item, to 
* request the generation of a softcopy image of shipping labels, and to provide 
* links to these shipping labels and other information associated with the 
* shipping item. 
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
using System.Xml;
using System.Configuration;

namespace CreateShipment
{
    class CreateShipment
    {
        static void Main(string[] args)
        {
            // Your username, password and customer number are imported from the following file
            // CPCWS_Shipping_DotNet_Samples\REST\shipping\user.xml 
            var username = ConfigurationSettings.AppSettings["username"];
            var password = ConfigurationSettings.AppSettings["password"];
            var mailedBy = ConfigurationSettings.AppSettings["customerNumber"];
            var mobo = ConfigurationSettings.AppSettings["customerNumber"];

            var url = "https://ct.soa-gw.canadapost.ca/rs/" + mailedBy + "/" + mobo + "/shipment"; // REST URL

            var method = "POST"; // HTTP Method
            var responseAsString = "";

            // Create shipment object to contain xml request
            ShipmentType shipment = new ShipmentType();
            shipment.deliveryspec = new DeliverySpecType();
            shipment.deliveryspec.sender = new SenderType();
            shipment.deliveryspec.sender.addressdetails = new AddressDetailsType();
            shipment.deliveryspec.destination = new DestinationType();
            shipment.deliveryspec.destination.addressdetails = new DestinationAddressDetailsType();
            shipment.deliveryspec.options = new OptionType[1];
            shipment.deliveryspec.options[0] = new OptionType();
            shipment.deliveryspec.parcelcharacteristics = new ParcelCharacteristicsType();
            shipment.deliveryspec.parcelcharacteristics.dimensions = new ParcelCharacteristicsTypeDimensions();
            shipment.deliveryspec.notification = new NotificationType();
            shipment.deliveryspec.printpreferences = new PrintPreferencesType();
            shipment.deliveryspec.preferences = new PreferencesType();
            shipment.deliveryspec.settlementinfo = new SettlementInfoType();
            shipment.deliveryspec.references = new ReferencesType();

            // Populate shipment object
            //1. regular shipment
            shipment.Item = "123456";

            //2. no manifest shipment
            //shipment.Item = true;

            shipment.requestedshippingpoint = "K1K4T3";
            shipment.cpcpickupindicator = true;
            shipment.cpcpickupindicatorSpecified = true;
            shipment.expectedmailingdate = new DateTime(2011, 08, 24);
            shipment.expectedmailingdateSpecified = true;
            shipment.deliveryspec.sender.addressdetails.addressline1 = "502 MAIN ST N";
            shipment.deliveryspec.sender.addressdetails.city = "MONTREAL";
            shipment.deliveryspec.sender.addressdetails.provstate = "QC";
            shipment.deliveryspec.sender.addressdetails.countrycode = "CA";
            shipment.deliveryspec.sender.addressdetails.postalzipcode = "H2B1A0";
            shipment.deliveryspec.sender.name = "Bulma";
            shipment.deliveryspec.sender.company = "Capsule Corp.";
            shipment.deliveryspec.sender.contactphone = "1 (514) 820 5879";
            shipment.deliveryspec.destination.addressdetails.addressline1 = "123 Postal Drive";
            shipment.deliveryspec.destination.addressdetails.city = "Ottawa";
            shipment.deliveryspec.destination.addressdetails.provstate = "ON";
            shipment.deliveryspec.destination.addressdetails.countrycode = "CA";
            shipment.deliveryspec.destination.addressdetails.postalzipcode = "K1P5Z9";
            shipment.deliveryspec.destination.name = "John Doe";
            shipment.deliveryspec.destination.company = "ACME Corp.";
            shipment.deliveryspec.options[0].optioncode = "DC";
            shipment.deliveryspec.parcelcharacteristics.dimensions.height = 6;
            shipment.deliveryspec.parcelcharacteristics.dimensions.length = 12;
            shipment.deliveryspec.parcelcharacteristics.dimensions.width = 9;
            shipment.deliveryspec.parcelcharacteristics.weight = 5;
            shipment.deliveryspec.notification.email = "ryuko.saito@kubere.com";
            shipment.deliveryspec.notification.ondelivery = true;
            shipment.deliveryspec.notification.onexception = false;
            shipment.deliveryspec.notification.onshipment = true;
            shipment.deliveryspec.printpreferences.outputformat = PrintPreferencesTypeOutputformat.Item85x11;
            shipment.deliveryspec.printpreferences.outputformatSpecified = true;
            shipment.deliveryspec.preferences.showinsuredvalue = true;
            shipment.deliveryspec.preferences.showpackinginstructions = true;
            shipment.deliveryspec.preferences.showpostagerate = true;
            shipment.deliveryspec.settlementinfo.contractid = "0042708517";
            shipment.deliveryspec.settlementinfo.intendedmethodofpayment = "Account";
            shipment.deliveryspec.references.costcentre = "costcentre";
            shipment.deliveryspec.references.customerref1 = "customerref1";
            shipment.deliveryspec.references.customerref2 = "customerref2";
            shipment.deliveryspec.servicecode = "DOM.EP";

            try
            {

                // Serialize shipment object to String
                StringBuilder shipmentSb = new StringBuilder();
                XmlWriter shipmentXml = XmlWriter.Create(shipmentSb);
                shipmentXml.WriteProcessingInstruction("xml", "version=\"1.0\" encoding=\"UTF-8\"");
                XmlSerializer serializerRequest = new XmlSerializer(typeof(ShipmentType));
                serializerRequest.Serialize(shipmentXml, shipment);

                // Create REST Request
                HttpWebRequest request = (HttpWebRequest)WebRequest.Create(url);
                request.Method = method;

                // Set Basic Authentication Header using username and password variables
                string auth = "Basic " + Convert.ToBase64String(Encoding.Default.GetBytes(username + ":" + password));
                request.Headers = new WebHeaderCollection();
                request.Headers.Add("Authorization", auth);

                // Write Post Data to Request
                UTF8Encoding encoding = new UTF8Encoding();
                byte[] buffer = encoding.GetBytes(shipmentSb.ToString());
                request.ContentLength = buffer.Length;
                request.Headers.Add("Accept-Language", "en-CA");
                request.Accept = "application/vnd.cpc.shipment-v8+xml";
                request.ContentType = "application/vnd.cpc.shipment-v8+xml";
                Stream PostData = request.GetRequestStream();
                PostData.Write(buffer, 0, buffer.Length);
                PostData.Close();

                // Execute REST Request
                HttpWebResponse response = (HttpWebResponse)request.GetResponse();

                responseAsString += "HTTP Response Status: " + (int)response.StatusCode + "\r\n\r\n";

                // Deserialize response to shipmentInfo object
                XmlSerializer serializer = new XmlSerializer(typeof(ShipmentInfoType));
                TextReader reader = new StreamReader(response.GetResponseStream());
                ShipmentInfoType shipmentInfo = (ShipmentInfoType)serializer.Deserialize(reader);

                // Retrieve values from shipmentInfo object
                responseAsString += "Shipment ID: " + shipmentInfo.shipmentid + "\r\n";
                foreach (LinkType link in shipmentInfo.links)
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
