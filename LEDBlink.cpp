// Defines
#define LED_PIN 13
#define LED_DELAY 500

// Initialization t = 0
void setup() {
  // Setup pins
  pinMode(LED_PIN, OUTPUT);
}

// Runtime t > 0
void loop() {
  // Set LED value HIGH
  digitalWrite(LED_PIN, HIGH);
  // Wait
  delay(LED_DELAY);
  // Set LED value LOW
  digitalWrite(LED_PIN, LOW);
  // Wait
  delay(LED_DELAY);
}
