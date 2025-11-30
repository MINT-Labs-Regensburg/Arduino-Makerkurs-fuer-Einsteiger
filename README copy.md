# Arduino Makerkurs für Einsteiger – In 3 Stunden zum eigenen Mikrocontroller-Projekt

<img src="Zusatzmaterial/Arduino Uno mit Potentiometer und LED.png" alt="Arduino Uno mit LED und Potentiometer" width="420" />  
<br>
</br>

## Was dich erwartet
Du bist 10 Jahre alt oder älter, und neugierig auf Microcontroller und hast Lust aufs Experimentieren?  
Dann bist du hier richtig im **Maker Kurs für Einsteiger**

Tauche ein in die spannende Welt der Mikrocontroller! Mit dem Arduino bringst du LEDs zum Leuchten und baust interaktive Schaltungen. In nur drei Stunden lernst du die Basics der Programmierung und Elektronik – und nimmst dein eigenes funktionierendes Gadget mit nach Hause!

---

## 📋 Kursübersicht

**Gesamtdauer:** 3 Stunden   
**Zielgruppe:** Jugendliche ab 10 Jahren ohne Programmiererfahrung  
**Format:** Interaktiver Freizeitkurs - 100% praktisches Lernen  
**Ziel:** Grundlagen Arduino Microcontroller. Grundlagen der Programmierung und der  Elektronik kennenlernen.

---

## 🎯 Lernziele

Am Ende des Kurses kannst du:

- einen Arduino anschließen und die Arduino IDE bedienen
- einfache Programme (Sketches) schreiben und auf den Arduino laden
- LEDs zum Leuchten bringen und blinken lassen
- digitale und analoge Eingaben (z.B. Taster, Potentiometer) auslesen
- die Helligkeit einer LED mit einem Potentiometer steuern
- eigene kleine Schaltungen auf dem Breadboard aufbauen
- selbstständig ein eigenes Mikrocontroller-Projekt umsetzen und erweitern

---



## 📅 Einheit 1: Dein Start in die Maker Welt 

### Inhalte
- Hardware Arduino kennenlernen
- Elektronische Komponenten kennenlernen
  
### Interaktive Aktivitäten

**Challenge: "Lerne dein Makerkit kennen - was ist was?"**
Zu Im Kurs bekommst du ein Arduino Maker Kit. Öffne die Kiste. Was findest du?
- Arduino UNO
- Steckplatine (Breadboard)
- LEDs
- Widerstände
- Jumper-Kabel
- Taster 
- was noch?

---

## 📅 Einheit 2: Was ist ein Microcontroller 
### Inhalte
- Arduino an den PC anschliessen
- 5V, 3V3 und GND Power
- Inputs, Outputs
- Digital, Analog

### Interaktive Aktivitäten

**Challenge: "Identifiziere die Pins deines Arduino"**

- Die Pinbelegung des Arduino, das "Pinout" findest du im Ordner `Zusatzmaterial` als Bilddatei:  
  [Arduino UNO Pinout](Zusatzmaterial/Arduino-UNO-pinout.jpg)  
  [Arduino Nano Pinout](Zusatzmaterial/Arduino-Nano-Pinout.png)  
- Verbinde dein Breadboard mit 5V und GND
- Wähle einen Digitalen Output für später aus
- Und einen Analogen Output
- Und einen Digitalen Input
- Und einen Analogen Input 
---

## 📅 Einheit 3: Die Arduino IDE – deine Programmier-Zentrale

### Inhalte

- Sketch
- Editor
- Serieller Port
- Sketches überprüfen und Hochladen 
- Monitor

### Interaktive Aktivitäten

**Challenge: "Verbinde deinen Arduino mit der IDE"**
- Schließe deinen Arduino per USB an den Computer an.
- Öffne die Arduino IDE und wähle das richtige Board und den richtigen Port aus.
---

**Challenge: "Erstelle dein erstes Programm: 'Hello World'"**

- Gib folgenden Code ein und lade ihn auf den Arduino:

```cpp
void setup() {
  Serial.begin(9600); // Starte die serielle Kommunikation mit 9600 Baud
}

void loop() {
  Serial.println("Hello, World!"); // Sende Text an den Computer
  delay(1000); // Warte 1 Sekunde
}
```


- Öffne in der Arduino IDE das **Serielle Monitor**-Fenster (Lupe oben rechts).  
  Jetzt siehst du jede Sekunde die Nachricht "Hello, World!" vom Arduino.

---


- Code-Erklärung
  - `setup()`: Wird in jedem Arduino Sketch einmal beim Start ausgeführt. Hier initialisierst du z.B. die serielle Kommunikation mit serial.begin().
  - `Serial.begin(9600);`: Startet die serielle Kommunikation zwischen Arduino und Computer mit 9600 Baud. Notwendig, damit der Arduino Text an den Computer senden kann.
  - `loop()`: Läuft immer wieder. Hier steht der Hauptcode, der ständig ausgeführt wird.
  - `Serial.println("Hello, World!");`: Sendet den Text "Hello, World!" an den Computer. Jede Nachricht erscheint in einer neuen Zeile im Seriellen Monitor.
  - `delay(1000);`: Wartet 1000 Millisekunden (1 Sekunde), bevor der nächste Durchlauf der Schleife beginnt.

