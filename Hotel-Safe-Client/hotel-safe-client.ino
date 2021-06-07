/**
 * Hotel Safe Client based on Arduino and C++
 * Main File
 * @version 1.0
 * @author ddemiraj, timokluser-dev
 */

#include <Arduino.h>
#include <SoftwareSerial.h>

#define ESP8266_TX 9
#define ESP8266_RX 10

SoftwareSerial esp8266(ESP8266_TX, ESP8266_RX);

// Libraries
#include <Keypad.h>
#include "libraries/ArduinoJson.h"
#include "libraries/sha256.h"

// Custom Header Files
#include "src/config.h"
#include "src/backend.h"
#include "src/library.h"

// Out scoped Variables
String enteredPin;
String rawResponse;
bool success;
DynamicJsonDocument response(JSONSIZE);
char key;

void setup()
{
    Serial.begin(9600);
    esp8266.begin(115200);

    Display::initialize();
    Numpad::initialize();
    LED::initialize(12, 13);
    PiezoSummer::initialize(11);
    Wifi::initialize(10);
    RFIDScanner::initialize();

    Wifi::reset();
    Wifi::connect();
}

void loop()
{
    if (Safe::safeIsClosed)
    {
        if (enteredPin.length() == 0)
        {
            Display::print("Enter PIN");
        }
        else
        {
            Display::printPin(enteredPin);
        }

        // Read PIN
        if (enteredPin.length() == PINLENGTH)
        {
            // generate SHA256 pin
            String pinHashed = Sha256::encrypt(enteredPin);
            Serial.println("SHA256: " + pinHashed);

            // API call
            rawResponse = "{\"canOpen\": true,\"badgeRequired\": false,\"isBlocked\": false}"; // mock API response
            // rawResponse = Backend::checkPin(pinHashed, "");
            response = BackendHelper::parseJSON(rawResponse);

            success = response["canOpen"] && !response["badgeRequired"];
            if (success)
            {
                Safe::open();
            }
            else
            {
                Display::print("Read room card");

                String badgeNumber = "";
                do
                {
                    String badgeNumber = RFIDScanner::readBadgeCard();
                } while (badgeNumber == "");

                rawResponse = Backend::checkPin(pinHashed, badgeNumber);
                response = BackendHelper::parseJSON(rawResponse);

                success = response["canOpen"] && !response["badgeRequired"];
                if (success)
                {
                    Safe::open();
                }
                else
                {
                    // pin badge combination false
                    Safe::close();
                }
            }

            enteredPin = "";
        }
        else
        {
            // read pin from keypad
            Serial.println("Read Key");

            do
            {
                key = Numpad::component.getKey();
            } while (!key || !isDigit(key));

            PiezoSummer::piep();

            Serial.println("Entered Key: " + String(key));

            enteredPin += String(key);
        }
    }
    else
    {
        Display::print("SAFE IS OPEN");

        // 10 seconds open
        for (int i = 0; i < 10; i++)
        {
            key = Numpad::component.getKey();

            if (key == "*")
            {
                String newPin;

                while (newPin.length() != PINLENGTH)
                {
                    if (newPin.length() == 0)
                    {
                        Display::print("Enter new PIN");
                    }
                    else
                    {
                        Display::printPin(newPin);
                    }

                    Serial.println("Read Key");

                    do
                    {
                        key = Numpad::component.getKey();
                    } while (!key || !isDigit(key));

                    PiezoSummer::piep();

                    Serial.println("Entered Key: " + String(key));

                    newPin += String(key);
                }

                String newPinEncrypted = Sha256::encrypt(newPin);

                rawResponse = Backend::changePin(newPinEncrypted);
                response = BackendHelper::parseJSON(rawResponse);

                success = response["success"];
                if (success)
                {
                    Display::print("PIN changed");
                }

                break;
            }

            delay(1000);
        }

        Serial.println("Safe closing");
        Safe::close();
    }
}
