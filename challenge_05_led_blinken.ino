/*
Challenge 05: "Digital Output - Lass eine LED blinken"
===================================================
Wähle im Pinout den Digital Output Pin aus, den du verwenden möchtest. 
Suche auch einen GND Pin aus.
Siehe: zusatzmaterial/00_Arduino_UNO-Pinout.jpg

Aufbau:
- Stecke eine LED ins Breadboard (langes Bein = Plus, kurzes = Minus).
- Verbinde das lange Bein über einen Widerstand (z.B. 220Ω) mit dem Digital Output des Arduino.
- Warum brauchst du den Widerstand? (Schutz der LED vor zu viel Strom)
- Das kurze Bein verbindest du mit GND (Masse) am Arduino.
- Den Schaltplan mit der LED an Pin 7 findest du in 'Zusatzmaterial/05_LED_schem.png'
- Den Aufbau mit Steckplatine findest du in 'Zusatzmaterial/05_LED_bb.png'

Aufgaben:
1. Baue die Schaltung wie oben beschrieben auf.
2. Schreibe einen Sketch, der die LED im Sekundentakt blinken lässt.
3. Teste dein Programm und beobachte die LED.

Hinweis:
- Nutze pinMode(PIN, OUTPUT) im setup().
- Nutze digitalWrite(PIN, HIGH) und digitalWrite(PIN, LOW) im loop().
- Mit delay(500) kannst du die Blinkgeschwindigkeit steuern.


Zusatzaufgabe:
Lass auch mal die auf dem Arduino fest eingebaute LED blinken. 
Findest du die eingebaute LED im Pinout unter 'zusatzmaterial/00_Arduino_UNO-Pinout.jpg'
*/

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
