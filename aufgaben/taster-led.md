
# Aufgabe: LED mit Taster steuern

## 🎯 Ziel
Eine LED mit einem Taster ein- und ausschalten (Toggle-Funktion)

## 📚 Was du lernst
- Digitale Ausgänge mit `digitalWrite()` setzen
- Digitale Eingaben mit `digitalRead()` einlesen
- Vorwiderstand verstehen
- Pull-Down-Widerstände verstehen
- Taster-Entprellung (Debouncing)
- Zustandsspeicherung mit Variablen
- Unterschied zwischen Taster gedrückt und Tasterdruck erkannt

## 🧰 Benötigte Hardware
- 1× Arduino Uno/Nano
- 1× LED (beliebige Farbe)
- 1× Widerstand 220Ω (rot-rot-braun) für LED
- 1× Widerstand 10kΩ (braun-schwarz-orange) für Taster
- 1× Taster (Push Button)
- Jumper-Kabel
- 1× Breadboard


## 🔌 Schaltplan LED

<img src="..\assets\LED_Schaltplan.png" alt="Schaltplan mit LED" width="350" />

LED über 220Ω Vorwiderstand an Output D7   



## 📝 Schritt-für-Schritt Anleitung

### Schritt 1: LED ansteuern
1. **Arduino vom USB trennen** (Sicherheit!)
2. **LED ins Breadboard:**
    - Langes Bein = Plus, kurzes = Minus
    - 220Ω Widerstand vom langen Bein zu Pin **D7**
    - Kurzes LED-Bein zu GND
3. **Arduino wieder per USB verbinden**

4. **Test-Code für LED:**

```cpp
#include <Arduino.h>

const int LED_PIN = 7;

void setup() {
    pinMode(LED_PIN, OUTPUT);
}

void loop() {
    digitalWrite(LED_PIN, HIGH); // LED an
    delay(500);
    digitalWrite(LED_PIN, LOW);  // LED aus
    delay(500);
}
```

5. **LED sollte blinken!**

---

### Schritt 2: Taster zusätzlich einbauen
## 🔌 Schaltplan LED und Taster

<img src="..\assets\LED_Taster_Schaltplan.png" alt="Schaltplan mit LED und Taster" width="350" />

LED über 220Ω Vorwiderstand an Output D7   
Taster mit 10kΩ Pullup Widerstand an Input2 D7 

1. **Arduino wieder vom USB trennen**
2. **Taster ins Breadboard:**
    - Ein Taster-Pin zu **D2**
    - Anderer Taster-Pin zu GND
    - 10kΩ Widerstand von **D2** zu +5V (Pullup)
3. **Arduino wieder per USB verbinden**


### Schritt 3: LED leuchtet, wenn Taster gedrückt ist
1. **Code für direkte Steuerung:**

```cpp
#include <Arduino.h>

const int TASTER_PIN = 2;
const int LED_PIN = 7;

void setup() {
    pinMode(TASTER_PIN, INPUT);
    pinMode(LED_PIN, OUTPUT);
}

void loop() {
    int tasterZustand = digitalRead(TASTER_PIN);
    if (tasterZustand == HIGH) {
        digitalWrite(LED_PIN, HIGH); // LED an
    } else {
        digitalWrite(LED_PIN, LOW);  // LED aus
    }
}
```

2. **Testen:** Die LED leuchtet nur, solange der Taster gedrückt wird.

---

### Schritt 4: Code schreiben (Toggle-Version)

Öffne `src/main.cpp` und ersetze den Inhalt mit:

