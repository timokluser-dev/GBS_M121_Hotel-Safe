/**
 * Hotel Safe Client: Display
 * Used to show the output on the Display
 * @version 1.0
 * @author ddemiraj, timokluser-dev
 * @see https://arduinojson.org
 */

void printOnDisplay(String input)
{
    // show on display

    Serial.println("DISPLAY: " + input);
}

void clearDisplay()
{
    printOnDisplay("");
}

String hidePin(String pin)
{
    Serial.println("DISPLAY: Hide PIN: " + pin);
    String hiddenPin = "";

    for (int i = 0; i < pin.length(); i++)
    {
        hiddenPin += "*";
        i++;
    }

    for (int i = 0; i < (PINLENGTH - hiddenPin.length()); i++)
    {

        hiddenPin += "_";
        i++;
    }

    return hiddenPin;
}