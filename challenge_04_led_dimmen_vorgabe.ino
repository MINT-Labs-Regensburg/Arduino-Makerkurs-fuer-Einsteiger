/*
Challenge 04: "LED Dimmen"
==========================
Baue eine Schaltung, bei der die LED sanft heller und dunkler wird (Fading).

Was du lernen wirst:
- PWM-Ausgänge am Arduino nutzen
- Die Helligkeit einer LED stufenlos steuern mit analogWrite()
- Eine for-Schleife verwenden


Aufgaben:
1. Wähle einen Ausgang, der Analog Output (PWM) kann (z.B. Pin 11, erkennbar an der ~).
2. Baue die LED-Schaltung mit Vorwiderstand an diesen PWM-Pin.
3. Schreibe einen Sketch, der die LED langsam heller und dunkler werden lässt.
   - Nutze analogWrite(PIN, Wert) für die Helligkeit (Wert von 0 bis 255).
   - Verwende eine for-Schleife, um den Wert schrittweise zu erhöhen und zu verringern.
4. Teste dein Programm und beobachte die LED.

Hinweis:
- Vergiss nicht pinMode(PIN, OUTPUT) im setup().
- Nutze delay(10) oder delay(20) für sanfte Übergänge.
*/
