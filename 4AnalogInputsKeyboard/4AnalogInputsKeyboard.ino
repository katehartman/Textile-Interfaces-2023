/* Textile Interfaces 2023
  Kate Hartman
  4 analog sensors to activate 4 keyboard keys
  be sure to use a voltage divider circuit for each sensor!
  Based on Keyboard library examples
 */

#include "Keyboard.h"

#define DEBOUNCE 100  // delay for ensuring that the sensor presses do not overlap


// Variables that won't change

const int sensorPin1 = A4;
const int sensorPin2 = A5;
const int sensorPin3 = A6;
const int sensorPin4 = A7;

const int keyboardKey1 = KEY_UP_ARROW;
const int keyboardKey2 = KEY_DOWN_ARROW;
const int keyboardKey3 = KEY_LEFT_ARROW;
const int keyboardKey4 = KEY_RIGHT_ARROW;

// Change this to a threshold that makes sense for your sensor(s). Use Examples -> 01.Basics -> AnalogInputSerial to determine.

const int threshold = 600;

// Variables that will change

int sensorValue1 = 1;
int sensorValue2 = 1;
int sensorValue3 = 1;
int sensorValue4 = 1;


void setup() {

  // initialize serial
  Serial.begin(9600);


  Keyboard.begin( );
}

void loop() {

  // read all sensor pins
  sensorValue1 = analogRead(sensorPin1);
  sensorValue2 = analogRead(sensorPin2);
  sensorValue3 = analogRead(sensorPin3);
  sensorValue4 = analogRead(sensorPin4);

  // use the sensor values to control  keyboard
  Serial.println(sensorValue1);
  if (sensorValue1 > threshold) {
    Keyboard.press(keyboardKey1);
    Serial.println("sensor 1 pressed");
    delay(50);
  }
  if (sensorValue2 > threshold) {
    Keyboard.press(keyboardKey2);
    Serial.println("sensor 2 pressed");
    delay(50);
  }
  if (sensorValue3 > threshold) {
    Keyboard.press(keyboardKey3);
    Serial.println("sensor 3 pressed");
    delay(50);
  }
  if (sensorValue4 > threshold) {
    Keyboard.press(keyboardKey4);
    Serial.println("sensor 4 pressed");
    delay(50);
  }

  Keyboard.releaseAll();
  delay(DEBOUNCE);  // delay in between reads for stability
}
