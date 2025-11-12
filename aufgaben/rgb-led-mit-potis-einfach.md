
# Aufgabe: RGB-LED mit Potentiometern steuern

## 🎯 Ziel
Steuere die Farbe einer RGB-LED stufenlos mit drei Potentiometern (Rot, Grün, Blau).


## 📚 Was du lernst
- Wie eine RGB-LED funktioniert
- Was ein Potentiometer ist
- `analogRead()` und `analogWrite()` verwenden
- PWM für Farbsteuerung

## 💡 Was ist eine RGB-LED?
Eine RGB-LED vereint drei LEDs (Rot, Grün, Blau) in einem Gehäuse. Je nach Ansteuerung der einzelnen Farben kann die LED fast jede beliebige Farbe anzeigen. Die drei Farbkanäle werden meist über eigene Pins angesteuert. Es gibt zwei Typen:
- **Gemeinsame Kathode (GND):** Das lange Bein kommt an GND, die drei anderen an die PWM-Pins.
- **Gemeinsame Anode (+5V):** Das lange Bein kommt an +5V, die drei anderen an die PWM-Pins (invertierte Logik).

## 💡 Was ist ein Potentiometer?
Ein Potentiometer (kurz: "Poti") ist ein verstellbarer Widerstand mit drei Anschlüssen:
- Ein Ende an +5V
- Ein Ende an GND
- Die Mitte (Schleifer) liefert eine Spannung zwischen 0V und 5V

Drehst du am Poti, verändert sich die Spannung am mittleren Anschluss stufenlos von 0V bis 5V. Der Arduino kann diese Spannung mit `analogRead()` messen (Wertebereich: 0 bis 1023).

## 🧰 Benötigte Hardware
- 1× Arduino Uno/Nano
- 1× RGB-LED (gemeinsame Kathode empfohlen)
- 3× Widerstände 220Ω (rot-rot-braun) für die LED
- 3× Potentiometer (10kΩ)
- Jumper-Kabel
- 1× Breadboard

## 🔌 Schaltplan

```
Pin 9   → 220Ω → R (rotes Bein der LED)
Pin 10  → 220Ω → G (grünes Bein der LED)
Pin 11  → 220Ω → B (blaues Bein der LED)
Langes Bein der LED → GND
Poti 1: +5V, GND, Schleifer an A0
Poti 2: +5V, GND, Schleifer an A1
Poti 3: +5V, GND, Schleifer an A2
```

**Hinweis:**
- Es gibt zwei Typen RGB-LEDs:
  - **Gemeinsame Kathode (GND):** Langes Bein an GND, die drei anderen an die PWM-Pins.
  - **Gemeinsame Anode (+5V):** Langes Bein an +5V, die drei anderen an die PWM-Pins (invertierte Logik).

## 📝 Schritt-für-Schritt Anleitung

### Schritt 1: Schaltung aufbauen
1. **Arduino vom USB trennen** (Sicherheit!)
2. **RGB-LED ins Breadboard stecken:**
   - Langes Bein (gemeinsame Kathode) an GND
   - R, G, B an die PWM-Pins (9, 10, 11) über je einen 220Ω Widerstand
3. **Potis anschließen:**
   - Jeweils ein Ende an +5V, das andere an GND
   - Schleifer (Mitte) von Poti 1 an A0, Poti 2 an A1, Poti 3 an A2
4. **Arduino wieder per USB verbinden**

### Schritt 2: Code schreiben

Öffne `src/main.cpp` und ersetze den Inhalt mit:

```cpp
#include <Arduino.h>

const int RED_PIN = 9;
const int GREEN_PIN = 10;
const int BLUE_PIN = 11;
const int PotiR = A0;
const int PotiG = A1;
const int PotiB = A2;

void setup() {
    pinMode(RED_PIN, OUTPUT);
    pinMode(GREEN_PIN, OUTPUT);
    pinMode(BLUE_PIN, OUTPUT);
}

void loop() {
    int r = analogRead(PotiR);   // 0-1023
    int g = analogRead(PotiG);
    int b = analogRead(PotiB);

    // Werte umrechnen auf 0-255 für PWM
    int r_pwm = map(r, 0, 1023, 0, 255);
    int g_pwm = map(g, 0, 1023, 0, 255);
    int b_pwm = map(b, 0, 1023, 0, 255);

    analogWrite(RED_PIN, r_pwm);
    analogWrite(GREEN_PIN, g_pwm);
    analogWrite(BLUE_PIN, b_pwm);
}
```

### Schritt 3: Testen
1. **Speichern:** `Ctrl+S`
2. **Kompilieren:** Klick auf ✓ (Build) in der Statusleiste
3. **Hochladen:** Klick auf → (Upload) in der Statusleiste
4. **Drehe an den Potis:** Die LED sollte die Farbe ändern!

## 🔍 Code-Erklärung

```cpp
int r = analogRead(PotiR);
int r_pwm = map(r, 0, 1023, 0, 255);
analogWrite(RED_PIN, r_pwm);
```
- Liest den Wert vom Poti (0-1023)
- Rechnet ihn um auf 0-255 für PWM
- Setzt die Helligkeit des jeweiligen Farbkanals

## ❓ Häufige Fehler

- **LED bleibt dunkel:** Prüfe GND, Widerstände und Verkabelung
- **Farben stimmen nicht:** Anschlüsse an den PWM-Pins vertauscht?
- **LED ist sehr schwach:** Prüfe die Widerstandswerte (220Ω empfohlen)
- **Nichts passiert:** Richtige Pins im Code? Potis korrekt angeschlossen?

## ℹ️ Begriffe erklärt

- **PWM:** Pulsweitenmodulation, steuert Helligkeit durch schnelles An/Aus
- **analogRead():** Liest analogen Wert (0-1023)
- **analogWrite():** Gibt PWM-Signal aus (0-255)
- **Potentiometer:** Drehwiderstand, liefert stufenlos verstellbare Spannung
- **RGB-LED:** LED mit 3 Farben in einem Gehäuse

Viel Spaß beim Farbmischen!
