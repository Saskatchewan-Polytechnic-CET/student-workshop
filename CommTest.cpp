// Defines
#define BUTTON_PIN 9
#define NUMBER_OF_QUESTIONS 4

// Pin mapping
const int answer_pins[] = {13,12,11,10};

// Initialization t = 0
void setup() {
  // Setup pins
  for(int i = 0; i < NUMBER_OF_QUESTIONS; i++) {
    pinMode(answer_pins[i], OUTPUT);
  }
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

// Runtime t > 0
void loop() {
  // If button pressed
  if (digitalRead(BUTTON_PIN) == LOW) {
    for(int i = 0; i < NUMBER_OF_QUESTIONS; i++) {
      // Turn off LED
      digitalWrite(answer_pins[i], LOW);
    }
  }
  // Otherwise keep LEDs HIGH
  else {
    for(int i = 0; i < NUMBER_OF_QUESTIONS; i++) {
      digitalWrite(answer_pins[i], HIGH);
    }
  }
}