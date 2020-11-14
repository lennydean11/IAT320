///////////////////////////////////////////////////////////////////////////////
// Circuit Playground Slouch Detector v3
//
// Push button(s) to set a target angle.
// Compute current angle using accelerometer and compare
// to preset slouch angle. Sound alarm if slouching after
// a preset period of time.
//
// Author: Carter Nelson
// MIT License (https://opensource.org/licenses/MIT)
 
#include <Adafruit_CircuitPlayground.h>
 
#define SLOUCH_ANGLE        10.0      // allowable slouch angle (deg)
#define SLOUCH_TIME         3000      // allowable slouch time (secs)           
#define GRAVITY             9.80665   // standard gravity (m/s^s)
#define RAD2DEG             52.29578  // convert radians to degrees
 
float currentAngle;
float targetAngle;
unsigned long slouchStartTime;
bool slouching;
int count = 0;

 
///////////////////////////////////////////////////////////////////////////////
void setup() {
  // Initialize Circuit Playground
  CircuitPlayground.begin();
 
  // Initialize target angle to zero.
  targetAngle = 0;

}
 
///////////////////////////////////////////////////////////////////////////////
void loop() {
  Serial.print(count);
  
  // Compute current angle
  currentAngle = RAD2DEG * asin(-CircuitPlayground.motionZ() / GRAVITY);
 
  // Set target angle on button press
  if ((CircuitPlayground.leftButton()) || (CircuitPlayground.rightButton())) {
    targetAngle = currentAngle;
    CircuitPlayground.playTone(900,100);
    delay(100);
    CircuitPlayground.playTone(900,100);
    delay(100);
  }
  
  // Check for slouching
  if (currentAngle - targetAngle > SLOUCH_ANGLE) {
    if (!slouching) slouchStartTime = millis();
    slouching = true;
    CircuitPlayground.setPixelColor(1, 255, 0, 0);
      CircuitPlayground.setPixelColor(2, 255, 0, 0);
      CircuitPlayground.setPixelColor(3, 255, 0, 0);
      CircuitPlayground.setPixelColor(4, 255, 0, 0);
      CircuitPlayground.setPixelColor(5, 255, 0, 0);
      CircuitPlayground.setPixelColor(6, 255, 0, 0);
      CircuitPlayground.setPixelColor(7, 255, 0, 0);
      CircuitPlayground.setPixelColor(8, 255, 0, 0);
      CircuitPlayground.setPixelColor(9, 255, 0, 0);
    Serial.print(count);
  } else {
    slouching = false;
    CircuitPlayground.setPixelColor(1, 0, 255, 0);
    CircuitPlayground.setPixelColor(2, 0, 255, 0);
    CircuitPlayground.setPixelColor(3, 0, 255, 0);
    CircuitPlayground.setPixelColor(4, 0, 255, 0);
    CircuitPlayground.setPixelColor(5, 0, 255, 0);
    CircuitPlayground.setPixelColor(6, 0, 255, 0);
    CircuitPlayground.setPixelColor(7, 0, 255, 0);
    CircuitPlayground.setPixelColor(8, 0, 255, 0);
    CircuitPlayground.setPixelColor(9, 0, 255, 0);

  }

  // Function that counts slouches

 
  // If we are slouching
  if (slouching) {
    // Check how long we've been slouching
    if (millis() - slouchStartTime > SLOUCH_TIME) {
      // Play a tone
      CircuitPlayground.playTone(500,300);
      }
  }    
}
