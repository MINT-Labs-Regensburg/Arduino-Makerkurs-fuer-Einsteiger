#include <Arduino.h>

/*
 * Potentiometer auslesen und LED-Helligkeit steuern (ESP32)
 *
 * Schaltung:
 * - Potentiometer (Drehregler) an GPIO33 (ADC, Wertebereich 0-4095)
 * - LED an GPIO12 (PWM-fähig)
 *
 * Funktionsweise:
 * - Der Wert des Potentiometers (0-4095) wird auf den PWM-Bereich (0-255) umgerechnet.
 * - Die LED wird entsprechend heller oder dunkler.
 */

const int potiPin = 33; // Potentiometer an GPIO33 (ADC)
const int ledPin = 12;  // LED an GPIO12 (PWM)

void setup()
{
  pinMode(ledPin, OUTPUT); // LED als Ausgang
}

void loop()
{
  int sensorWert = analogRead(potiPin); // Potentiometer auslesen (0-4095)
  int helligkeit = sensorWert / 16;     // Umrechnen auf 0-255 (4096/256=16)
  analogWrite(ledPin, helligkeit);      // LED-Helligkeit setzen
  delay(10);                            // kleine Pause für sanftes Dimmen
}