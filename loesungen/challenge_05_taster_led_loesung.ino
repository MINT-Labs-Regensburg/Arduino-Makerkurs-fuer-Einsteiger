/*
Challenge 05: "Mit Taster LED schalten" - MUSTERLÖSUNG
======================================================
*/

const int tasterPin = 2; // Digital Input
const int ledPin = 7;    // Digital Output

void setup()
{
    pinMode(tasterPin, INPUT);
    pinMode(ledPin, OUTPUT);
}

void loop()
{
    int tasterState = digitalRead(tasterPin);
    if (tasterState == HIGH)
    {
        digitalWrite(ledPin, HIGH); // LED an
    }
    else
    {
        digitalWrite(ledPin, LOW); // LED aus
    }
}
