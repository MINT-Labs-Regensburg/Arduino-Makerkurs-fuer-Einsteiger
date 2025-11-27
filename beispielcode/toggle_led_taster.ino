#include <Arduino.h>

/*
 * Toggle-LED mit Taster (mit Entprellen)
 *
 * Funktionsweise:
 * - Die Variable 'letzterTasterStatus' merkt sich, ob der Taster im letzten Durchlauf gedrückt war.
 * - Nur wenn der Taster von "nicht gedrückt" auf "gedrückt" wechselt, wird die LED umgeschaltet (Toggle).
 * - Die 'delay(50)' sorgt dafür, dass Prellen (mehrfaches Auslösen durch mechanische Kontakte) unterdrückt wird.
 *
 * Schaltung:
 * - Taster an GPIO33. 
 * - LED an GPIO12
 */

// Beispiel: Toggle-LED mit Taster und Entprellen
const int tasterPin = 33; // Taster an GPIO33
const int ledPin = 12;    // LED an GPIO12

int letzterTasterStatus = LOW; // Speichert den letzten Tasterzustand
int ledStatus = LOW;           // Speichert den aktuellen LED-Zustand

void setup()
{
    pinMode(tasterPin, INPUT_PULLUP); // Taster mit internem Pullup-Widerstand
    pinMode(ledPin, OUTPUT);          // LED als Ausgang
}

void loop()
{
    int tasterStatus = digitalRead(tasterPin);

    // Prüfe, ob der Taster gerade gedrückt wurde (Flanke von LOW auf HIGH)
    if (tasterStatus == HIGH && letzterTasterStatus == LOW)
    {
        // Taster wurde gerade gedrückt → LED-Zustand umschalten
        ledStatus = !ledStatus;
        digitalWrite(ledPin, ledStatus);
        delay(50); // Entprellen: kurze Pause, verhindert mehrfaches Auslösen
    }

    // Speichere aktuellen Tasterstatus für den nächsten Durchlauf
    letzterTasterStatus = tasterStatus;
}