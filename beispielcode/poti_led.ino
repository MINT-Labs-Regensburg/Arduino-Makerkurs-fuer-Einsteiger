/*
  Potentiometer auslesen und LED-Helligkeit steuern

  - Ein Potentiometer (Drehregler) ist an A0 angeschlossen.
  - Eine LED ist an einem PWM-Pin (z.B. 9) angeschlossen.
  - Der Wert des Potentiometers (0-1023) wird auf den PWM-Bereich (0-255) umgerechnet.
  - Die LED wird entsprechend heller oder dunkler.
*/

const int potiPin = A0; // Potentiometer an A0
const int ledPin = 9;   // LED an PWM-Pin 9

void setup()
{
    pinMode(ledPin, OUTPUT);
}

void loop()
{
    int sensorWert = analogRead(potiPin); // Wert von 0 bis 1023
    int helligkeit = sensorWert / 4;      // Umrechnen auf 0-255
    analogWrite(ledPin, helligkeit);      // LED-Helligkeit setzen
    delay(10);                            // kleine Pause für sanftes Dimmen
}