---

## 📅 Einheit 4: Digital Output und Analog Output

### Inhalte

- LED mit Vorwiderstand
- pinMode
- digitalWrite
- analogWrite
- delay

**Challenge: "Digital Output - Lass eine LED blinken"**

- Wähle im [Pinout](Zusatzmaterial/Arduino-UNO-pinout.jpg) den Digital Output Pin aus, den du verwenden möchtest
- Stecke eine LED ins Breadboard (langes Bein = Plus, kurzes = Minus).
- Verbinde das lange Bein über einen Widerstand (z.B. 220Ω) mit dem Digital Output des Arduino.  
Warum brauchst du den Widerstand?
- Das kurze Bein verbindest du mit GND (Masse) am Arduino.
- Schau dir im Schaltplan an, wie der Strom fliesst: `Arduino Output → Widerstand → LED → Arduino GND`
  - [Schaltplan LED an D7 ](Zusatzmaterial/LED_Schaltplan.png) 
  - [Steckplatine LED an D7 ](Zusatzmaterial/LED_Steckplatine.png)
- Gib folgenden Code ein:
```cpp
void setup() {
  pinMode(7, OUTPUT); // Pin D7 als Ausgang
}

void loop() {
  digitalWrite(7, HIGH); // LED an
  delay(500);            // 0,5 Sekunden warten
  digitalWrite(7, LOW);  // LED aus
  delay(500);            // 0,5 Sekunden warten
}
```


- **Zusatzaufgabe 1: LED schneller oder langsamer blinken lassen:**
  - Wie lässt du die LED schneller oder langsamer blinken?
  - Lass auch mal die auf dem Arduino **eingebaute** LED blinken. Findest du die eingebaute LED im [Arduino UNO Pinout](Zusatzmaterial/Arduino-UNO-pinout.jpg) ?

- **Zusatztaufgabe 2: Morsecode SOS:**
  - Schreibe ein Programm, das die LED das Morsezeichen SOS blinken lässt:
    - S = kurz kurz kurz (drei schnelle Blinks)
    - O = lang lang lang (drei lange Blinks)
    - S = kurz kurz kurz (drei schnelle Blinks)
  - Tipp: Nutze unterschiedliche `delay()`-Werte für kurz (z.B. 150 ms) und lang (z.B. 500 ms) und passende Pausen zwischen den Buchstaben.
---
### Analog Output - Aufgabe: LED dimmen

- **Was ist ein Analoger Output:** Der Arduino kann an bestimmten Pins sogenannte **PWM-Signale** (Pulsweitenmodulation) ausgeben. Damit kannst du z.B. die Helligkeit einer LED stufenlos steuern – auch wenn der Arduino eigentlich nur AN oder AUS kennt.
- PWM-Pins sind mit einer `~` (Tilde) am Arduino beschriftet (z.B. 3, 5, 6, 9, 10, 11 beim UNO).
- Die Analog-Werte gehen bei Arduino UNO von 0 bis 255.
- Beispiele, eine LED hell, halbhell, dunkel zu schalten mit  `analogWrite()`:
```cpp
    analogWrite(11, 255); // LED maximale Helligkeit
    analogWrite(11, 128); // LED halbe Helligkeit
    analogWrite(11, 0); // LED minimale Helligkeit = aus
``` 
- Auch hier darf nicht vergessen werden, den Port vorher als Ausgang zu schalten mit `pinMode(11, OUTPUT)` und einen Vorwiderstand mit 220 Ohm zu verwenden
- **Aufgabe:** Baue die Schaltung auf und lasse die LED sanft heller und dunkler werden! 
  - Siehe [beispielcode/led_fading.ino](beispielcode/led_fading.ino)

---

---

## Eingaben – Digital Input & Analog Input
### Digital Input

Ein **Digitaler Input** ist ein Eingangspin am Arduino, der nur zwei Zustände kennt: **AN** (HIGH, 5V) oder **AUS** (LOW, 0V). Typische digitale Eingaben sind Taster oder Schalter. Wenn du z.B. einen Taster an einen digitalen Pin anschließt, kann der Arduino erkennen, ob der Taster gedrückt ist (HIGH) oder nicht (LOW).

**So liest du einen digitalen Input:**

```cpp

int tasterStatus = digitalRead(2); // Liest den Zustand von Pin 2
if (tasterStatus == HIGH) {
  // Taster ist gedrückt
} else {
  // Taster ist nicht gedrückt
}
```

**Code-Erklärung:**

