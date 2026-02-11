/*
  Lösung: Challenge 05 - "Hello World auf dem Seriellen Monitor ausgeben"

  Beschreibung:
  - Öffne die Arduino IDE und wähle das richtige Board und den COM-Port.
  - Lade diesen Sketch hoch und öffne den Seriellen Monitor (9600 Baud).
  - Der Sketch schreibt "Hello World" in den Seriellen Monitor und blinkt die
    eingebaute LED im Sekundentakt.
*/

void setup() {
  Serial.begin(9600);
  while (!Serial) { /* warten, falls das Board Serial erst initialisieren muss */ }
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.println("Hello World");
}

void loop() {
  // LED an und Nachricht
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.println("LED ON");
  delay(500);

  // LED aus und Nachricht
  digitalWrite(LED_BUILTIN, LOW);
  Serial.println("LED OFF");
  delay(500);
}
