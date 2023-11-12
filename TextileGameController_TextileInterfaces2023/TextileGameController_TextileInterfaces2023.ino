/* Textile Interfaces 2023
  Kate Hartman
  Textile Game Controller 
  Pong game: https://editor.p5js.org/katehartman/full/yIL31Xkzm
  2 digital inputs and/or 2 analog inputs to activate 4 keyboard keys
  no resistors needed for digital inputs (see documentation for pinmode "INPUT_PULLUP")
  voltage divider circuit needed for analog inputs
  Based on Keyboard library examples
 */

#include "Keyboard.h"

#define DEBOUNCE 100  // delay for ensuring that the button presses do not overlap


// Variables that won't change

// Change to digital input pins that you are using
const int buttonPin1 = 2;
const int buttonPin2 = 3;

// Change to analog input pins that you are using
const int sensorPin1 = A0;
const int sensorPin2 = A1;


const int keyboardKey1 = KEY_UP_ARROW;
const int keyboardKey2 = KEY_DOWN_ARROW;

const int keyboardKey3 = KEY_LEFT_ARROW;
const int keyboardKey4 = KEY_RIGHT_ARROW;

// Change this to a threshold that makes sense for your sensor(s). Use Examples -> 01.Basics -> AnalogInputSerial to determine.

const int threshold = 600;

// Variables that will change

int buttonValue1 = 1;
int buttonValue2 = 1;

int sensorValue1 = 1;
int sensorValue2 = 1;


void setup() {

  // initialize  buttons' inputs:
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);

  // initialize serial
  Serial.begin(9600);


  Keyboard.begin();
}

void loop() {

  // read all button pins
  buttonValue1 = digitalRead(buttonPin1);
  buttonValue2 = digitalRead(buttonPin2);

  sensorValue1 = analogRead(sensorPin1);
  sensorValue2 = analogRead(sensorPin2);

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

// use analog sensor values to control keyboard
  if (sensorValue1 > threshold) {
    Keyboard.press(keyboardKey3);
    Serial.println("sensor 3 pressed");
    delay(50);
  }
  if (sensorValue2 > threshold) {
    Keyboard.press(keyboardKey4);
    Serial.println("sensor 4 pressed");
    delay(50);
  }

  Keyboard.releaseAll();


  delay(DEBOUNCE);  // delay in between reads for stability
}
