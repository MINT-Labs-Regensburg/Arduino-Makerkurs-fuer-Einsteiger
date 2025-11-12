# Aufgabe: LED dimmen mit PWM

## 🎯 Ziel
Eine LED sanft heller und dunkler machen (Atmungseffekt/"Breathing")

## 📚 Was du lernst
- PWM (Pulse Width Modulation)
- `analogWrite()` verwenden
- For-Schleifen für Animationen
- Unterschied zwischen digitalen und PWM-Pins

## 🧰 Benötigte Hardware
- 1× Arduino Uno
- 1× LED (beliebige Farbe)
- 1× Widerstand 220Ω (rot-rot-braun)
- 2× Jumper-Kabel
- 1× Breadboard

## 🔌 Schaltplan

```
Arduino Pin 9 ----[220Ω]----[LED]---- GND
                 Widerstand  |
                        (lang/+)
```

**Wichtig:** 
- LED hat zwei Beine: **lang = Plus (Anode)**, **kurz = Minus (Kathode)**
- Widerstand schützt die LED vor zu viel Strom!

## 📝 Schritt-für-Schritt Anleitung

### Schritt 1: Schaltung aufbauen

1. **Arduino vom USB trennen** (Sicherheit!)
2. **LED ins Breadboard stecken:**
   - Langes Bein (Anode) in eine Reihe
   - Kurzes Bein (Kathode) in eine andere Reihe
3. **Widerstand anschließen:**
   - Ein Ende zum langen LED-Bein
   - Anderes Ende zu einer freien Reihe
4. **Jumper-Kabel anschließen:**
   - Pin 9 vom Arduino → Widerstand-Seite
   - GND vom Arduino → kurzes LED-Bein
5. **Arduino wieder per USB verbinden**

### Schritt 2: Code verstehen

**Was ist PWM?**
PWM steht für „Pulsweitenmodulation“. Dabei wird ein Pin sehr schnell ein- und ausgeschaltet. Je länger der Pin „an“ ist, desto heller leuchtet z.B. eine LED. Das Auge sieht kein Flackern, sondern eine stufenlose Helligkeit. Der Arduino kann mit `analogWrite()` solche PWM-Signale erzeugen. So lässt sich die Helligkeit regeln, obwohl der Pin eigentlich nur „an“ oder „aus“ kennt.

**PWM-Werte:**
- `0` = komplett aus (0% Einschaltzeit)
- `128` = halbe Helligkeit (50% Einschaltzeit)
- `255` = voll an (100% Einschaltzeit)

**PWM-fähige Pins am Arduino Uno:**
- Pin 3, 5, 6, 9, 10, 11
- Erkennbar am **~** Symbol auf dem Board

### Schritt 3: Code schreiben

Öffne `src/main.cpp` und ersetze den Inhalt mit:

```cpp
/*
 * LED Dimmen - Atmungseffekt
 * 
 * Diese Programm lässt eine LED sanft heller und dunkler werden
 */

#include <Arduino.h>

const int LED_PIN = 9;  // PWM-fähiger Pin

void setup()
{
    // Serielle Kommunikation für Debug-Ausgaben
    Serial.begin(115200);
    Serial.println("LED Dimming gestartet!");
    
    // Pin 9 als Ausgang festlegen
    pinMode(LED_PIN, OUTPUT);
}

void loop()
{
    // LED von dunkel nach hell dimmen (Fade In)
    for (int helligkeit = 0; helligkeit <= 255; helligkeit++) {
        analogWrite(LED_PIN, helligkeit);
        delay(10);  // 10ms warten = sanfter Übergang
    }
    
    // LED von hell nach dunkel dimmen (Fade Out)
    for (int helligkeit = 255; helligkeit >= 0; helligkeit--) {
        analogWrite(LED_PIN, helligkeit);
        delay(10);
    }
}
```


## 🔍 Code-Erklärung

### Die wichtigsten Teile:

```cpp
const int LED_PIN = 9;
```
- Definiert, welcher Pin verwendet wird
- `const` = Wert kann nicht geändert werden
- Pin 9 ist PWM-fähig

```cpp
analogWrite(LED_PIN, helligkeit);
```
- Setzt die PWM-Helligkeit
- `helligkeit` kann 0-255 sein
- 0 = aus, 255 = voll an

```cpp
for (int helligkeit = 0; helligkeit <= 255; helligkeit++)
```
- Zählt von 0 bis 255 hoch
- Nach jedem Durchlauf: `helligkeit++` (erhöht um 1)
- LED wird immer heller

