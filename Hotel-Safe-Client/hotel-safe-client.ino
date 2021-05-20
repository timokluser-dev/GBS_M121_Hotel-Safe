/**
 * Hotel Safe Client based on Arduino and C++
 * Main File
 * @version 1.0
 * @author ddemiraj, timokluser-dev
 */

// Libraries
#include "libraries/ArduinoJson.h"

// Custom Header Files
// backend.ino - Is auto included
#include "sha256.h"
#include "keypad.h"
#include "display.h"

// Out scoped Variables
String enteredPin;

void setup()
{
    Serial.begin(9600);
}

void loop()
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
        Serial.println("-- START CHECK ATTEMPT --");

        // generate SHA256 pin
        String pinHashed = Sha256::encrypt(enteredPin);
        Serial.println("SHA256: " + pinHashed);

        // API call
        DynamicJsonDocument request = BackendHelper::prepareJSONDocument();
        request["encryptedPin"] = pinHashed;
        request["badgeNumber"] = JSONNULL;

        String requestJson = BackendHelper::generateJSON(request);
        Serial.println("JSON Request: " + requestJson);

        bool success = true;

        if (success)
        {
            Serial.println("PIN STATUS: CORRECT");

            Serial.println("DO: OPEN SAFE");
        }
        else
        {
            Serial.println("PIN STATUS: WRONG");
        }

        enteredPin = "";
        Serial.println("-- END CHECK ATTEMPT --\n");
    }
    else
    {
        // read pin from keypad
        Serial.println("Read Key");
        String key = Keypad::readKey();

        Serial.println("Entered Key: " + key);
        enteredPin += key;
    }
}
