/*
Challenge 05: "Digital Output - Lass eine LED blinken" - MUSTERLÖSUNG
=====================================================================
*/

const int ledPin = 8; // Digital Output für externe LED

void setup()
{
    pinMode(ledPin, OUTPUT);
}

void loop()
{
    digitalWrite(ledPin, HIGH); // LED an
    delay(500);
    digitalWrite(ledPin, LOW); // LED aus
    delay(500);
}
