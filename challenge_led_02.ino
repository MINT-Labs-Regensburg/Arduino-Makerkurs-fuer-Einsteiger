/*
AUFGABE 3: Lauflicht - Ping Pong

Programmiere ein "Ping Pong" Lauflicht:
- Eine LED läuft von links nach rechts
- Am Ende angekommen läuft sie zurück von rechts nach links
- Das wiederholt sich endlos
- Verwende eine schöne Farbe deiner Wahl

Tipp: Du brauchst zwei Schleifen - eine vorwärts, eine rückwärts
*/

#include <Adafruit_NeoPixel.h>

const int ledPin = 6;
const int anzahlLeds = 10;

Adafruit_NeoPixel leds(anzahlLeds, ledPin, NEO_GRB + NEO_KHZ800);

const uint32_t meineFarbe = leds.Color(0, 100, 255);  // Blau

void zeigeLed(int position) {
    leds.clear();
    leds.setPixelColor(position, meineFarbe);
    leds.show();
    delay(100);
}

void setup() {
    leds.begin();
    leds.clear();
    leds.show();
}

void loop() {
    // Von links nach rechts (0 bis 9)
    for (int position = 0; position < anzahlLeds; position++) {
        zeigeLed(position);
    }

    // Von rechts nach links (9 bis 0)
    for (int position = anzahlLeds - 1; position >= 0; position--) {
        zeigeLed(position);
    }
}