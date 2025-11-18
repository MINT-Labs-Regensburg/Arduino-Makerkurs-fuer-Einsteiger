# Mikrocontroller zum Anfassen – Deine ersten 3 Stunden als Maker
- [Mikrocontroller zum Anfassen – Deine ersten 3 Stunden als Maker](#mikrocontroller-zum-anfassen--deine-ersten-3-stunden-als-maker)
  - [💡 Was dich erwartet](#-was-dich-erwartet)
  - [📦 Dein Maker Kit kennenlernen](#-dein-maker-kit-kennenlernen)
    - [Aufgabe: Wie fliesst der Strom? Bringe eine LED zum Leuchten](#aufgabe-wie-fliesst-der-strom-bringe-eine-led-zum-leuchten)
  - [🚦 Dein Start in die Arduino-Welt](#-dein-start-in-die-arduino-welt)
    - [- Was ist ein Arduino überhaupt?](#--was-ist-ein-arduino-überhaupt)
    - [- Tour durch den Arduino Nano/UNO](#--tour-durch-den-arduino-nanouno)
    - [- Die Arduino IDE – deine Programmier-Zentrale](#--die-arduino-ide--deine-programmier-zentrale)
  - [💡 Dein erstes Arduino Programm: Lass die LED blinken](#-dein-erstes-arduino-programm-lass-die-led-blinken)
    - [Digital Output](#digital-output)
    - [Analog Output: LED dimmen](#analog-output-led-dimmen)
  - [🛠️ Eingaben - Digital und analog input](#️-eingaben---digital-und-analog-input)
    - [Digital Input](#digital-input)
    - [Analog input](#analog-input)
      - [Aufgabe: Poti auslesen und LED ansteuern](#aufgabe-poti-auslesen-und-led-ansteuern)
    - [🎨 Dein eigenes Projekt](#-dein-eigenes-projekt)
  - [💻 Die Software](#-die-software)
  - [📞 Kontakt](#-kontakt)

## 💡 Was dich erwartet
Du bist 10 Jahre alt oder älter, und neugierig auf Microcontroller und hast Lust aufs Experimentieren?  
Dann bist du hier richtig im **Maker Kurs für Einsteiger**

Tauche ein in die spannende Welt der Mikrocontroller! Mit dem Arduino bringst du LEDs zum Leuchten und baust interaktive Schaltungen. In nur drei Stunden lernst du die Basics der Programmierung und Elektronik – und nimmst dein eigenes funktionierendes Gadget mit nach Hause!


## 📦 Dein Maker Kit kennenlernen

Zu Beginn des Kurses erhältst du ein Maker Kit. Öffne die Kiste. Was findest du?
- Arduino (UNO oder Nano)
- Steckplatine (Breadboard)
- LEDs
- Widerstände
- Jumper-Kabel
- Taster 
- was noch?

### Aufgabe: Wie fliesst der Strom? Bringe eine LED zum Leuchten
1. Stecke eine LED ins Breadboard (langes Bein = Plus, kurzes = Minus).
2. Verbinde das lange Bein über einen Widerstand (z.B. 220Ω) mit dem 5V-Pin des Arduino.  
Warum brauchst du den Widerstand?
3. Das kurze Bein verbindest du mit GND (Masse) am Arduino.
4. Schließe den Arduino am Computer an. Die LED sollte jetzt leuchten

Die Pinbelegung des Arduino findest du im Ordner `medien` als Bilddatei:  
- [Arduino UNO Pinout](medien/Arduino-UNO-pinout.jpg)  
- [Arduino Nano Pinout](medien/Arduino-Nano-pinout.png)  

So gehts:
- [Schaltplan LED an 5 Volt](medien/LED_5Volt_Schaltplan.png) – So sieht der Stromkreis aus
- [Steckplatine LED an 5 Volt](medien/LED_5Volt_Steckplatine.png) – Beispiel für den Aufbau auf dem Breadboard

---

## 🚦 Dein Start in die Arduino-Welt
### - Was ist ein Arduino überhaupt?
### - Tour durch den Arduino Nano/UNO
- Inputs, Outputs, Digital, Analog
- Pinout Arduino 
### - Die Arduino IDE – deine Programmier-Zentrale
- Starte die Arduino IDE  
- Der Editor. Hier gibts du deine Befehle für den Arduino ein
- Laden das Programms auf deinen Arduino


---

## 💡 Dein erstes Arduino Programm: Lass die LED blinken
### Digital Output

- Schliesse die LED an einen digitalen Ausgang des Arduino an.  
  Suche dazu einen digitalen Output in [Arduino UNO Pinout](medien/Arduino-UNO-pinout.jpg).  
- So gehts:
  - [Schaltplan LED an D7 ](medien/LED_Schaltplan.png) 
  - [Steckplatine LED an D7 ](medien/LED_Steckplatine.png)
- Starte die Arduino IDE
- Gib folgenden Code ein:
```cpp
void setup() {
  pinMode(13, OUTPUT); // Pin 13 als Ausgang
}

void loop() {
  digitalWrite(13, HIGH); // LED an
  delay(500);             // 0,5 Sekunden warten
  digitalWrite(13, LOW);  // LED aus
  delay(500);             // 0,5 Sekunden warten
}
```
---

- Code-Erklärung
  - `setup()`: Wird in jedem Arduino scetch einmal beim Start ausgeführt. Hier wird der Pin als Ausgang gesetzt.
  - `pinMode()`: Legt fest, ob ein Pin als Eingang (`INPUT`) oder Ausgang (`OUTPUT`) verwendet wird. Hier wird Pin 13 als Ausgang für die LED definiert.
  - `loop()`: Läuft immer wieder. Schaltet die LED an/aus und wartet jeweils 0,5 Sekunden.
  - `digitalWrite()`: Schaltet den Pin auf HIGH (an) oder LOW (aus).
  - `delay()`: Wartet die angegebene Zeit in Millisekunden. Das sind tausendstel Sekunden (Der Arduino ist schnell!). delay(1000) wartet also eine Sekunde.

---

- **Zusatzaufgabe 1: LED schneller oder langsamer blinken lassen:**
  - Wie lässt du die LED schneller oder langsamer blinken?
  - Lass auch mal die auf dem Arduino **eingebaute** LED blinken. Findest du die eingebaute LED im [Arduino UNO Pinout](medien/Arduino-UNO-pinout.jpg) ?

- **Zusatztaufgabe 2: Morsecode SOS:**
  - Schreibe ein Programm, das die LED das Morsezeichen SOS blinken lässt:
    - S = kurz kurz kurz (drei schnelle Blinks)
    - O = lang lang lang (drei lange Blinks)
    - S = kurz kurz kurz (drei schnelle Blinks)
  - Tipp: Nutze unterschiedliche `delay()`-Werte für kurz (z.B. 150 ms) und lang (z.B. 500 ms) und passende Pausen zwischen den Buchstaben.
---
### Analog Output: LED dimmen

- Der Arduino kann an bestimmten Pins sogenannte **PWM-Signale** (Pulsweitenmodulation) ausgeben. Damit kannst du z.B. die Helligkeit einer LED stufenlos steuern – auch wenn der Arduino eigentlich nur AN oder AUS kennt.
- Typische PWM-Pins sind mit einer `~` (Tilde) am Arduino beschriftet (z.B. 3, 5, 6, 9, 10, 11 beim UNO).


- `analogWrite(Pin, Wert)`: Wert von 0 (aus) bis 255 (volle Helligkeit) 
- Beispiele, eine LED hell, halbhell, dunkel zu schalten mit  `analogWrite()`:
```cpp
    analogWrite(9, 255); // LED maximale Helligkeit
    analogWrite(9, 128); // LED halbe Helligkeit
    analogWrite(9, 0); // LED minimale Helligkeit = aus
``` 
- Auch hier darf nicht vergessen werden, den Port vorher als Ausgang zu schalten mit `pinMode(9, OUTPUT)`
- **Aufgabe:** Baue die Schaltung auf und lasse die LED sanft heller und dunkler werden!
  
  **Beispielcode:** Siehe [`beispielcode/led_fading_poti.ino`](beispielcode/led_fading.ino)

---

## 🛠️ Eingaben - Digital und analog input
### Digital Input

- Was ist ein **digitaler Input**?  
  Ein digitaler Input ist ein Eingangspin am Arduino, der nur zwei Zustände kennt: **AN** (HIGH, 5V) oder **AUS** (LOW, 0V). Typische digitale Eingaben sind Taster oder Schalter. Wenn du z.B. einen Taster an einen digitalen Pin anschließt, kann der Arduino erkennen, ob der Taster gedrückt ist (HIGH) oder nicht (LOW).

- So liest du einen digitalen Input:
```cpp
int tasterStatus = digitalRead(2); // Liest den Zustand von Pin 2
if (tasterStatus == HIGH) {
  // Taster ist gedrückt
} else {
  // Taster ist nicht gedrückt
}
```
- Wichtig: Vergiss nicht, vorher den Pin im `setup()` als Eingang zu definieren:
```cpp
pinMode(2, INPUT);
pinMode(2, INPUT_PULLUP);
```
- **Aufgabe 1: Taste lesen** Mache ein Programm, das die LED einschaltet, solange der Taster gerdrückt ist
  - Beachte, dass der Input einen Pullup (oder Pulldown) 10 kΩ Widerstand braucht. 
  - [Schaltplan: Taster und LED am Arduino](medien/LED_Taster_Schaltplan.png)  
    [Steckplatine: Taster und LED am Arduino](medien/LED_Taster_Steckplatine.png) 
  - Der Widerstand kann weggelassen werden, wenn man stattdessen den internen Pullup Widerstand des Arduino benutzt. Dazu muss der Input mit `pinMode(PIN_NUMBER, INPUT_PULLUP)` initalisiert werden
- **Aufgabe 2: Toggle-LED mit dem Taster (mit Entprellen)**
Mache ein Programm, das die LED bei jedem Tastendruck umschaltet (Toggle). 
  - Nutze eine Variable, um den letzten Tasterzustand zu speichern
  - entprelle den Taster mit einer kleinen Wartezeit.  
  - **Beispielcode:** Der vollständige Beispielcode ist in der Datei [`beispielcode/toggle_led_taster.ino`](beispielcode/toggle_led_taster.ino) zu finden.

### Analog input
- Ein **analoger** Input ist ein Eingangspin am Arduino, der nicht nur AN oder AUS kennt, sondern viele Werte dazwischen. Damit kannst du z.B. einen Drehregler (Potentiometer) auslesen und bekommst Werte von 0 bis 1023. So kannst du z.B. die Helligkeit einer LED an einem analog output stufenlos steuern.

- So liest du einen analogen Input:
```cpp
int sensorWert = analogRead(A0); // Liest den Wert vom analogen Pin A0 (0 bis 1023)
```
Hinweis: analogRead benötigt **kein** pinMode Setting im setup.  

Typische analoge Inputs sind Potentiometer, Lichtsensoren oder Temperatursensoren.
#### Aufgabe: Poti auslesen und LED ansteuern

- Baue einen Poti so auf, dass ein Anschluss an 5V, einer an GND und der mittlere an den analogen Pin A0 geht.
- Lese den Wert des Potis mit `analogRead(A0)` aus und steuere damit die Helligkeit der LED mit `analogWrite(9, ...)`.
- Tipp: Da `analogRead` Werte von 0 bis 1023 liefert, `analogWrite` aber nur 0 bis 255 erwartet, musst du den Wert umrechnen, z.B. mit `wert / 4`.
 - [Schaltplan: Poti und LED am Arduino](medien/LED_Poti_Schaltplan.png)  
    [Steckplatine: Poti und LED am Arduino](medien/LED_Poti_Steckplatine.png) 

**Beispielcode:** Siehe [`beispielcode/poti_led.ino`](beispielcode/poti_led.ino)
- **Drehregler** auslesen und LED-Helligkeit steuern
- **PWM-Magie** Stufenloses Dimmen

---
### 🎨 Dein eigenes Projekt
Jetzt wird's richtig cool! Wähle eines dieser Projekte und baue es:
- **Ampelsteuerung:** Programmiere eine funktionierende Mini-Ampel
- **Reaktionsspiel:** LED blinkt auf – wer ist am schnellsten am Buzzer?
- **RGB-Farbmischer:** Mixe mit drei Drehreglern deine Lieblingsfarben

---
## 💻 Die Software

- **Arduino IDE** – komplett kostenlos und open source!
- Download: [https://www.arduino.cc/en/software](https://www.arduino.cc/en/software)
---


## 📞 Kontakt

Bei Fragen zum Kurs oder Material:  
**MINT-Labs Regensburg**  
🌐 [https://www.mint-labs-regensburg.de/](https://www.mint-labs-regensburg.de/)

---

**Viel Erfolg und Spaß beim Arduino-Kurs!** 🔧⚡
