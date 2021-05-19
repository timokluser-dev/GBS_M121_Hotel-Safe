/**
 * Hotel Safe Client based on Arduino and C++
 * @version 1.0
 * @author ddemiraj, timokluser-dev
 */

#include "api.h"
#include "sha256.h"
#include "keypad.h"
#include "display.h"

String enteredPin = "";

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    printOnDisplay("PIN: " + hidePin(enteredPin));

    // Read PIN
    if (enteredPin.length() == PINLENGTH)
    {
        Serial.println("-- START CHECK ATTEMPT --");

        // generate SHA256 pin
        String pinSha256 = SHA256(enteredPin);
        Serial.println("SHA256: " + pinSha256);

        // API call

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
        String key = readKey();

        Serial.println("Entered Key: " + key);
        enteredPin += key;
    }
}
