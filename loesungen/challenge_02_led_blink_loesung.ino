/*
Challenge 05: "Taster lesen und LED schalten" - Zusatzaufgabe Toggle - MUSTERLÖSUNG
===================================================================================
*/

const int tasterPin = 2; // Digital Input
const int ledPin = 13;   // Digital Output

bool ledStatus = false;
bool lastTasterState = LOW;

void setup()
{
    pinMode(tasterPin, INPUT);
    pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, LOW);
}

void loop()
{
    bool tasterState = digitalRead(tasterPin);

    // Toggle nur bei Flanke von LOW nach HIGH
    if (tasterState == HIGH && lastTasterState == LOW)
    {
        ledStatus = !ledStatus;
        digitalWrite(ledPin, ledStatus ? HIGH : LOW);
        delay(50); // Entprellen
    }

    lastTasterState = tasterState;
}