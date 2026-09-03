/*
Challenge LED 05: Farbige LED-Effekte
=====================================

Aufbau:
- Verwende einen WS2812B/NeoPixel-LED-Streifen mit 10 LEDs.
- Verbinde DIN mit Digital-Pin 6 am Arduino.
- Installiere in der Arduino IDE die Bibliothek "Adafruit NeoPixel".

Aufgaben:
1. Beobachte die drei Effekte: Farbverlauf, Lauflicht und Regenbogen.
2. Aendere Farben, Geschwindigkeit und die Dauer der einzelnen Effekte.
3. Erfinde einen vierten Effekt.
*/

#include <Adafruit_NeoPixel.h>

const int ledPin = 6;
const int anzahlLeds = 10;

Adafruit_NeoPixel leds(anzahlLeds, ledPin, NEO_GRB + NEO_KHZ800);

uint32_t farbrad(byte position) {
  position = 255 - position;

  if (position < 85) {
    return leds.Color(255 - position * 3, 0, position * 3);
  }
  if (position < 170) {
    position -= 85;
    return leds.Color(0, position * 3, 255 - position * 3);
  }

  position -= 170;
  return leds.Color(position * 3, 255 - position * 3, 0);
}

void farbverlauf() {
  const uint32_t farben[] = {
    leds.Color(255, 0, 0),
    leds.Color(255, 100, 0),
    leds.Color(255, 255, 0),
    leds.Color(0, 255, 0),
    leds.Color(0, 0, 255),
    leds.Color(180, 0, 255)
  };

  for (int schritt = 0; schritt < 60; schritt++) {
    for (int position = 0; position < anzahlLeds; position++) {
      leds.setPixelColor(position, farben[(position + schritt) % 6]);
    }
    leds.show();
    delay(80);
  }
}

void lauflicht() {
  const uint32_t farbe = leds.Color(0, 180, 255);

  for (int runde = 0; runde < 4; runde++) {
    for (int position = 0; position < anzahlLeds; position++) {
      leds.clear();
      leds.setPixelColor(position, farbe);
      leds.show();
      delay(90);
    }
  }
}

void regenbogen() {
  for (int schritt = 0; schritt < 128; schritt++) {
    for (int position = 0; position < anzahlLeds; position++) {
      byte farbposition = (position * 256 / anzahlLeds + schritt) & 255;
      leds.setPixelColor(position, farbrad(farbposition));
    }
    leds.show();
    delay(30);
  }
}

void setup() {
  leds.begin();
  leds.clear();
  leds.show();
}

void loop() {
  farbverlauf();
  lauflicht();
  regenbogen();
}