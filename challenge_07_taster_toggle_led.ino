/*
Challenge 07: "LED mit Taster toggeln"
========================================
Schalte die LED mit dem Taster ein und aus – jedes Mal, wenn du den Taster drückst, wechselt die LED ihren Zustand (Toggle-Funktion).

Was du lernen wirst:
- Einen digitalen Eingang (Taster) auslesen
- Den Zustand einer LED speichern und ändern
- Mit Flankenerkennung arbeiten (nur bei Tastendruck toggeln, nicht dauerhaft)

Aufgaben:
1. Baue eine Schaltung mit Taster und LED (z.B. LED an Pin 11, Taster an Pin 2).
2. Schreibe einen Sketch, der die LED bei jedem Tastendruck toggelt.
3. Nutze eine Variable, um den Zustand der LED zu speichern.
4. Denke an die Entprellung (kurzes delay nach dem Umschalten).

Hinweis:
- Flankenerkennung: Vergleiche aktuellen und vorherigen Tasterzustand.
- Nutze digitalWrite(ledPin, ...) und digitalRead(tasterPin).
- Entprellung: delay(50) nach dem Umschalten.
*/
