// Morsecode SOS mit LED (Pin 13)
#include <Arduino.h>
const int LED_PIN = 13;

void setup()
{
    pinMode(LED_PIN, OUTPUT);
}

void blinkKurz()
{
    digitalWrite(LED_PIN, HIGH);
    delay(150); // kurz
    digitalWrite(LED_PIN, LOW);
    delay(150);
}

void blinkLang()
{
    digitalWrite(LED_PIN, HIGH);
    delay(500); // lang
    digitalWrite(LED_PIN, LOW);
    delay(300);
}

void loop()
{
    // S: kurz kurz kurz
    blinkKurz();
    blinkKurz();
    blinkKurz();
    delay(300); // Pause zwischen Buchstaben
    // O: lang lang lang
    blinkLang();
    blinkLang();
    blinkLang();
    delay(300); // Pause zwischen Buchstaben
    // S: kurz kurz kurz
    blinkKurz();
    blinkKurz();
    blinkKurz();
    delay(1500); // Pause zwischen SOS
}
