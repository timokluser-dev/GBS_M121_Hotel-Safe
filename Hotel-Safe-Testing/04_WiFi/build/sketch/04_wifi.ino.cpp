#include <Arduino.h>
#line 1 "c:\\Users\\tkluser\\Desktop\\Git\\m121_hotel_safe\\Hotel-Safe-Testing\\04_WiFi\\04_wifi.ino"
#include <SoftwareSerial.h>

SoftwareSerial esp8266(9, 10); // RX, TX

#include "src/config.h"
#include "src/library.h"
#include "src/backend.h"

#line 9 "c:\\Users\\tkluser\\Desktop\\Git\\m121_hotel_safe\\Hotel-Safe-Testing\\04_WiFi\\04_wifi.ino"
void setup();
#line 19 "c:\\Users\\tkluser\\Desktop\\Git\\m121_hotel_safe\\Hotel-Safe-Testing\\04_WiFi\\04_wifi.ino"
void loop();
#line 9 "c:\\Users\\tkluser\\Desktop\\Git\\m121_hotel_safe\\Hotel-Safe-Testing\\04_WiFi\\04_wifi.ino"
void setup()
{
    Serial.begin(9600);
    esp8266.begin(115200);

    Wifi::reset();

    Wifi::connect();
}

void loop()
{
    // String data = "{\"encryptedPin\":\"61503690505f84b144e6ac89124540a3eb8d22e77db76500984cfc50a1d8776b\"}";

    // Serial.println(BackendHelper::httpPOSTRequest("192.168.137.1", "47505", "/api/Safes/3fa85f64-5717-4562-b3fc-2c963f66afa6/CanOpen", data));

    Serial.println(BackendHelper::httpGETRequest("192.168.137.1", "80", "/index.html"));

    delay(1000);
}

