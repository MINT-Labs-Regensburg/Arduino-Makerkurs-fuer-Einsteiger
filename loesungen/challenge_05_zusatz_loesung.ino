const int ledPin = 13;
const int buttonPin = 2;

bool ledState = false;
bool lastButtonState = HIGH;

void setup()
{
    pinMode(ledPin, OUTPUT);
    pinMode(buttonPin, INPUT_PULLUP);
}

void loop()
{
    bool buttonState = digitalRead(buttonPin);
    if (buttonState == LOW && lastButtonState == HIGH)
    {
        ledState = !ledState;
        digitalWrite(ledPin, ledState ? HIGH : LOW);
        delay(50); // Entprellung
    }
    lastButtonState = buttonState;
}
