/*
Challenge 05: "Taster lesen und LED schalten" - MUSTERLÖSUNG
============================================================
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
    int tasterStatus = digitalRead(tasterPin);
    if (tasterStatus == HIGH)
    {
        digitalWrite(ledPin, HIGH); // LED an
    }
    else
    {
        digitalWrite(ledPin, LOW); // LED aus
    }
}
