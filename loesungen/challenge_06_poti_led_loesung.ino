/*
Challenge 06: "Poti auslesen und LED ansteuern" - MUSTERLÖSUNG
==============================================================
*/

const int potiPin = A0; // Analog Input
const int ledPin = 11;  // PWM Output

void setup()
{
    pinMode(ledPin, OUTPUT);
}

void loop()
{
    int potiWert = analogRead(potiPin);           // Wert von 0 bis 1023
    int ledWert = map(potiWert, 0, 1023, 0, 255); // Umrechnen auf 0 bis 255
    analogWrite(ledPin, ledWert);                 // LED-Helligkeit setzen
    delay(10);
}
