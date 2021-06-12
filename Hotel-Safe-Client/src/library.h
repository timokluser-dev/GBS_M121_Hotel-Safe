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
    static void initialize()
    {
        // TODO
    }
    static void print(String input)
    {
        Serial.println("DISPLAY: " + input);

        // TODO: Show on display
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
    static void pinWrong()
    {
        print("PIN: Wrong");
        delay(3000);
        print("Please try again");
    }
    static void pinCorrect()
    {
        print("PIN: Correct");
        delay(3000);
        print("Welcome");
    }
    static void pinBlocked()
    {
        print("PIN: is blocked");
        delay(3000);
        print("Contact reception");
    }
};

/**
 * Hotel Safe Client: Numpad Library
 * Used to get input from the Keypad
 * @version 1.0
 * @author ddemiraj, timokluser-dev
 * @see https://www.circuitbasics.com/how-to-set-up-a-keypad-on-an-arduino/
 */
class Numpad
{
private:
public:
    static char hexaKeys[4][3];
    static byte rowPins[4];
    static byte colPins[3];
    static Keypad component;

    static void initialize()
    {
        Numpad::component = Keypad(makeKeymap(Numpad::hexaKeys), Numpad::rowPins, colPins, 4, 3);
    }
};
char Numpad::hexaKeys[4][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'},
    {'*', '0', '#'}};
byte Numpad::rowPins[4] = {8, 7, 6, 5};
byte Numpad::colPins[3] = {4, 3, 2};
Keypad Numpad::component = Keypad(makeKeymap(Numpad::hexaKeys), Numpad::rowPins, colPins, 4, 3);

/**
 * Hotel Safe Client: LED
 * Used to show corresponding LEDs
 * @version 1.0
 * @author ddemiraj, timokluser-dev
 */
class LED
{
private:
    static void ledOn(int pin)
    {
        digitalWrite(pin, HIGH);
    }
    static void ledOff(int pin)
    {
        digitalWrite(pin, LOW);
    }

public:
    static int pinGreen;
    static int pinRed;

    static void initialize(int pinGreen, int pinRed)
    {
        LED::pinGreen = pinGreen;
        LED::pinRed = pinRed;
        pinMode(LED::pinGreen, OUTPUT);
        pinMode(LED::pinRed, OUTPUT);
    }
    static void greenOn()
    {
        LED::ledOn(LED::pinGreen);
    }
    static void greenOff()
    {
        LED::ledOff(LED::pinGreen);
    }
    static void redOn()
    {
        LED::ledOn(LED::pinRed);
    }
    static void redOff()
    {
        LED::ledOff(LED::pinRed);
    }
};
int LED::pinGreen = 0;
int LED::pinRed = 0;

/**
 * Hotel Safe Client: PiezoSummer 
 * Used to make sound when PIN Number pressed
 * @version 1.0
 * @author ddemiraj, timokluser-dev
 * @see https://create.arduino.cc/projecthub/joshi/piezo-christmas-songs-fd1ae9
 */
class PiezoSummer
{
private:
public:
    static int pin;

    static void initialize(int pin)
    {
        PiezoSummer::pin = pin;
        pinMode(PiezoSummer::pin, OUTPUT);
    }
    static void piep()
    {
        tone(PiezoSummer::pin, 1000);
        delay(500);
        noTone(PiezoSummer::pin);
    }
};
int PiezoSummer::pin = 0;

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
    static int wifiConnectionAttempts;
    static int maxWifiConnectionAttempts;

    static void initialize(int maxWifiConnectionAttempts)
    {
        Wifi::maxWifiConnectionAttempts = maxWifiConnectionAttempts;
    }
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

            if (Wifi::wifiConnectionAttempts < Wifi::maxWifiConnectionAttempts)
            {
                Wifi::connect();
            }
            else
            {
                Serial.println("Max wifi connection attempts reached. Program exits");

                // endless loop - used for program exit
                while (1)
                    ;
            }

            Wifi::maxWifiConnectionAttempts++;
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
int Wifi::wifiConnectionAttempts = 0;
int Wifi::maxWifiConnectionAttempts = 20;

/**
 * Hotel Safe Client: RFID Scan
 * Used to scan badge cards when required
 * @version 1.0
 * @author ddemiraj, timokluser-dev
 */
class RFIDScanner
{
private:
public:
    static void initialize()
    {
        // TODO
    }
    static String readBadgeCard()
    {
        return String(random(111111, 999999));
    }
};

/**
 * Hotel Safe Client: Safe
 * Used to handle success or non success of opening attempt. Wrapper for different tasks
 * @version 1.0
 * @author ddemiraj, timokluser-dev
 */
class Safe
{
private:
public:
    static bool safeIsClosed;

    static void open()
    {
        LED::redOff();
        LED::greenOn();
        Display::pinCorrect();
        Safe::safeIsClosed = false;
    }
    static void close()
    {
        LED::greenOff();
        LED::redOn();
        Display::pinWrong();
        Safe::safeIsClosed = true;
    }
};
bool Safe::safeIsClosed = true;
