/*
Challenge 03: "Lass die LED im Morsecode SOS blinken"
=====================================================
Schreibe ein Programm, das die LED das Morsezeichen SOS blinken lässt:

Morsecode:
- S = kurz kurz kurz (drei schnelle Blinks)
- O = lang lang lang (drei lange Blinks)
- S = kurz kurz kurz (drei schnelle Blinks)

Was du lernen wirst:
- Eine LED gezielt ansteuern
- Verschiedene Blinkmuster mit delay() erzeugen
- Morsecode mit dem Arduino ausgeben

Aufgaben:
1. Baue die LED-Schaltung wie bei Challenge 02 auf.
2. Schreibe einen Sketch, der die LED im Morsecode SOS blinken lässt.
   - Nutze unterschiedliche delay()-Werte für kurz (z.B. 150 ms) und lang (z.B. 500 ms).
   - Baue passende Pausen zwischen den Buchstaben ein.
3. Teste dein Programm und beobachte die LED.

Hinweis:
- Nutze digitalWrite(PIN, HIGH) und digitalWrite(PIN, LOW) für die LED.
- Die LED soll das Muster fortlaufend wiederholen.
*/
