/*
Challenge LED 01: "LED-Streifen - Ampelschaltung"
===================================================

Aufbau:
- Verwende einen WS2812B/NeoPixel-LED-Streifen mit mindestens 3 LEDs.
- Verbinde DIN des Streifens mit Digital-Pin 6 am Arduino.
- Verbinde 5V mit 5V und GND mit GND.
- Installiere in der Arduino IDE die Bibliothek "Adafruit NeoPixel".

Aufgaben:
1. Erstelle eine Ampelschaltung auf der ersten LED des Streifens:
   - Rot fuer 3 Sekunden
   - Gelb fuer 1 Sekunde
   - Gruen fuer 3 Sekunden
2. Wiederhole die Ampelschaltung endlos.
3. Erweiterung: Zeige Rot, Gelb und Gruen gleichzeitig auf LED 1, 2 und 3.

Hinweis:
Die Bibliothek wird so eingebunden:
#include <Adafruit_NeoPixel.h>

Lege eine Variable fuer den Datenpin und eine fuer die Anzahl der LEDs an.
Die Farben kannst du mit leds.Color(rot, gruen, blau) erzeugen.
*/

#include <Adafruit_NeoPixel.h>

const int ledPin = 6;
const int anzahlLeds = 10;

Adafruit_NeoPixel leds(anzahlLeds, ledPin, NEO_GRB + NEO_KHZ800);

void setup() {
  leds.begin();
  leds.clear();
  leds.show();
}

void loop() {
  // Schreibe hier deine Ampelschaltung.
}