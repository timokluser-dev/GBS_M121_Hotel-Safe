/**
 * Hotel Safe Client based on Arduino and C++
 * Main File
 * @version 1.0
 * @author ddemiraj, timokluser-dev
 */

#include <Arduino.h>
#include <SoftwareSerial.h>

#define ESP8266_RX 9
#define ESP8266_TX 10

SoftwareSerial esp8266(ESP8266_RX, ESP8266_TX);

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
DynamicJsonDocument response(JSONSIZE);
char key;

// const byte ROWS = 4;
// const byte COLS = 3;

// char hexaKeys[ROWS][COLS] = {
//     {'1', '2', '3'},
//     {'4', '5', '6'},
//     {'7', '8', '9'},
//     {'*', '0', '#'}};

// byte rowPins[ROWS] = {8, 7, 6, 5};
// byte colPins[COLS] = {4, 3, 2};

// Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup()
{
    Serial.begin(9600);
    esp8266.begin(115200);

    Display::initialize();
    Numpad::initialize();
    LED::initialize(12, 13);     // TODO
    PiezoSummer::initialize(11); // TODO
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
            // String response = Backend::checkPin(pinHashed, "");

            // mock API response
            String rawResponse = "{\"canOpen\": true,\"badgeRequired\": false,\"isBlocked\": false}";
            // rawResponse = Backend::checkPin(pinHashed, "");
            response = BackendHelper::parseJSON(rawResponse);

            bool success = response["canOpen"] && !response["badgeRequired"];
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

                bool success = response["canOpen"] && !response["badgeRequired"];
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

                    Serial.println("Entered Key: " + String(key));

                    newPin += String(key);
                }

                String newPinEncrypted = Sha256::encrypt(newPin);

                rawResponse = Backend::changePin(newPinEncrypted);
                response = BackendHelper::parseJSON(rawResponse);

                // TODO: classmethod `changePin`
                // TODO: API call: http://localhost:47505/api/Safes/3fa85f64-5717-4562-b3fc-2c963f66afa6/ChangePin
                /*
                {
                    "encryptedPin": "61503690505f84b144e6ac89124540a3eb8d22e77db76500984cfc50a1d8776a"
                }
                */

                if (response["success"])
                {
                    Display::print("PIN changed");
                }

                break;
            }

            delay(1000);
        }

        Serial.println("Safe closing");
        Safe::safeIsClosed = true;
    }
}
