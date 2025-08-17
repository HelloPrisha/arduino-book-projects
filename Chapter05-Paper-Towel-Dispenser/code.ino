#include <Servo.h> // Include the Servo Library


const int sw = 2;
const int trigPin = 6; 
const int echoPin = 5;
Servo ServoMotor; // Create servo object
void setup() {
  ServoMotor.attach(3); // Motor pin
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(sw, INPUT);
}
void loop() {
  float cm = getDistance();
  Serial.print(cm);
  delay(50);


  // Button activation
  if (digitalRead(sw) == HIGH) {
    ServoMotor.write(360);
    delay(1000);
    ServoMotor.write(0);
  }
  // Sensor activation
  if (cm < 30) {
    ServoMotor.write(360);
    delay(1000);
    ServoMotor.write(0);
  }
}
float getDistance() {
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  unsigned long duration = pulseIn(echoPin, HIGH);
  float distance = (duration * 0.0343) / 2;
  return distance;
}
