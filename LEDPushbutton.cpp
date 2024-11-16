// Defines
#define LED_PIN 13
#define BUTTON_PIN 9

// Initialization t = 0
void setup() {
  // Setup pins
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

// Runtime t > 0
void loop() {
  // If button pressed
  if (digitalRead(BUTTON_PIN) == LOW) {
    // Set LED value HIGH
    digitalWrite(LED_PIN, HIGH);
  }
  // Otherwise keep LED LOW
  else {
    digitalWrite(LED_PIN, LOW);
  }
}
