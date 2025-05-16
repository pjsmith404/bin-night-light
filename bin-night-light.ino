const int RED_BIN_PIN = 12;
const int YELLOW_BIN_PIN = 11;

void setup() {
  pinMode(RED_BIN_PIN, OUTPUT);
  pinMode(YELLOW_BIN_PIN, OUTPUT);
}

void loop() {
  digitalWrite(RED_BIN_PIN, HIGH);
  digitalWrite(YELLOW_BIN_PIN, HIGH);
  delay(1000);
  digitalWrite(RED_BIN_PIN, LOW);
  digitalWrite(YELLOW_BIN_PIN, LOW);
  delay(1000);
}

