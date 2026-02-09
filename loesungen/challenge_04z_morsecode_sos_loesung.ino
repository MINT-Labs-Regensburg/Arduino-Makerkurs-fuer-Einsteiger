/*
Challenge 05z: "Lass die LED im Morsecode SOS blinken" - MUSTERLÖSUNG
====================================================================
*/

const int ledPin = 8; // Digital Output für externe LED

void setup()
{
    pinMode(ledPin, OUTPUT);
}

void loop()
{
    // S: kurz kurz kurz
    for (int i = 0; i < 3; i++)
    {
        digitalWrite(ledPin, HIGH);
        delay(200);
        digitalWrite(ledPin, LOW);
        delay(200);
    }
    // O: lang lang lang
    for (int i = 0; i < 3; i++)
    {
        digitalWrite(ledPin, HIGH);
        delay(600);
        digitalWrite(ledPin, LOW);
        delay(200);
    }
    // S: kurz kurz kurz
    for (int i = 0; i < 3; i++)
    {
        digitalWrite(ledPin, HIGH);
        delay(200);
        digitalWrite(ledPin, LOW);
        delay(200);
    }
    delay(1200); // Pause zwischen SOS
}
