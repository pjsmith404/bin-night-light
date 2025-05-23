const int LED_RED = 12;
const int LED_YELLOW = 11;
const int BUTTON = 7;

// This'll be the 7 days between bin nights, but can be shrunk for testing.
const long DELAY_INTERVAL = 604800000;

// Initialise button state for tracking in the loop.
int buttonState = 0;
int lastButtonState = 0;

unsigned long previousMillis = 0;

void switchLight() {
  int red_pin_state = digitalRead(LED_RED);

  if (red_pin_state) {
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_YELLOW, HIGH);
  } else {
    digitalWrite(LED_RED, HIGH);
    digitalWrite(LED_YELLOW, LOW);
  }
}

void buttonSwitch() {
  buttonState = digitalRead(BUTTON);

  if (buttonState != lastButtonState) {
    if (buttonState) {
      switchLight();
    }
    delay(50);
  }

  lastButtonState = buttonState;
}

void intervalSwitch() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= DELAY_INTERVAL) {
    previousMillis = currentMillis;
    switchLight();
  }
}

void setup() {
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(BUTTON, INPUT);

  switchLight(); // Ensures the LEDs start switched on.
}

void loop() {
  buttonSwitch();
  intervalSwitch();
}

