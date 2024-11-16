// Defines
#define LED_PIN 13
#define BUTTON_PIN 9

#define DELAY_COUNT 5
const int LED_DELAY[] = {500,200,100,50,1000};
int index = 0;

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
    // Change delay index
    index++;
    // Reset index at the end of the array
    if(index >= DELAY_COUNT)
    {
      index = 0;
    }
  }
  // Otherwise do nothing
  else {
  }
    // Set LED value HIGH
  digitalWrite(LED_PIN,HIGH);
  // Wait
  delay(LED_DELAY[index]);
  // Set LED value LOW
  digitalWrite(LED_PIN,LOW);
  // Wait
  delay(LED_DELAY[index]);
}
