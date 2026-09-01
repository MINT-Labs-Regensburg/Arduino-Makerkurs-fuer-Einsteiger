/*
Challenge LED 01: "LED-Streifen - Ampelschaltung" - MUSTERLOESUNG
===================================================================
*/

#include <Adafruit_NeoPixel.h>

const int ledPin = 6;
const int anzahlLeds = 10;

Adafruit_NeoPixel leds(anzahlLeds, ledPin, NEO_GRB + NEO_KHZ800);

const uint32_t rot = leds.Color(255, 0, 0);
const uint32_t gelb = leds.Color(255, 255, 0);
const uint32_t gruen = leds.Color(0, 255, 0);

void zeigeAmpel(uint32_t farbe) {
  leds.clear();
  leds.setPixelColor(0, farbe);
  leds.show();
}

void setup() {
  leds.begin();
  leds.clear();
  leds.show();
}

void loop() {
  // Ampelschaltung auf der ersten LED
  zeigeAmpel(rot);
  delay(3000);

  zeigeAmpel(gelb);
  delay(1000);

  zeigeAmpel(gruen);
  delay(3000);

  // Erweiterung: Alle drei Farben gleichzeitig auf LED 1, 2 und 3
  leds.clear();
  leds.setPixelColor(0, rot);
  leds.setPixelColor(1, gelb);
  leds.setPixelColor(2, gruen);
  leds.show();
  delay(3000);
}