### Programmierung des Arduino: Lasse die LED blinken

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


## 📝 Schritt-für-Schritt Anleitung

### Schritt 1: LED ansteuern
### 🔌 Schaltplan LED

<img src="..\medien\LED_Schaltplan.png" alt="Schaltplan mit LED" width="350" />


> **Wichtig:** Der Vorwiderstand schützt die LED und den Arduino vor zu hohem Strom!



1. **Arduino vom USB trennen** (Sicherheit!)
2. **LED ins Breadboard:**
    - Langes Bein = Plus, kurzes = Minus
    - 220Ω Widerstand vom langen Bein zu Pin **D7**
    - Kurzes LED-Bein zu GND

---

### Programmierung des Arduino: Lasse die LED blinken

Schreibe ein Programm, das die LED an Pin D7 blinken lässt. 

**Dazu ist erforderlich:**
- `pinMode()` – Pin als Ausgang konfigurieren
- `digitalWrite()` – LED ein/aus schalten
- `delay()` – Pausen zwischen den Zuständen
- Endlosschleife (`loop()`-Funktion)


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


---

### Zusatzaufgabe

1. **LED 10 mal blinken lassen:**
    - Lasse die LED 10 mal blinken. Warte 2 Sekunden, dann wieder 10 mal blinken

2. **Morsecode SOS:**
    - Schreibe ein Programm, das die LED das Morsezeichen SOS blinken lässt:
        - S = kurz kurz kurz (drei schnelle Blinks)
        - O = lang lang lang (drei lange Blinks)
        - S = kurz kurz kurz (drei schnelle Blinks)
    - Tipp: Nutze unterschiedliche `delay()`-Werte für kurz (z.B. 150 ms) und lang (z.B. 500 ms) und passende Pausen zwischen den Buchstaben.

---



### Schritt 2: Taster zusätzlich einbauen
## 🔌 Schaltplan LED und Taster

<img src="..\medien\LED_Taster_Schaltplan.png" alt="Schaltplan mit LED und Taster" width="350" />

LED über 220Ω Vorwiderstand an Output D7   
Taster mit 10kΩ Pullup Widerstand an Input2 D7 




---

### Schritt 3: LED leuchtet, wenn Taster gedrückt ist
1. **Code für direkte Steuerung:**
    
    ```cpp
    #include <Arduino.h>
    const int TASTER_PIN = 2;
    const int LED_PIN = 7;
    void setup() {
    }
    void loop() {
        int tasterZustand = digitalRead(TASTER_PIN);
        if (tasterZustand == HIGH) {
        } else {
            digitalWrite(LED_PIN, LOW);  // LED aus
        }
---

### Schritt 4: Toggle-Funktion programmieren

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
```
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
