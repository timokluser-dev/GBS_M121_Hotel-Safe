/**
 * Hotel Safe Client: WiFi 
 * Used to connect to the WIFI to call API
 * @version 1.0
 * @author ddemiraj, timokluser-dev
 * @see https://kunzleigh.com/how-to-connect-an-arduino-to-the-internet-with-an-esp8266-module/
 * @see https://www.instructables.com/Arduino-Esp8266-Post-Data-to-Website/
 */
class Wifi
{
private:
public:
    static void connect()
    {
        esp8266.flush();

        esp8266.println("AT+CWMODE=3");

        String cmd = "AT+CWJAP=\"" + String(HOTELSAFE_WIFI_SSID) + "\",\"" + String(HOTELSAFE_WIFI_PASSKEY) + "\"";
        esp8266.println(cmd);
        delay(4000);
        

        if (esp8266.find("OK"))
        {
            Serial.println("Connected!");
        }
        else
        {
            Serial.println("Cannot connect to wifi");
            Wifi::connect();
        }
    }

    static void reset()
    {
        esp8266.flush();

        esp8266.println("AT+RST");
        delay(1000);

        if (esp8266.find("OK"))
        {
            Serial.println("Module Reset");
        }
    }
};