- `int tasterStatus = digitalRead(2);` &rarr; Liest den Zustand des Tasters an Pin 2 (HIGH = gedrückt, LOW = nicht gedrückt).
- `if (tasterStatus == HIGH)` &rarr; Prüft, ob der Taster gedrückt ist.
- `else` &rarr; Wird ausgeführt, wenn der Taster nicht gedrückt ist.

- Hinweis: Vergiss auch hier nicht, vorher den Pin 2 im `setup()` als INPUT zu definieren:
```cpp
pinMode(2, INPUT);
```
- **Aufgabe 1: Taste lesen** Mache ein Programm, das die LED einschaltet, solange der Taster gerdrückt ist
  - Beachte, dass der Input einen Pullup (oder Pulldown) 10 kΩ Widerstand braucht. 
    - [Schaltplan: Taster und LED am Arduino](Zusatzmaterial/LED_Taster_Schaltplan.png)  
    - [Steckplatine: Taster und LED am Arduino](Zusatzmaterial/LED_Taster_Steckplatine.png) 
  - Der 10 kΩ Pullup Widerstand kann weggelassen werden, wenn man stattdessen den internen Pullup Widerstand des Arduino benutzt. Dazu muss der Input mit `pinMode(PIN_NUMBER, INPUT_PULLUP)` initalisiert werden
```cpp
pinMode(2, INPUT_PULLUP);
```
- **Aufgabe 2: Toggle-LED mit dem Taster (mit Entprellen)**
Mache ein Programm, das die LED bei jedem Tastendruck umschaltet (Toggle). 
  - Nutze eine Variable, um den letzten Tasterzustand zu speichern
  - entprelle den Taster mit einer kleinen Wartezeit.  
  - **Beispielcode:** Der vollständige Beispielcode ist in der Datei [`beispielcode/toggle_led_taster.ino`](beispielcode/toggle_led_taster.ino) zu finden.

### Analog Input
- Ein **analoger** Input ist ein Eingangspin am Arduino, der nicht nur AN oder AUS kennt, sondern viele Werte dazwischen. Die Analog Inputs sind mit A0, A1, A2, A3, A4, A5 bezeichnet. Mit einem Analog Input kannst du z.B. einen Drehregler (Potentiometer) auslesen und bekommst Werte von 0 bis 1023. So kannst du z.B. die Helligkeit einer LED an einem analog output stufenlos steuern.

- So liest du einen analogen Input:
```cpp
int sensorWert = analogRead(A0); // Liest den Wert vom analogen Pin A0 (0 bis 1023)
```
Hinweis: analogRead benötigt **kein** pinMode Setting im setup.  

Typische analoge Inputs sind Potentiometer, Lichtsensoren oder Temperatursensoren.
### Aufgabe: Poti auslesen und LED ansteuern

- Baue einen Poti so auf, dass ein Anschluss an 5V, einer an GND und der mittlere an den analogen Pin A0 geht.
- Lese den Wert des Potis mit `analogRead(A0)` aus und steuere damit die Helligkeit der LED mit `analogWrite(9, ...)`.
  - [Schaltplan: Poti und LED am Arduino](Zusatzmaterial/LED_Poti_Schaltplan.png)  
  - [Steckplatine: Poti und LED am Arduino](Zusatzmaterial/LED_Poti_Steckplatine.png) 
- Tipp: Da `analogRead` Werte von 0 bis 1023 liefert, `analogWrite` aber nur 0 bis 255 erwartet, musst du den Wert umrechnen, z.B. mit `wert / 4`.
  
  - Siehe [`beispielcode/poti_led.ino`](beispielcode/poti_led.ino)

---
---

## Dein eigenes Projekt
Jetzt wird's richtig cool! Wähle eines dieser Projekte und baue es:
- **Ampelsteuerung:** Programmiere eine funktionierende Mini-Ampel
- **Reaktionsspiel:** LED blinkt auf – wer ist am schnellsten am Buzzer?
- **RGB-Farbmischer:** Mixe mit drei Drehreglern deine Lieblingsfarben

---
---

## Die Software

- **Arduino IDE** – komplett kostenlos und open source!
- Download: [https://www.arduino.cc/en/software](https://www.arduino.cc/en/software)
---


---

## 📞 Kontakt

Bei Fragen zum Kurs oder Material:  
**MINT-Labs Regensburg**  
🌐 [https://www.mint-labs-regensburg.de/](https://www.mint-labs-regensburg.de/)

## 5461AS-1 4 Digit display

---

## Weiterführende Links

- [4 Digit Segment 5461AS-1](https://www.electronicssimplified.in/feed/2062/)
- Schaltplan zum 4x7-Segment-Display findest du hier:  
  [4x7segment_display_schem.png](Zusatzmaterial/4x7segment_display_schem.png)
- Steckplatinen-Ansicht:  
  [4x7segment_display_bb.png](Zusatzmaterial/4x7segment_display_bb.png)

---