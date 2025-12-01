/*
Challenge: "Digital Output - Lass eine LED blinken" - MUSTERLÖSUNG
==================================================================
*/

const int ledPin = 7; // Beispiel: Pin 7 als Digital Output. 
                      // Pin 13 ist die eingebaute LED

void setup() {
    pinMode(ledPin, OUTPUT);
}

void loop() {
    digitalWrite(ledPin, HIGH); // LED an
    delay(500);                 // 0,5 Sekunden warten
    digitalWrite(ledPin, LOW);  // LED aus
    delay(500);                 // 0,5 Sekunden warten
}