```cpp
#include <Arduino.h>

const int TASTER_PIN = 2;
const int LED_PIN = 7;

bool ledZustand = false;           // LED-Status speichern
bool letzterTasterZustand = LOW;   // Vorheriger Taster-Status

void setup()
{
    Serial.begin(115200);
    Serial.println("Taster-LED gestartet (Toggle)");
    pinMode(TASTER_PIN, INPUT);
    pinMode(LED_PIN, OUTPUT);
}

void loop()
{
    // Aktuellen Taster-Zustand lesen
    int tasterZustand = digitalRead(TASTER_PIN);
    // Prüfen ob Taster GERADE gedrückt wurde (Flanke)
    if (tasterZustand == HIGH && letzterTasterZustand == LOW) {
        // Taster wurde gerade gedrückt!
        ledZustand = !ledZustand;  // LED-Status umkehren
        digitalWrite(LED_PIN, ledZustand);
        Serial.print("Toggle! LED ist jetzt: ");
        Serial.println(ledZustand ? "AN" : "AUS");
        delay(50);  // Entprellung
    }
    // Aktuellen Zustand für nächsten Durchlauf speichern
    letzterTasterZustand = tasterZustand;
    delay(10);  // Kurze Pause
}
```

### Schritt 3: Testen
1. **Speichern:** `Ctrl+S`
2. **Kompilieren:** Klick auf ✓ (Build) in der Statusleiste
3. **Hochladen:** Klick auf → (Upload) in der Statusleiste
4. **Taster drücken:** Die LED sollte bei jedem Druck umschalten!

## 🔍 Code-Erklärung

```cpp
if (tasterZustand == HIGH && letzterTasterZustand == LOW) {
    // Taster wurde GERADE gedrückt (steigende Flanke)
}
```
- Erkennt den Moment des Drückens
- Nicht: "Taster ist gedrückt", sondern: "Taster wurde gerade gedrückt"

```cpp
ledZustand = !ledZustand;  // Umkehren: true → false, false → true
```
- `!` ist der NOT-Operator, kehrt Boolean-Wert um

## ❓ Häufige Fehler

- **Taster funktioniert nicht / LED flackert:** Kein Pull-Down-Widerstand? 10kΩ von Pin zu GND oder `INPUT_PULLUP` verwenden
- **LED schaltet mehrfach bei einem Druck:** Taster prellt mechanisch → Entprellung mit `delay(50)` oder Zeitprüfung
- **LED reagiert verzögert:** `delay()` blockiert Programm → `millis()` statt `delay()` verwenden
- **Pin "schwebt" (random HIGH/LOW):** Floating Pin ohne Pull-Widerstand → Pull-Down (zu GND) oder Pull-Up (zu +5V) verwenden

## ℹ️ Begriffe erklärt

- **Pull-Down:** Widerstand von Pin zu GND → Pin standardmäßig LOW
- **Pull-Up:** Widerstand von Pin zu +5V → Pin standardmäßig HIGH
- **Floating Pin:** Pin ohne Pull-Widerstand → zufällige Werte
- **Entprellung (Debouncing):** Filtern mechanischer Kontaktschwingungen
- **Flanke:** Übergang von LOW zu HIGH (steigend) oder HIGH zu LOW (fallend)
- **Toggle:** Umschalten zwischen zwei Zuständen
- **millis():** Millisekunden seit Arduino-Start (läuft ~50 Tage)

### Mit internem Pull-Up (ohne 10kΩ Widerstand)
```
Arduino Pin 7 ----[Taster]---- GND
             |
         (intern Pull-Up)
             
// Im Code:
pinMode(TASTER_PIN, INPUT_PULLUP);
// Jetzt: Nicht gedrückt = HIGH, Gedrückt = LOW!
```

Vorteil: Ein Widerstand weniger!  
Nachteil: Logik ist umgekehrt (LOW = gedrückt)

## ✅ Checkliste

- [ ] Schaltung aufgebaut (LED + Taster mit Pull-Down)
- [ ] Einfache Version getestet (Taster hält LED an)
- [ ] Toggle-Version implementiert
- [ ] Entprellung verstanden und getestet
- [ ] Mindestens ein Experiment ausprobiert
- [ ] Alternative mit INPUT_PULLUP getestet
- [ ] Serial Monitor für Debug-Ausgaben genutzt

---

**Viel Erfolg beim Tüfteln!** 🎮
