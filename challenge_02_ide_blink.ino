/*
  Challenge: IDE oeffnen und Blink starten
  Ziel: Oeffne die Arduino IDE, waehle das Board "Arduino Uno" und lade das Beispiel "Blink" hoch,
        damit die eingebaute LED blinkt. Dieser Sketch enthaelt die Schritt-fuer-Schritt Anweisungen
        als Kommentare und darunter das funktionale Blink-Beispiel.

  Schritte:
  1. Starte die Arduino IDE auf deinem Computer.
  2. Schliesse dein Arduino UNO per USB an den Computer an.
  3. In der IDE: Tools -> Board -> Arduino AVR Boards -> Arduino Uno auswaehlen.
  4. In der IDE: Tools -> Port -> den COM-Port waehlen, der dem Arduino entspricht.
  5. Menu File -> Examples -> 01.Basics -> Blink oeffnen (oder diesen Sketch verwenden).
  6. Optional: Code pruefen oder LED_PIN anpassen, falls du eine externe LED nutzt.
  7. Klick auf Upload (Pfeil nach rechts). Warte auf "Done uploading".
  8. Beobachte die eingebaute LED (LED_BUILTIN) auf dem Board - sie sollte blinken.

  Tipps bei Problemen:
  - Falls Uploadfehler auftreten: Board und Port pruefen, USB-Kabel tauschen, Rechner/IDE neu starten.
  - Externe LED verwenden: Anode ueber Vorwiderstand an Pin 13 (oder gewuenschtem Pin), Kathode an GND.
*/

void setup() {
  // Initialisiere den eingebauten LED Pin als Ausgang
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // Schalte LED an
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000); // 1 Sekunde an

  // Schalte LED aus
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000); // 1 Sekunde aus
}
