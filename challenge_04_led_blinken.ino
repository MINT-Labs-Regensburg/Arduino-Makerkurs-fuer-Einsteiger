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
- Den Schaltplan mit der LED an Pin 7 findest du in 'Zusatzmaterial/04_LED_schem.png'
- Den Aufbau mit Steckplatine findest du in 'Zusatzmaterial/04_LED_bb.png'

Aufgaben:
1. Baue die Schaltung wie oben beschrieben auf.
2. Schreibe einen Sketch, der die LED im Sekundentakt blinken lässt.
3. Teste dein Programm und beobachte die LED.

Hinweis:
Du kannst als Grundlage das Programm aus challenge 02 verwenden. Allerdings musst du einen anderen Pin verwenden. Anstatt LED_BUILTIN
*/



// So sieht das Programm aus challenge_02 aus. Ersetze die LED_BUILTIN durch deinen eigenen Pin
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);                      // wait for a second
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
  delay(1000);                      // wait for a second
}


