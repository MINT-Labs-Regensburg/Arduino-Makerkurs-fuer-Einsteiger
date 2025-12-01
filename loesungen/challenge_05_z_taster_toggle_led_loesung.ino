/*
Challenge 05_z: "LED mit Taster toggeln" - MUSTERLÖSUNG
=======================================================
*/

const int tasterPin = 2; // Digital Input
const int ledPin = 11;   // PWM Output (oder Digital Output)

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