```cpp
for (int helligkeit = 255; helligkeit >= 0; helligkeit--)
```
- Zählt von 255 bis 0 runter
- Nach jedem Durchlauf: `helligkeit--` (verringert um 1)
- LED wird immer dunkler

```cpp
delay(10);
```
- Wartet 10 Millisekunden
- Macht den Übergang sanft
- Kleinerer Wert = schnelleres Dimmen
- Größerer Wert = langsameres Dimmen

## 🎨 Experimente zum Ausprobieren

### Experiment 1: Geschwindigkeit ändern
```cpp
delay(5);   // Schneller
delay(20);  // Langsamer
```

### Experiment 2: Nur halb so hell
```cpp
for (int helligkeit = 0; helligkeit <= 128; helligkeit++) {
    // Maximal halbe Helligkeit
}
```

### Experiment 3: In Stufen dimmen
```cpp
for (int helligkeit = 0; helligkeit <= 255; helligkeit += 10) {
    // Springt in 10er-Schritten: 0, 10, 20, 30...
    analogWrite(LED_PIN, helligkeit);
    delay(50);
}
```

### Experiment 4: Pause zwischen Fade In/Out
```cpp
void loop()
{
    // Fade In
    for (int helligkeit = 0; helligkeit <= 255; helligkeit++) {
        analogWrite(LED_PIN, helligkeit);
        delay(10);
    }
    
    delay(1000);  // 1 Sekunde warten bei voller Helligkeit
    
    // Fade Out
    for (int helligkeit = 255; helligkeit >= 0; helligkeit--) {
        analogWrite(LED_PIN, helligkeit);
        delay(10);
    }
    
    delay(1000);  // 1 Sekunde warten bei Dunkelheit
}
```

## ❓ Häufige Fehler

### LED blinkt nur, dimmt aber nicht
- ❌ **Problem:** Falscher Pin verwendet (z.B. Pin 13)
- ✅ **Lösung:** Nur PWM-Pins verwenden: 3, 5, 6, 9, 10, 11

### LED leuchtet gar nicht
- ❌ **Problem:** LED falsch herum eingesteckt
- ✅ **Lösung:** Langes Bein zu Pin 9, kurzes zu GND
- ❌ **Problem:** Kein Widerstand → LED kaputt
- ✅ **Lösung:** Immer Widerstand verwenden!

### LED ist sehr schwach
- ❌ **Problem:** Widerstand zu groß (z.B. 10kΩ)
- ✅ **Lösung:** 220Ω verwenden

### Code kompiliert nicht
- ❌ **Problem:** `#include <Arduino.h>` fehlt
- ✅ **Lösung:** Muss in der ersten Zeile stehen (bei PlatformIO)

## 🏆 Erweiterungen für Fortgeschrittene

### RGB-LED mit 3 Farben dimmen
```cpp
const int RED_PIN = 9;
const int GREEN_PIN = 10;
const int BLUE_PIN = 11;

void loop() {
    // Rot dimmen
    for (int i = 0; i <= 255; i++) {
        analogWrite(RED_PIN, i);
        delay(5);
    }
    // Grün dimmen...
}
```

### Mit Potentiometer steuern
```cpp
int potiWert = analogRead(A0);           // Liest 0-1023
int helligkeit = map(potiWert, 0, 1023, 0, 255);  // Wandelt um auf 0-255
analogWrite(LED_PIN, helligkeit);
```

## 📚 Begriffe erklärt

- **PWM (Pulse Width Modulation):** Schnelles Ein-/Ausschalten zur Helligkeitssteuerung
- **Duty Cycle:** Prozentsatz der "Ein"-Zeit (50% = halbe Helligkeit)
- **Frequenz:** Wie oft pro Sekunde geschaltet wird (490 Hz beim Arduino Uno)
- **analogWrite():** Funktion zum Setzen der PWM-Helligkeit (0-255)
- **digitalWrite():** Nur EIN/AUS (HIGH/LOW), kein Dimmen möglich

## ✅ Checkliste

- [ ] Schaltung aufgebaut und überprüft
- [ ] Code geschrieben und verstanden
- [ ] Erfolgreich hochgeladen
- [ ] LED dimmt sanft heller und dunkler
- [ ] Mindestens ein Experiment ausprobiert
- [ ] Andere Pin-Nummern getestet
- [ ] Geschwindigkeit variiert

## 🎓 Nächste Schritte

Nach dieser Aufgabe kannst du:
- Mehrere LEDs gleichzeitig dimmen
- RGB-LEDs für Farbmischungen verwenden
- Mit Tastern die Helligkeit steuern
- Lauflicht-Effekte programmieren

---

**Viel Erfolg beim Experimentieren!** 🚀
