/*
Challenge: "Hello World" mit dem Arduino
========================================
Ziel: Schreibe ein Programm, das jede Sekunde "Hello, World!" an den Computer sendet.

Was du lernen wirst:
- Die serielle Schnittstelle verwenden
- Textausgabe im Seriellen Monitor anzeigen

Aufgaben:
1. Schließe deinen Arduino per USB an den Computer an.
2. Öffne die Arduino IDE und wähle das richtige Board und den richtigen Port aus.
3. Schreibe einen Sketch, der im setup() die serielle Kommunikation startet.
4. Gib im loop() jede Sekunde "Hello, World!" über Serial.println() aus.
5. Öffne den Seriellen Monitor und beobachte die Ausgabe.


Tipp:
- Vergiss nicht Serial.begin(9600); im setup()
- Verwende Serial.println("Hello World!"); für die Ausgabe   
- Nutze delay(1000) im loop(), damit die Ausgabe jede Sekunde erfolgt.
*/