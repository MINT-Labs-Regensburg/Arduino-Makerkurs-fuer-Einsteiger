/*
Challenge 04: "LED Dimmen" - MUSTERLÖSUNG
=========================================
*/

const int ledPin = 11; // PWM-Pin, z.B. 11

void setup()
{
    pinMode(ledPin, OUTPUT);
}

void loop()
{
    // LED heller werden lassen
    for (int helligkeit = 0; helligkeit <= 255; helligkeit++)
    {
        analogWrite(ledPin, helligkeit);
        delay(10);
    }
    // LED dunkler werden lassen
    for (int helligkeit = 255; helligkeit >= 0; helligkeit--)
    {
        analogWrite(ledPin, helligkeit);
        delay(10);
    }
}
