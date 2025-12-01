/*
Challenge 03: "Lass die LED im Morsecode SOS blinken" - MUSTERLÖSUNG
====================================================================
*/

const int ledPin = 7; // Beispiel: Pin 7 für die LED

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
        delay(150);
        digitalWrite(ledPin, LOW);
        delay(150);
    }
    delay(300); // Pause zwischen S und O

    // O: lang lang lang
    for (int i = 0; i < 3; i++)
    {
        digitalWrite(ledPin, HIGH);
        delay(500);
        digitalWrite(ledPin, LOW);
        delay(500);
    }
    delay(300); // Pause zwischen O und S

    // S: kurz kurz kurz
    for (int i = 0; i < 3; i++)
    {
        digitalWrite(ledPin, HIGH);
        delay(150);
        digitalWrite(ledPin, LOW);
        delay(150);
    }
    delay(1000); // Pause vor dem nächsten SOS
}
