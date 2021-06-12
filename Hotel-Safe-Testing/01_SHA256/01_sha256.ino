#include "sha256.h"
#include <print.h>

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    String hashText = "Hello World";
    String hashed_data = SHA256(hashText);

    Serial.println(hashed_data);
}
