/*
Challenge 06: "LED Dimmen" - MUSTERLÖSUNG
=========================================
*/

const int ledPin = 11; // PWM-Pin (z.B. Pin 11 mit ~)

void setup()
{
    pinMode(ledPin, OUTPUT);
}

void loop()
{
    // LED heller werden lassen
    for (int i = 0; i <= 255; i++)
    {
        analogWrite(ledPin, i);
        delay(10);
    }
    // LED dunkler werden lassen
    for (int i = 255; i >= 0; i--)
    {
        analogWrite(ledPin, i);
        delay(10);
    }
}
