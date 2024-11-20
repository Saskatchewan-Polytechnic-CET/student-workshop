// Defines
#define BUTTON_PIN 9
#define NUMBER_OF_QUESTIONS 4
#define DELAY_BETWEEN_ANSWERS 2500 // 5 seconds between answers
#define LED_DELAY 150

// Answers to questions
#define YES HIGH
#define NO LOW

// Responses
int answers[] =
{
  YES, // Question 1
  YES, // Question 2
  YES, // Question 3
  YES  // Question 4
};

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
      // Double blink LED
      digitalWrite(answer_pins[i], HIGH);
      delay(LED_DELAY);
      digitalWrite(answer_pins[i], LOW);
      delay(LED_DELAY);
      digitalWrite(answer_pins[i], HIGH);
      delay(LED_DELAY);
      digitalWrite(answer_pins[i], LOW);
      delay(LED_DELAY);

      // Pause in between
      delay(LED_DELAY*4);

      // Set LED value HIGH
      digitalWrite(answer_pins[i], answers[i]);
      delay(DELAY_BETWEEN_ANSWERS);
      // Return LED LOW
      digitalWrite(answer_pins[i], LOW);
    }
  }
  // Otherwise keep LEDs LOW
  else {
    for(int i = 0; i < NUMBER_OF_QUESTIONS; i++) {
      digitalWrite(answer_pins[i], LOW);
    }
  }
}