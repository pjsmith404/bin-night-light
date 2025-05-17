const int LED_RED = 12;
const int LED_YELLOW = 11;

// This'll be the 7 days between bin nights, but can be shrunk for testing.
const float DELAY_MILLIS = 10000;

void switchLight() {
  int red_pin_state = digitalRead(LED_RED);

  if (red_pin_state) {
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_YELLOW, HIGH);
  } else {
    digitalWrite(LED_YELLOW, LOW);
    digitalWrite(LED_RED, HIGH);
  }
};

void setup() {
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
}

void loop() {
  switchLight();
  // Delay is a blocking function, this will matter if we introduce a light switcher.
  delay(DELAY_MILLIS);
}

