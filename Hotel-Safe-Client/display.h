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
