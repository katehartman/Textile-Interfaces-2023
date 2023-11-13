/* Textile Interfaces 2023
  Kate Hartman
  4 digital inputs to activate 4 keyboard keys
  no resistors needed (see documentation for pinmode "INPUT_PULLUP")
  Based on Keyboard library examples
 */

#include "Keyboard.h"

#define DEBOUNCE 100  // delay for ensuring that the button presses do not overlap


// Variables that won't change

const int buttonPin1 = 1;  // CPX A4
const int buttonPin2 = 0;  // CPX A5
const int buttonPin3 = 2;  // CPX A6
const int buttonPin4 = 3;  // CPX A7

const int keyboardKey1 = KEY_UP_ARROW;
const int keyboardKey2 = KEY_DOWN_ARROW;
const int keyboardKey3 = KEY_LEFT_ARROW;
const int keyboardKey4 = KEY_RIGHT_ARROW;

// Variables that will change

int buttonValue1 = 1;
int buttonValue2 = 1;
int buttonValue3 = 1;
int buttonValue4 = 1;


void setup() {

  // initialize the buttons' inputs:
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);
  pinMode(buttonPin4, INPUT_PULLUP);

  // initialize serial
  Serial.begin(9600);


  Keyboard.begin();
}

void loop() {

  // read all button pins
  buttonValue1 = digitalRead(buttonPin1);
  buttonValue2 = digitalRead(buttonPin2);
  buttonValue3 = digitalRead(buttonPin3);
  buttonValue4 = digitalRead(buttonPin4);

  // use the button values to control  keyboard
  if (buttonValue1 == LOW) {
    Keyboard.press(keyboardKey1);
    delay(50);
    Serial.println("Button 1 pressed");
  }
  if (buttonValue2 == LOW) {
    Keyboard.press(keyboardKey2);
    delay(50);
    Serial.println("Button 2 pressed");
  }
  if (buttonValue3 == LOW) {
    Keyboard.press(keyboardKey3);
    delay(50);
    Serial.println("Button 3 pressed");
  }
  if (buttonValue4 == LOW) {
    Keyboard.press(keyboardKey4);
    delay(50);
    Serial.println("Button 4 pressed");
  }
  Keyboard.releaseAll();


  delay(DEBOUNCE);  // delay in between reads for stability
}
