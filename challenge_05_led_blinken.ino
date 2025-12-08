/*
Challenge 05: "Digital Output - Lass eine LED blinken"
===================================================
Wähle im Pinout den Digital Output Pin aus, den du verwenden möchtest.

Aufbau:
- Stecke eine LED ins Breadboard (langes Bein = Plus, kurzes = Minus).
- Verbinde das lange Bein über einen Widerstand (z.B. 220Ω) mit dem Digital Output des Arduino.
- Warum brauchst du den Widerstand? (Schutz der LED vor zu viel Strom)
- Das kurze Bein verbindest du mit GND (Masse) am Arduino.
- Den Schaltplan mit der LED an Pin 7 findest du in 'Zusatzmaterial/LED_Schaltplan.png'
- Den Aufbau mit Steckplatine findest du in 'Zusatzmaterial/LED_Steckplatine.png'

Was du lernen wirst:
- Einen digitalen Ausgang am Arduino nutzen
- Eine LED mit digitalWrite() ansteuern
- Die Bedeutung des Vorwiderstands verstehen

Aufgaben:
1. Baue die Schaltung wie oben beschrieben auf.
2. Schreibe einen Sketch, der die LED im Sekundentakt blinken lässt.
3. Teste dein Programm und beobachte die LED.

Hinweis:
- Nutze pinMode(PIN, OUTPUT) im setup().
- Nutze digitalWrite(PIN, HIGH) und digitalWrite(PIN, LOW) im loop().
- Mit delay(500) kannst du die Blinkgeschwindigkeit steuern.


Zusatzaufgabe:
Lass auch mal die auf dem Arduino **eingebaute** LED blinken. 
Findest du die eingebaute LED im Pinout unter 'Zusatzmaterial/Arduino-UNO-pinout.jpg'
*/