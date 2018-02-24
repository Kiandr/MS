using System;
using System.IO;
using System.Net;

namespace canadaPostAPiPoc
{
    class Program
    {
        static void Main(string[] args)
        {
            WebRequest httpWebRequest = WebRequest.Create("https://sandbox-api.postmen.com/v3/rates");
            string json = "{\"async\":false,\"shipper_accounts\":[{\"id\":\"00000000-0000-0000-0000-000000000000\"}],\"is_document\":false,\"shipment\":{\"parcels\":[{\"description\":\"Food XS\",\"box_type\":\"custom\",\"weight\":{\"value\":2,\"unit\":\"kg\"},\"dimension\":{\"width\":20,\"height\":40,\"depth\":40,\"unit\":\"cm\"},\"items\":[{\"description\":\"Food Bar\",\"origin_country\":\"JPN\",\"quantity\":2,\"price\":{\"amount\":3,\"currency\":\"CAD\"},\"weight\":{\"value\":0.6,\"unit\":\"kg\"},\"sku\":\"PS4-2015\"}]}],\"ship_from\":{\"contact_name\":\"Yin Ting Wong\",\"street1\":\"Flat A, 29/F, Block 17\nLaguna Verde\",\"city\":\"Hung Hom\",\"state\":\"Alberta\",\"postal_code\":\"T5A1H1\",\"country\":\"CAN\",\"phone\":\"+1-613-555-0159\",\"email\":\"test@test.test\",\"type\":\"residential\"},\"ship_to\":{\"contact_name\":\"Yin Ting Wong\",\"street1\":\"Flat A, 29/F, Block 17\nLaguna Verde\",\"city\":\"Hung Hom\",\"state\":\"Alberta\",\"postal_code\":\"T5A1H1\",\"country\":\"CAN\",\"phone\":\"+1-613-555-0159\",\"email\":\"test@test.test\",\"type\":\"residential\"}}}";

            httpWebRequest.ContentType = "application/json";
            httpWebRequest.Method = "POST";
            httpWebRequest.Headers["postmen-api-key"] = "8fc7966b-679b-4a57-911d-c5a663229c9e";

            using (StreamWriter streamWriter = new StreamWriter(httpWebRequest.GetRequestStream()))
            {
                streamWriter.Write(json);
                streamWriter.Flush();
                streamWriter.Close();
            }

            HttpWebResponse httpResponse = (HttpWebResponse)httpWebRequest.GetResponse();
            using (StreamReader streamReader = new StreamReader(httpResponse.GetResponseStream()))
            {
                string result = streamReader.ReadToEnd();
                Console.WriteLine(result);
            }
        }
    }
}
