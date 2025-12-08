/*
Challenge 07: "Taster lesen und LED schalten"
=============================================
Baue eine Schaltung mit einem Taster und einer LED. Die LED soll leuchten, solange der Taster gedrückt ist.

Was du lernen wirst:
- Einen digitalen Eingang (Taster) auslesen
- Mit digitalRead() und digitalWrite() arbeiten
- Eine LED abhängig vom Tasterzustand schalten

Aufgaben:
1. Baue die Schaltung: Verbinde einen Taster mit einem digitalen Input-Pin (z.B. Pin 2) und eine LED mit einem digitalen Output-Pin (z.B. Pin 7).
2. Schreibe einen Sketch, der den Zustand des Tasters ausliest.
3. Schalte die LED ein, wenn der Taster gedrückt ist, und aus, wenn er nicht gedrückt ist.
4. Teste dein Programm und beobachte die LED.


Hinweis:
- Vergiss nicht, pinMode(PIN, INPUT) für den Taster und pinMode(PIN, OUTPUT) für die LED im setup() zu setzen.
- Nutze digitalRead() für den Taster und digitalWrite() für die LED.
- Ein Pullup- oder Pulldown-Widerstand ist nötig, oder verwende INPUT_PULLUP.
*/
