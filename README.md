**Mikrocontroller zum Anfassen – Deine ersten 3 Stunden als Maker!**
- [💡 Was dich erwartet](#-was-dich-erwartet)
- [👥 Für wen ist dieser Kurs?](#-für-wen-ist-dieser-kurs)
- [🎯 Was du am Ende kannst](#-was-du-am-ende-kannst)
- [🚀 Der Fahrplan](#-der-fahrplan)
  - [1️⃣ Dein Maker Kit kennenlernen](#1️⃣-dein-maker-kit-kennenlernen)
    - [Aufgabe: Bringe eine LED zum Leuchten\*\*](#aufgabe-bringe-eine-led-zum-leuchten)
  - [2️⃣ Dein Start in die Arduino-Welt (ca. 45 Min.)](#2️⃣-dein-start-in-die-arduino-welt-ca-45-min)
    - [📝 Dein erstes Arduino Programm. Lass die LED blinken](#-dein-erstes-arduino-programm-lass-die-led-blinken)
    - [🔍 Code-Erklärung](#-code-erklärung)
    - [🧩 Zusatzaufgaben](#-zusatzaufgaben)
  - [3️⃣ Eingaben \& Ausgaben meistern (ca. 60 Min.)](#3️⃣-eingaben--ausgaben-meistern-ca-60-min)
  - [4️⃣ Dein eigenes Projekt (ca. 60 Min.)](#4️⃣-dein-eigenes-projekt-ca-60-min)
  - [5️⃣ Abschluss (ca. 15 Min.)](#5️⃣-abschluss-ca-15-min)
  - [💻 Die Software](#-die-software)
  - [📚 Kursmaterialien](#-kursmaterialien)
- [🚀 Wie geht's weiter?](#-wie-gehts-weiter)
- [Kontakt](#kontakt)

## 💡 Was dich erwartet

Tauche ein in die spannende Welt der Mikrocontroller! Mit dem Arduino Nano bringst du LEDs zum Leuchten und baust interaktive Schaltungen. In nur drei Stunden lernst du die Basics der Programmierung und Elektronik – und nimmst dein eigenes funktionierendes Gadget mit nach Hause!



## 👥 Für wen ist dieser Kurs?

- **Alter:** Ab 10 Jahren
- **Vorkenntnisse:** Null, nada, nichts – du startest bei Null!
- **Mitbringen:** Nur deine Neugierde und Lust aufs Experimentieren


## 🎯 Was du am Ende kannst

Nach diesem Kurs kannst du:
- ✅ Die Arduino IDE bedienen und deinen Code auf das Board laden
- ✅ Elektronische Schaltungen auf dem Breadboard bauen
- ✅ LEDs zum Blinken, Leuchten und Dimmen bringen
- ✅ Taster einsetzen


## 🚀 Der Fahrplan


### 1️⃣ Dein Maker Kit kennenlernen

Zu Beginn des Kurses erhältst du ein Maker Kit. Öffne die Kiste. Was findest du?
- Arduino (Nano oder Uno)
- Steckbrett (Breadboard)
- LEDs
- Widerstände
- Jumper-Kabel
- Taster 
- was noch?

#### Aufgabe: Bringe eine LED zum Leuchten**
1. Stecke eine LED ins Breadboard (langes Bein = Plus, kurzes = Minus).
2. Verbinde das lange Bein über einen Widerstand (z.B. 220Ω) mit dem 5V-Pin des Arduino.  
Warum brauchst du den Widerstand?
3. Das kurze Bein verbindest du mit GND (Masse) am Arduino.
4. Schließe den Arduino am Computer an. Die LED sollte jetzt leuchten

Die Pinbelegung des Arduino findest du im Ordner `medien` als Bilddatei:  
- [Arduino Nano Pinout](medien/Arduino-Nano-pinout.png)  
- [Arduino Uno Pinout](medien/Arduino-UNO-pinout.jpg)  

So gehts:
- [5V-Schaltplan (PDF)](medien/LED_5Volt_Schaltplan.png) – So sieht der Stromkreis aus
- [5V-Steckplatine (Bild)](medien/LED_5Volt_Steckplatine.png) – Beispiel für den Aufbau auf dem Breadboard



### 2️⃣ Dein Start in die Arduino-Welt (ca. 45 Min.)
- Was ist ein Arduino überhaupt?
- Tour durch den Arduino Nano/UNO
- Die Arduino IDE – deine Programmier-Zentrale

#### 📝 Dein erstes Arduino Programm. Lass die LED blinken

1. **Starte die Arduino IDE**  
2. **Gib folgenden Code ein**
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

3. **Lade das Programm auf deinen Arduino hoch.**
4. **Beobachte:** Die LED sollte nun blinken!

#### 🔍 Code-Erklärung
- `setup()`: Wird einmal beim Start ausgeführt. Hier wird der Pin als Ausgang gesetzt.
- `pinMode()`: Legt fest, ob ein Pin als Eingang (`INPUT`) oder Ausgang (`OUTPUT`) verwendet wird. Hier wird Pin 13 als Ausgang für die LED definiert.
- `loop()`: Läuft immer wieder. Schaltet die LED an/aus und wartet jeweils 0,5 Sekunden.
- `digitalWrite()`: Schaltet den Pin auf HIGH (an) oder LOW (aus).
- `delay()`: Wartet die angegebene Zeit in Millisekunden.

#### 🧩 Zusatzaufgaben

1. **LED schneller oder langsamer blinken lassen:**

  - Wie lässt du die LED schneller oder langsamer blinken?
  - Lass die auf dem Arduino eingebaute LED blinken. Findest du die eingebaute LED im Pinout?

2. **Morsecode SOS:**
  - Schreibe ein Programm, das die LED das Morsezeichen SOS blinken lässt:
    - S = kurz kurz kurz (drei schnelle Blinks)
    - O = lang lang lang (drei lange Blinks)
    - S = kurz kurz kurz (drei schnelle Blinks)
  - Tipp: Nutze unterschiedliche `delay()`-Werte für kurz (z.B. 150 ms) und lang (z.B. 500 ms) und passende Pausen zwischen den Buchstaben.


### 3️⃣ Eingaben & Ausgaben meistern (ca. 60 Min.)
- LEDs richtig verkabeln (ohne dass was durchbrennt 😉)
- Buttons einbauen – deine erste Interaktion!
- Drehregler auslesen und LED-Helligkeit steuern
- PWM-Magie: Stufenloses Dimmen

### 4️⃣ Dein eigenes Projekt (ca. 60 Min.)
Jetzt wird's richtig cool! Wähle eines dieser Projekte und baue es:
- **🚦 Ampelsteuerung:** Programmiere eine funktionierende Mini-Ampel
- **⚡ Reaktionsspiel:** LED blinkt auf – wer ist am schnellsten am Buzzer?
- **🌈 RGB-Farbmischer:** Mixe mit drei Drehreglern deine Lieblingsfarben

### 5️⃣ Abschluss (ca. 15 Min.)
- Zeig, was du gebaut hast!
- Fragen & Antworten
- Wie geht's weiter? (Spoiler: Es gibt SO viel zu entdecken!)


### 💻 Die Software

- **Arduino IDE** – komplett kostenlos und open source!
- Download: [https://www.arduino.cc/en/software](https://www.arduino.cc/en/software)

### 📚 Kursmaterialien

In diesem Repository findest du:

- **[Arduino Cheatsheet (PDF)](medien/4rtech_arduino-cheatsheet-deutsch.pdf)** – Schnellübersicht aller wichtigen Befehle
- **[Arduino Nano Pinout](medien/Arduino-Nano-Pinout.png)** – Übersicht aller Pins am Arduino Nano
- **[Arduino UNO Pinout](medien/Arduino-UNO-pinout.jpg)** – Übersicht aller Pins am Arduino UNO

## 🚀 Wie geht's weiter?

Das ist erst der Anfang! Nach diesem Kurs kannst du weitermachen mit:
- 🤖 Servomotoren für Roboter-Arme
- 📺 LCD-Displays für coole Anzeigen
- 🌡️ Sensoren (Temperatur, Abstand, Licht, Bewegung...)
- 🎵 Sound-Module und Musik-Player
- 🎮 Game-Controller bauen
- 💡 Smarthome-Projekte
- ...und was dir sonst noch einfällt!


## Kontakt

Bei Fragen zum Kurs oder Material:  
**MINT-Labs Regensburg**  
🌐 [https://www.mint-labs-regensburg.de/](https://www.mint-labs-regensburg.de/)

---

**Viel Erfolg und Spaß beim Arduino-Kurs!** 🔧⚡
