/*
Challenge 08: "Poti auslesen und LED analog steuern"
====================================================
Baue eine Schaltung mit einem Potentiometer und einer LED. Die Helligkeit der LED soll sich stufenlos mit dem Poti regeln lassen.

Was du lernen wirst:
- Einen analogen Eingang (Potentiometer) auslesen mit analogRead()
- Einen PWM-Ausgang (LED) mit analogWrite() steuern
- Werte umrechnen (von 0-1023 auf 0-255)

Aufgaben:
1. Baue die Schaltung: Verbinde das Poti mit 5V, GND und dem analogen Pin A0. Verbinde die LED mit einem PWM-Pin (z.B. Pin 9) und Vorwiderstand.
2. Schreibe einen Sketch, der den Wert des Potis mit analogRead(A0) ausliest.
3. Steuere die Helligkeit der LED mit analogWrite(9, ...) entsprechend dem Potiwert.
   - Tipp: Teile den Potiwert durch 4, um ihn auf den Bereich 0-255 zu bringen.
4. Teste dein Programm und beobachte die LED.

Hinweis:
- Vergiss nicht, pinMode(9, OUTPUT) im setup() zu setzen.
*/
