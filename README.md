# <img src="assets/arduino-logos-512px.png" alt="Arduino IDE Logo" width="38" style="vertical-align:middle;"> Arduino Makerkurs für Einsteiger – In 3 Stunden zum eigenen Mikrocontroller-Projekt

<img src="assets/Arduino Uno mit Potentiometer und LED.png" alt="Arduino Uno mit LED und Potentiometer" width="420" />

---

## Inhaltsangabe

- [ Arduino Makerkurs für Einsteiger – In 3 Stunden zum eigenen Mikrocontroller-Projekt](#-arduino-makerkurs-für-einsteiger--in-3-stunden-zum-eigenen-mikrocontroller-projekt)
  - [Inhaltsangabe](#inhaltsangabe)
  - [Was dich erwartet](#was-dich-erwartet)
  - [📋 Kursübersicht](#-kursübersicht)
  - [🎯 Lernziele](#-lernziele)
  - [🧰 01 Dein Start in die Maker Welt](#-01-dein-start-in-die-maker-welt)
  - [💡 02 Was ist eine LED? Wie fliesst der Strom?](#-02-was-ist-eine-led-wie-fliesst-der-strom)
  - [🖥️ 03 Was ist ein Microcontroller](#️-03-was-ist-ein-microcontroller)
  - [💻 04 Programmiere den Arduino mit der Arduino IDE](#-04-programmiere-den-arduino-mit-der-arduino-ide)
  - [🔦 05 Digital Output](#-05-digital-output)
  - [🌈 06 Analog Output](#-06-analog-output)
  - [🔲 07 Digital Input](#-07-digital-input)
  - [📈 08 Analog Input](#-08-analog-input)
  - [📞 Kontakt](#-kontakt)

---

## Was dich erwartet

Du bist 10 Jahre alt oder älter, neugierig auf Mikrocontroller und hast Lust aufs Experimentieren?  
Dann bist du hier richtig im **Maker Kurs für Einsteiger**!

Tauche ein in die spannende Welt der Mikrocontroller! Mit dem Arduino bringst du LEDs zum Leuchten und baust interaktive Schaltungen. In nur drei Stunden lernst du die Basics der Programmierung und Elektronik – und nimmst dein eigenes funktionierendes Gadget mit nach Hause!

---

## 📋 Kursübersicht

- **Gesamtdauer:** 3 Stunden
- **Zielgruppe:** Jugendliche ab 10 Jahren ohne Programmiererfahrung
- **Format:** Interaktiver Freizeitkurs – 100% praktisches Lernen

---

## 🎯 Lernziele

Am Ende des Kurses kannst du:

- einen Arduino anschließen und die Arduino IDE bedienen
- einfache Programme (Sketches) schreiben und auf den Arduino laden
- LEDs zum Leuchten bringen und blinken lassen
- digitale und analoge Eingaben (z.B. Taster, Potentiometer) auslesen
- die Helligkeit einer LED mit einem Potentiometer steuern
- eigene kleine Schaltungen auf dem Breadboard aufbauen

---

## 🧰 01 Dein Start in die Maker Welt

**🏆 Challenge 01: "Lerne dein Makerkit kennen – was ist was?"**  

Du bekommst ein Arduino Maker Kit. Es enthält neben dem Arduino viele elektronische Bauelemente und Material für verschiedene Experimente.

Öffne die Kiste. Was findest du?
- Arduino UNO
- Steckplatine (Breadboard)
- LEDs
- Widerstände
- Jumper-Kabel
- Taster
- was noch?

---
## 💡 02 Was ist eine LED? Wie fliesst der Strom?

Eine LED (Licht-Emittierende Diode) ist ein kleines Bauteil, das leuchtet, wenn Strom hindurchfließt.  
Sie hat zwei Beine:  
- Das **lange Bein** ist die **Anode** (+), hier kommt der Pluspol hin.
- Das **kurze Bein** ist die **Kathode** (–), hier kommt der Minuspol (GND) hin.

**Wichtig:**  
Eine LED braucht immer einen Vorwiderstand (z.B. 220 Ω), damit sie nicht durch zu viel Strom kaputt geht.

**So wird eine LED an eine Batterie angeschlossen:**  
- [01_LED5VBatterie_Schaltplan.png](zusatzmaterial/01_LED5VBatterie_schem.png)  
- [01_LED5VBatterie_Steckplatine.png](zusatzmaterial/01_LED5VBatterie_bb.png)


**🏆 Challenge 02: "Bringe eine LED zum Leuchten"**  
- Wir verwenden den Arduino anstatt einer Batterie als 5Volt Stromquelle
- Wir verwenden das Breadboard. Damit sparen wir und das umständliche Löten
- Wir vewenden einen 220 Ω Vorwiderstand. Du erkennst ihn an der Markierung rot-rot-braun.
- Das sieht dann so aus:  
  - [02_LED5VArduino_Schaltplan.png](zusatzmaterial/02_LED5VArduino_schem.png)  
  - [02_LED5VArduino_Steckplatine.png](zusatzmaterial/02_LED5VArduino_bb.png)

---
## 🖥️ 03 Was ist ein Microcontroller

Der Arduino ist ein Mikrocontroller mit vielen Anschlüssen (Pins). Du lernst, welche Arten von Pins es gibt und wie du sie identifizierst:
- Stromversorgungs-Pins: 5V, 3V3 (kennst du ja schon) und  
- Inputs, Outputs

**🏆 Challenge 03: "Identifiziere die Pins deines Arduino"**
- Die Pinbelegung des Arduino findest du im Ordner zusatzmaterial:  
  [03_Arduino UNO Pinout](zusatzmaterial/03_Arduino-UNO-pinout.jpg)  
- Suche die Powerpins
- Suche einen digitalen Output
- Suche einen analogen Output
- Suche einen digitalen Input
- Suche einen analogen Input

---

## 💻 04 Programmiere den Arduino mit der Arduino IDE

Jetzt geht es ans Programmieren!  
Du verwendest die Arduino IDE als Programmierzentrale. In der IDE erstellst du einen einfachen Sketch (Programm), lädst den Code in den Arduino und startest deinen Sketch.

**🏆 Challenge 04: "Erstelle dein erstes Programm: 'Hello World'"**
- [challenge_04_hello_world.ino](challenge_04_hello_world.ino)

**Hinweis:** Ein praktisches Arduino-Cheatsheet findest du im Ordner zusatzmaterial:  
[04_arduino-cheatsheet-deutsch.pdf](zusatzmaterial/04_arduino-cheatsheet-deutsch.pdf)

---

## 🔦 05 Digital Output

Bisher haben wir den Arduino nur als "Batterieersatz" der 5 Volt liefert verwendet, um die LED zum Leuchten zu bringen.
Jetzt wollen wir die LED ansteuern und sie blinken lassen. Dazu benutzten wir einen digitalen Output des Arduino.

**🏆 Challenge 05: "Digital Output – Lass eine LED blinken"**

- [05_LED_Schaltplan.png](zusatzmaterial/05_LED_schem.png)
- [05_LED_Steckplatine.png](zusatzmaterial/05_LED_bb.png)
- [challenge_05_led_blinken.ino](challenge_05_led_blinken.ino)


**🏆 Zusatz Challenge 05z für Fortgeschrittene: "Lass die LED im Morsecode SOS blinken"**
- [challenge_05z_morsecode_sos.ino](challenge_05z_morsecode_sos.ino)

---

## 🌈 06 Analog Output

Der Arduino hat nicht nur Ausgänge, die nur "AN" (5 Volt) und "AUS" (0 Volt) können. Es gibt auch "Analog Outputs", sogenannte PWM-Outputs, die viele Spannungen zwischen 0 und 5 Volt erzeugen können. Nutze einen analogen Output, um eine LED sanft hell und wieder dunkel werden zu lassen (Dimmen).

**🏆 Challenge 06: "LED Dimmen"**
- Wähle einen Ausgang, der Analog Output (PWM) kann (z.B. Pin 11, erkennbar an der ~).
- [challenge_06_led_dimmen.ino](challenge_06_led_dimmen.ino)

---

## 🔲 07 Digital Input

Der Arduino hat auch Eingangspins. Digital Inputs erkennen, ob am Eingang 0 V oder 5 V anliegen.

**🏆 Challenge 07: "Mit Taster LED schalten"**

- [07_LED_Taster_Schaltplan.png](zusatzmaterial/07_LED_Taster_schem.png)
- [07_LED_Taster_Steckplatine.png](zusatzmaterial/07_LED_Taster_bb.png)
- [challenge_07_taster_led.ino](challenge_07_taster_led.ino)

**🏆 Zusatz Challenge 07z: "Mit Taster LED toggeln"**
- Schalte die LED abwechselnd ein und aus mit jedem Tastendruck.
- [challenge_07z_taster_toggle_led.ino](challenge_07z_taster_toggle_led.ino)

---

## 📈 08 Analog Input

Der Arduino hat auch "Analog Inputs". Das sind Eingangspins, die nicht nur AN oder AUS kennen, sondern viele Werte dazwischen.  
Mit einem Analog Input kannst du z.B. einen Drehregler (Potentiometer) auslesen und damit die Helligkeit einer LED an einem analog output stufenlos steuern.

**🏆 Challenge 08: "Poti auslesen und LED ansteuern"**
- [08_LED_Poti_Schaltplan.png](zusatzmaterial/08_LED_Poti_schem.png)
- [08_LED_Poti_Steckplatine.png](zusatzmaterial/08_LED_Poti_bb.png)
- [challenge_08_poti_led.ino](challenge_08_poti_led.ino)

---

## 📞 Kontakt

Bei Fragen zum Kurs oder Material:  
**MINT-Labs Regensburg**  
🌐 [https://www.mint-labs-regensburg.de/](https://www.mint-labs-regensburg.de/)
