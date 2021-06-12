/**
 * Hotel Safe Client: API Library
 * Used to prepare and send data to the backend API
 * @version 1.0
 * @author ddemiraj, timokluser-dev
 */

// reserved JSON size per document [in Bytes]
#define JSONSIZE 100

// alias for C# known `null`
// #define JSONNULL nullptr
#define JSONNULL NULL

// how many digits log the pin is
#define PINLENGTH 6

/**
 * Hotel Safe Client: BackendHelper
 * Used to prepare Data before sending it to the API
 * @version 1.0
 * @author ddemiraj, timokluser-dev
 * @see https://arduinojson.org
 * @see https://www.instructables.com/Arduino-Esp8266-Post-Data-to-Website/
 * @see https://docs.espressif.com/projects/esp-at/en/latest/AT_Command_Set/index.html
 */
class BackendHelper
{
private:
    static String httpRequest(String server, String port, String plainHttpRequest)
    {
        String response;

        esp8266.flush();

        esp8266.println("AT+CIPSTART=\"TCP\",\"" + server + "\"," + port + ""); //start a TCP connection.

        if (esp8266.find("OK"))
        {
            Serial.println("TCP connection ready");
        }
        delay(1000);

        String sendCmd = "AT+CIPSEND=";
        esp8266.print(sendCmd);
        esp8266.println(plainHttpRequest.length());
        delay(500);

        if (esp8266.find(">"))
        {
            Serial.println("Sending...");
            esp8266.print(plainHttpRequest);

            if (esp8266.find("SEND OK"))
            {
                Serial.println("Package sent");
                
                while (esp8266.available())
                {
                    response = esp8266.readString();
                    Serial.println(response);
                }

                esp8266.println("AT+CIPCLOSE");
            }
        }

        return response;
    }

public:
    static String httpPOSTRequest(String server, String port, String uri, String jsonData)
    {
        String response;

        /*
        EXAMPLE FOR POST:
        ----
        POST /api/Safes/3fa85f64-5717-4562-b3fc-2c963f66afa6/CanOpen HTTP/1.1
        Host: localhost:47505
        x-api-key: 05b9c947-7be5-4659-b616-bce2338c22b7
        Content-Type: application/json
        Content-Length: 118

        {
            "encryptedPin": "9af15b336e6a9619928537df30b2e6a2376569fcf9d7e773eccede65606529a0"
        }
        */
        String request =
            "POST " + uri + " HTTP/1.1\r\n" +
            "Host: " + server + ":" + port + "\r\n" +
            "Accept: *" + "/" + "*\r\n" +
            "x-api-key: 05b9c947-7be5-4659-b616-bce2338c22b7\r\n" +
            "Content-Type: application/json\r\n" +
            "Content-Length: " + jsonData.length() + "\r\n" +
            "\r\n" + jsonData;

        response = BackendHelper::httpRequest(server, port, request);

        return response;
    }

    static String httpGETRequest(String server, String port, String uri)
    {
        String response;

        /*
        EXAMPLE FOR GET:
        ----
        GET /api/Safes HTTP/1.1
        Host: localhost:47505
        x-api-key: 05b9c947-7be5-4659-b616-bce2338c22b7
        */
        String request =
            "GET " + uri + " HTTP/1.1\r\n" +
            "Host: " + server + ":" + port + "\r\n" +
            "Accept: *" + "/" + "*\r\n" +
            "x-api-key: 05b9c947-7be5-4659-b616-bce2338c22b7";

        response = BackendHelper::httpRequest(server, port, request);

        return response;
    }
};
