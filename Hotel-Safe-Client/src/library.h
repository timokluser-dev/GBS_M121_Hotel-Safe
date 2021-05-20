/**
 * Hotel Safe Client: Main Library Wrapper
 * @version 1.0
 * @author ddemiraj, timokluser-dev
 */

/**
 * Hotel Safe Client: Display
 * Used to show the output on the Display
 * @version 1.0
 * @author ddemiraj, timokluser-dev
 * @see https://www.arduino.cc/en/Tutorial/LibraryExamples/HelloWorld
 */
class Display
{
private:
    static String hidePin(String pin)
    {
        String hiddenPin;

        for (int i = 0; i < pin.length(); i++)
        {
            hiddenPin += "*";
        }

        for (int i = 0; i < (PINLENGTH - pin.length()); i++)
        {
            hiddenPin += "_";
        }

        return hiddenPin;
    }

public:
    static void print(String input)
    {
        // show on display

        Serial.println("DISPLAY: " + input);
    }

    static void printPin(String pin)
    {
        String toDisplay = "PIN: " + hidePin(pin);

        print(toDisplay);
    }

    static void clear()
    {
        print("");
    }

    static void displayPinWrong()
    {
        print("PIN: Wrong");
        delay(1000);
        print("Please try again");
    }

    static void displayPinCorrect()
    {
        print("PIN: Correct");
        delay(1000);
        print("Welcome");
    }

    static void displayPinBlocked()
    {
        print("PIN: is blocked");
        delay(1000);
        print("Contact reception");
    }
};

/**
 * Hotel Safe Client: Keypad Library
 * Used to get input from the Keypad
 * @version 1.0
 * @author ddemiraj, timokluser-dev
 * @see https://arduinojson.org
 */
class Keypad
{
private:
public:
    static String readKey()
    {
        // TODO: Implementation

        return String("0");
    }
};

/**
 * Hotel Safe Client: LED
 * Used to show corresponding LEDs
 * @version 1.0
 * @author ddemiraj, timokluser-dev
 */
class LED
{
private:
public:
};

/**
 * Hotel Safe Client: PiezoSummer 
 * Used to make sound when PIN Number pressed
 * @version 1.0
 * @author ddemiraj, timokluser-dev
 */
class PiezoSummer
{
private:
public:
};

/**
 * Hotel Safe Client: ShiftRegister 
 * Used to make sound when PIN Number pressed
 * @version 1.0
 * @author ddemiraj, timokluser-dev
 */
class ShiftRegister
{
private:
public:
};

/**
 * Hotel Safe Client: WiFi 
 * Used to connect to the WIFI to call API
 * @version 1.0
 * @author ddemiraj, timokluser-dev
 */
class Wifi
{
private:
public:
};
