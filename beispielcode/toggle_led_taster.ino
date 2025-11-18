/*
    Toggle-LED mit Taster (mit Entprellen)

    Erklärung:
    - Die Variable 'letzterTasterStatus' merkt sich, ob der Taster im letzten Durchlauf gedrückt war.
    - Nur wenn der Taster von nicht gedrückt auf gedrückt wechselt, wird die LED umgeschaltet.
    - Die 'delay(50)' sorgt dafür, dass Prellen (mehrfaches Auslösen durch mechanische Kontakte) unterdrückt wird.
*/
// Beispiel: Toggle-LED mit Taster und Entprellen
const int tasterPin = 2;
const int ledPin = 13;

int letzterTasterStatus = LOW; // Merkt sich den letzten Tasterzustand
int ledStatus = LOW;           // Merkt sich den LED-Zustand

void setup()
{
    pinMode(tasterPin, INPUT);
    pinMode(ledPin, OUTPUT);
}

void loop()
{
    int tasterStatus = digitalRead(tasterPin);
    if (tasterStatus == HIGH && letzterTasterStatus == LOW)
    {
        // Taster wurde gerade gedrückt
        ledStatus = !ledStatus; // LED-Zustand umschalten
        digitalWrite(ledPin, ledStatus);
        delay(50); // Entprellen: kurze Pause
    }
    letzterTasterStatus = tasterStatus;
}
