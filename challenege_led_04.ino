/*
AUFGABE 4: Regenbogen - Pulsierende Helligkeit

Erstelle einen pulsierenden Regenbogen:
- Zeige alle Regenbogenfarben auf dem LED-Streifen
- Die Helligkeit soll langsam hoch und runter gehen
- Wie ein "atmender" Regenbogen

Tipp: Du musst die RGB-Werte mit einem Faktor multiplizieren
der zwischen 0.1 und 1.0 wechselt
*/

#include <Adafruit_NeoPixel.h>

const int ledPin = 6;
const int anzahlLeds = 10;

Adafruit_NeoPixel leds(anzahlLeds, ledPin, NEO_GRB + NEO_KHZ800);

struct Farbe {
    uint8_t rot;
    uint8_t gruen;
    uint8_t blau;
};

const Farbe regenbogen[anzahlLeds] = {
    {255, 0, 0},    // Rot
    {255, 127, 0},  // Orange
    {255, 255, 0},  // Gelb
    {0, 255, 0},    // Gruen
    {0, 0, 255},    // Blau
    {75, 0, 130},   // Indigo
    {148, 0, 211},  // Violett
    {255, 0, 255},  // Magenta
    {255, 100, 100},
    {100, 255, 255}
};

float helligkeit = 0.1;
float richtung = 0.05;

void setup() {
    leds.begin();
    leds.clear();
    leds.show();
}

void loop() {
    helligkeit += richtung;

    if (helligkeit >= 1.0) {
        helligkeit = 1.0;
        richtung = -0.05;
    } else if (helligkeit <= 0.1) {
        helligkeit = 0.1;
        richtung = 0.05;
    }

    for (int position = 0; position < anzahlLeds; position++) {
        uint8_t rot = regenbogen[position].rot * helligkeit;
        uint8_t gruen = regenbogen[position].gruen * helligkeit;
        uint8_t blau = regenbogen[position].blau * helligkeit;
        leds.setPixelColor(position, leds.Color(rot, gruen, blau));
    }

    leds.show();
    delay(100);
}