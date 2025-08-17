#include <Servo.h> // Import the Servo Library


Servo myServo; // Create a servo object


void setup() {
  myServo.attach(3); // Attach motor to pin 3
}


void loop() {
  myServo.write(105); 
  // Perfect speed for clinostat:
  // Not too fast (avoids centrifugal force)
  // Not too slow (ensures microgravity simulation)
}

