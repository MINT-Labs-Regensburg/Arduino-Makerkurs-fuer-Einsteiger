# Aufgabe: LED mit Taster steuern

## 🎯 Ziel
Eine LED mit einem Taster ein- und ausschalten (Toggle-Funktion)

## 📚 Was du lernst
- Digitale Eingaben mit `digitalRead()` einlesen
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

## 🔌 Schaltplan

```
                    +5V
                     |
Arduino Pin 7 ----[Taster]----[10kΩ]---- GND
                               Pull-Down

Arduino Pin 9 ----[220Ω]----[LED]---- GND
                 Widerstand  |
                        (lang/+)
```

**Wichtig:**
- **Taster:** Pin 7 zwischen Taster und +5V, 10kΩ Pull-Down zu GND
- **LED:** Pin 9 über 220Ω Widerstand zur LED, dann zu GND

## 📝 Schritt-für-Schritt Anleitung

### Schritt 1: Schaltung aufbauen

#### LED-Teil (wie vorher):
1. LED ins Breadboard (langes Bein = Plus, kurzes = Minus)
2. 220Ω Widerstand vom langen Bein zu Pin 9
3. Kurzes LED-Bein zu GND

#### Taster-Teil:
1. **Taster ins Breadboard** (über die Mitte)
2. **+5V** zu einem Taster-Pin
3. **Pin 7** zum anderen Taster-Pin (gleiche Seite wie +5V)
4. **10kΩ Widerstand** von Pin 7 zu GND (Pull-Down)

**Warum Pull-Down-Widerstand?**
- Ohne Widerstand "schwebt" der Pin (floating) → zufällige Werte!
- Pull-Down zieht Pin auf GND → sauberes LOW-Signal
- Taster gedrückt → Pin wird HIGH (+5V)

### Schritt 2: Code - Einfache Version

```cpp
/*
 * LED mit Taster steuern - Einfache Version
 * 
 * Taster gedrückt = LED an
 * Taster losgelassen = LED aus
 */

#include <Arduino.h>

const int TASTER_PIN = 7;
const int LED_PIN = 9;

void setup()
{
    Serial.begin(115200);
    Serial.println("Taster-LED gestartet (einfach)");
    
    pinMode(TASTER_PIN, INPUT);  // Taster als Eingang
    pinMode(LED_PIN, OUTPUT);     // LED als Ausgang
}

void loop()
{
    // Taster-Zustand lesen
    int tasterZustand = digitalRead(TASTER_PIN);
    
    // LED entsprechend setzen
    if (tasterZustand == HIGH) {
        digitalWrite(LED_PIN, HIGH);  // LED an
        Serial.println("Taster gedrückt - LED AN");
    } else {
        digitalWrite(LED_PIN, LOW);   // LED aus
        Serial.println("Taster losgelassen - LED AUS");
    }
    
    delay(100);  // Kurze Pause
}
```

**Problem:** LED geht aus, sobald Taster losgelassen wird!

### Schritt 3: Code - Toggle-Version (Ein/Aus wechseln)

```cpp
/*
 * LED mit Taster steuern - Toggle-Version
 * 
 * Jeder Tastendruck wechselt LED zwischen AN und AUS
 */

#include <Arduino.h>

const int TASTER_PIN = 7;
const int LED_PIN = 9;

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

### Schritt 4: Code - Professionelle Version mit Entprellung

```cpp
/*
 * LED mit Taster steuern - Mit Entprellung
 * 
 * Saubere Erkennung von Tastendrücken ohne Prellen
 */

#include <Arduino.h>

const int TASTER_PIN = 7;
const int LED_PIN = 9;
const unsigned long ENTPRELLZEIT = 50;  // 50ms Entprellzeit

bool ledZustand = false;
bool letzterTasterZustand = LOW;
unsigned long letzteAenderungZeit = 0;

void setup()
{
    Serial.begin(115200);
    Serial.println("Taster-LED mit Entprellung");
    
    pinMode(TASTER_PIN, INPUT);
    pinMode(LED_PIN, OUTPUT);
}

