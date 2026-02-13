/*
  Challenge 04+ - Verkehrsampel

  Aufgabenbeschreibung:
  - Ziel: Baue eine Mini-Verkehrsampel mit drei LEDs (Rot, Gelb, Grün) und
    programmiere den Ablauf: Grün -> Gelb -> Rot -> Grün.
  - Lernziele: Digitale Ausgänge ansteuern, einfache Zeitsteuerung,
    Schaltungsaufbau mit Vorwiderständen.

  Benötigte Bauteile:
  - Arduino UNO
  - 3 LEDs (rot, gelb, grün)
  - 3 x 220Ω Widerstände
  - Steckbrett (Breadboard) und Jumperkabel

  Schaltung (Vorschlag):
  - Rot  -> Digitalpin 8 über 220Ω -> Anode LED, Kathode -> GND
  - Gelb -> Digitalpin 9 über 220Ω -> Anode LED, Kathode -> GND
  - Grün -> Digitalpin 10 über 220Ω -> Anode LED, Kathode -> GND

  Kurzer Starter-Sketch (blockierend, einfach):
*/

const int RED_PIN = 8;
const int YELLOW_PIN = 9;
const int GREEN_PIN = 10;

const unsigned long GREEN_TIME = 5000;   // 5s
const unsigned long YELLOW_TIME = 2000;  // 2s
const unsigned long RED_TIME = 5000;     // 5s

void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);

  digitalWrite(RED_PIN, LOW);
  digitalWrite(YELLOW_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
}

void loop() {
  // Grün
  digitalWrite(GREEN_PIN, HIGH);
  digitalWrite(YELLOW_PIN, LOW);
  digitalWrite(RED_PIN, LOW);
  delay(GREEN_TIME);

  // Gelb
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(YELLOW_PIN, HIGH);
  digitalWrite(RED_PIN, LOW);
  delay(YELLOW_TIME);

  // Rot
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(YELLOW_PIN, LOW);
  digitalWrite(RED_PIN, HIGH);
  delay(RED_TIME);
}
