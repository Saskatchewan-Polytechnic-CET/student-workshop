// Custom HID device
#include <Keyboard.h>

// Declare LED pins
#define LED1_PIN 20
#define LED2_PIN 21

//Declare button pins
#define BTN1_PIN 18 
#define BTN2_PIN 19        

// Payload prototypes
bool _payload1 = false;
void payload1();
bool _payload2 = false;
void payload2();

// Init t = 0
void setup() {
  // Set LEDs as output
  pinMode(LED1_PIN, OUTPUT); // Set LED 1 as an output
  pinMode(LED2_PIN, OUTPUT); // Set LED 2 as an output

  // Declare the buttons as input_pullup
  pinMode(BTN1_PIN, INPUT_PULLUP); 
  pinMode(BTN2_PIN, INPUT_PULLUP);  

  // Initialize keyboard module 
  Keyboard.begin();
}

// Poll t > 0
void loop() {
  // Check the state of the button
  int button1State = digitalRead(BTN1_PIN);
  
  if (button1State == HIGH) {
    _payload1=false;
    digitalWrite(LED1_PIN, LOW); // set the LED off
    delay(50);
  }
  else if (button1State == LOW && !_payload1) {
    digitalWrite(LED1_PIN, HIGH); // set the LED on
    delay(50);
    _payload1=true;
    payload2();
    digitalWrite(LED1_PIN, LOW); // set the LED off
  }

  // Check the state of the button
  int button2State = digitalRead(BTN2_PIN);
  
  if (button2State == HIGH) {
    _payload2 = false;
    digitalWrite(LED2_PIN, LOW); // set the LED off
    delay(50);
  }
  else if (button2State == LOW && !_payload2) {
    digitalWrite(LED2_PIN, HIGH); // set the LED on
    payload2();
    digitalWrite(LED2_PIN, LOW); // set the LED off
    delay(50);
  }
}

// Keyboard strokes
void payload1()
{
  // Start Keyboard and Mouse
  //AbsoluteMouse.begin();
  Keyboard.begin();

  // Start Payload
  delay(3000);

  // Implement keystrokes as per:
  // https://docs.arduino.cc/language-reference/en/functions/usb/Keyboard/

  // End Payload

  // Stop Keyboard and Mouse
  Keyboard.end();
}

// Keyboard strokes
void payload2()
{
  // Start Keyboard and Mouse
  //AbsoluteMouse.begin();
  Keyboard.begin();

  // Start Payload
  delay(3000);

  // Implement keystrokes as per:
  // https://docs.arduino.cc/language-reference/en/functions/usb/Keyboard/

  // End Payload

  // Stop Keyboard and Mouse
  Keyboard.end();
}