#include <Arduino.h>

/*
  LED sanft heller und dunkler werden lassen (Fading) mit ESP32

    - Eine LED ist an einem PWM-fähigen Pin (z.B. GPIO2) angeschlossen.
  - Die Helligkeit wird im Programm automatisch von dunkel zu hell und wieder zurück geregelt.
*/
const int ledPin = 12; // LED an GPIO12

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
    delay(8); // Geschwindigkeit des Fadings
  }
  // LED dunkler werden lassen
  for (int helligkeit = 255; helligkeit >= 0; helligkeit--)
  {
    analogWrite(ledPin, helligkeit);
    delay(8);
  }
}
