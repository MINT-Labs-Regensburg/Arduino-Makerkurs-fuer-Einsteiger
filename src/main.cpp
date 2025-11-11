/*
 * Arduino Blink - Dein erstes Programm!
 *
 * Dieses Programm lässt die eingebaute LED auf dem Arduino Uno blinken.
 * Pin 13 ist mit der LED verbunden.
 */

#include <Arduino.h>

void setup()
{
    // Serielle Kommunikation starten (115200 Baud)
    Serial.begin(115200);

    // Kurz warten bis Serial bereit ist
    delay(100);

    // Nachricht senden
    Serial.println();
    Serial.println("STARTED");

    // Pin 13 als Ausgang festlegen
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{

    for (int i = 0; i < 256; i++){
        analogWrite(LED_BUILTIN, i);
        delay(100);
    }

        // LED einschalten
        // digitalWrite(LED_BUILTIN, HIGH);

    // 1 Sekunde warten (1000 Millisekunden)
    delay(100);

    // LED ausschalten
    // digitalWrite(LED_BUILTIN, LOW);

    // 1 Sekunde warten
}
