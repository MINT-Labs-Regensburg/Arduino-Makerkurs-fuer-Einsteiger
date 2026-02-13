const int RED_PIN = 8;
const int YELLOW_PIN = 9;
const int GREEN_PIN = 10;

const unsigned long GREEN_TIME = 5000;   // 5s
const unsigned long YELLOW_TIME = 2000;  // 2s
const unsigned long RED_TIME = 5000;     // 5s

void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);

  digitalWrite(RED_PIN, LOW);
  digitalWrite(YELLOW_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
}

void loop() {
  // Grün
  digitalWrite(GREEN_PIN, HIGH);
  digitalWrite(YELLOW_PIN, LOW);
  digitalWrite(RED_PIN, LOW);
  delay(GREEN_TIME);

  // Gelb
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(YELLOW_PIN, HIGH);
  digitalWrite(RED_PIN, LOW);
  delay(YELLOW_TIME);

  // Rot
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(YELLOW_PIN, LOW);
  digitalWrite(RED_PIN, HIGH);
  delay(RED_TIME);
}
