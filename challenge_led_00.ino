const int ledPin = 6;
const int anzahlLeds = 10;

Adafruit_NeoPixel leds(anzahlLeds, ledPin, NEO_GRB + NEO_KHZ800);

void setup() {
  leds.begin();
}

void loop() {
  leds.setPixelColor(0, leds.Color(255, 0, 0));  // Rot
  leds.show();
  delay(500);
  leds.setPixelColor(0, leds.Color(0, 0, 0));  // Rot
  leds.show();
  delay(500);
}
