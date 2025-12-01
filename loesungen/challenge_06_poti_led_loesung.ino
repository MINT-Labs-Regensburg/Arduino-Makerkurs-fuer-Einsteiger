/*
Challenge 06: "Poti auslesen und LED analog steuern" - MUSTERLÖSUNG
===================================================================
*/

const int potiPin = A0; // Analog Input
const int ledPin = 9;   // PWM Output

void setup()
{
    pinMode(ledPin, OUTPUT);
}

void loop()
{
    int potiWert = analogRead(potiPin); // Wert von 0 bis 1023
    int ledWert = potiWert / 4;         // Umrechnen auf 0 bis 255
    analogWrite(ledPin, ledWert);       // LED-Helligkeit setzen
    delay(10);
}