#include <Arduino.h>
#line 1 "c:\\Users\\tkluser\\Desktop\\Git\\m121_hotel_safe\\Hotel-Safe-Testing\\03_numpad\\03_numpad.ino"
#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 3;

char hexaKeys[ROWS][COLS] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'},
    {'*', '0', '#'}};

byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3};

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

#line 17 "c:\\Users\\tkluser\\Desktop\\Git\\m121_hotel_safe\\Hotel-Safe-Testing\\03_numpad\\03_numpad.ino"
void setup();
#line 22 "c:\\Users\\tkluser\\Desktop\\Git\\m121_hotel_safe\\Hotel-Safe-Testing\\03_numpad\\03_numpad.ino"
void loop();
#line 17 "c:\\Users\\tkluser\\Desktop\\Git\\m121_hotel_safe\\Hotel-Safe-Testing\\03_numpad\\03_numpad.ino"
void setup()
{
  Serial.begin(9600);
}

void loop()
{
  char customKey = customKeypad.getKey();

  if (customKey)
  {
    Serial.println(customKey);
  }
}
