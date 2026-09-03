/*
Challenge LED 06: Ampelschaltung mit LED-Streifen
=================================================

Aufbau:
- Verwende einen WS2812B/NeoPixel-LED-Streifen mit 10 LEDs.
- Verbinde DIN mit Digital-Pin 16.
- Installiere in der Arduino IDE die Bibliothek "Adafruit NeoPixel".

Die Grundaufgabe zeigt die Ampel nacheinander auf LED 1.
Anschliessend zeigen LED 1, 2 und 3 die drei Farben gleichzeitig.
*/

#include <Adafruit_NeoPixel.h>

const int ledPin = 16;
const int anzahlLeds = 10;

Adafruit_NeoPixel leds(anzahlLeds, ledPin, NEO_GRB + NEO_KHZ800);

void grundaufgabe() {
  // Rot fuer 3 Sekunden.
  leds.clear();
  leds.setPixelColor(0, leds.Color(255, 0, 0));
  leds.show();
  delay(3000);

  // Gelb fuer 1 Sekunde.
  leds.setPixelColor(0, leds.Color(255, 255, 0));
  leds.show();
  delay(1000);

  // Gruen fuer 3 Sekunden.
  leds.setPixelColor(0, leds.Color(0, 255, 0));
  leds.show();
  delay(3000);
}

void erweiterung() {
  // LED 1, 2 und 3 zeigen alle Ampelfarben gleichzeitig.
  leds.clear();
  leds.setPixelColor(0, leds.Color(255, 0, 0));
  leds.setPixelColor(1, leds.Color(255, 255, 0));
  leds.setPixelColor(2, leds.Color(0, 255, 0));
  leds.show();
  delay(3000);
}

void setup() {
  leds.begin();
  leds.clear();
  leds.show();
}

void loop() {
  grundaufgabe();
  erweiterung();
}