void loop()
{
    int tasterZustand = digitalRead(TASTER_PIN);
    unsigned long aktuelleZeit = millis();
    
    // Prüfen ob genug Zeit seit letzter Änderung vergangen ist
    if ((aktuelleZeit - letzteAenderungZeit) > ENTPRELLZEIT) {
        
        // Prüfen ob Taster-Flanke (LOW → HIGH)
        if (tasterZustand == HIGH && letzterTasterZustand == LOW) {
            // Toggle LED
            ledZustand = !ledZustand;
            digitalWrite(LED_PIN, ledZustand);
            
            Serial.print("LED umgeschaltet: ");
            Serial.println(ledZustand ? "AN" : "AUS");
            
            letzteAenderungZeit = aktuelleZeit;
        }
    }
    
    letzterTasterZustand = tasterZustand;
}
```

## 🔍 Code-Erklärung

### Wichtige Konzepte:

#### 1. Pull-Down-Widerstand
```cpp
pinMode(TASTER_PIN, INPUT);  // Ohne internen Pull-Up
```
- Externer 10kΩ zu GND
- Pin ist standardmäßig LOW
- Taster gedrückt → Pin wird HIGH

**Alternative: Interner Pull-Up** (Taster zu GND statt +5V):
```cpp
pinMode(TASTER_PIN, INPUT_PULLUP);  // Interner Pull-Up
// Jetzt: Nicht gedrückt = HIGH, Gedrückt = LOW
```

#### 2. Flanken-Erkennung
```cpp
if (tasterZustand == HIGH && letzterTasterZustand == LOW) {
    // Taster wurde GERADE gedrückt (steigende Flanke)
}
```
- Erkennt den Moment des Drückens
- Nicht: "Taster ist gedrückt"
- Sondern: "Taster wurde gerade gedrückt"

#### 3. Toggle (Umschalten)
```cpp
ledZustand = !ledZustand;  // Umkehren: true → false, false → true
```
- `!` ist der NOT-Operator
- Kehrt Boolean-Wert um

#### 4. Entprellung (Debouncing)
```cpp
if ((aktuelleZeit - letzteAenderungZeit) > ENTPRELLZEIT) {
```
- Taster "prellt" mechanisch beim Drücken
- Mehrere HIGH/LOW-Wechsel in kurzer Zeit
- Lösung: Mindestzeit zwischen erkannten Änderungen


## ❓ Häufige Fehler

### Taster funktioniert nicht / LED flackert
- ❌ **Problem:** Kein Pull-Down-Widerstand
- ✅ **Lösung:** 10kΩ von Pin zu GND oder `INPUT_PULLUP` verwenden

### LED schaltet mehrfach bei einem Druck
- ❌ **Problem:** Taster prellt mechanisch
- ✅ **Lösung:** Entprellung mit `delay(50)` oder Zeitprüfung

### LED reagiert verzögert
- ❌ **Problem:** `delay()` blockiert Programm
- ✅ **Lösung:** `millis()` statt `delay()` verwenden

### Pin "schwebt" (random HIGH/LOW)
- ❌ **Problem:** Floating Pin ohne Pull-Widerstand
- ✅ **Lösung:** Pull-Down (zu GND) oder Pull-Up (zu +5V) verwenden

## 📚 Begriffe erklärt

- **Pull-Down:** Widerstand von Pin zu GND → Pin standardmäßig LOW
- **Pull-Up:** Widerstand von Pin zu +5V → Pin standardmäßig HIGH
- **Floating Pin:** Pin ohne Pull-Widerstand → zufällige Werte
- **Entprellung (Debouncing):** Filtern mechanischer Kontaktschwingungen
- **Flanke:** Übergang von LOW zu HIGH (steigend) oder HIGH zu LOW (fallend)
- **Toggle:** Umschalten zwischen zwei Zuständen
- **millis():** Millisekunden seit Arduino-Start (läuft ~50 Tage)

## 🔌 Alternative Schaltungen

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
