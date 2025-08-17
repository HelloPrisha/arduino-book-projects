#include <IRremote.hpp>
#include <Servo.h> 
// Libraries = Predefined sets of code that can shorten development
#define USE_IRREMOTE_HPP_AS_PLAIN_INCLUDE


int led = 3; // Variable assignment
Servo myServo; // Making the object Servo


void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT); // Assign pin for LED
  IrReceiver.begin(4);  // IR receiver on pin 4
  myServo.attach(5);    // Servo motor on pin 5
  myServo.write(0);     // Initial servo position
}


void loop() {
  while (IrReceiver.decode() == 0) {
    // Waiting for IR signal
  }
  if (IrReceiver.decode()) {
    unsigned long code = IrReceiver.decodedIRData.decodedRawData;
    Serial.println(code);
    switch (code) {
      case 4010852096:
        digitalWrite(led, HIGH);
        myServo.write(90);
        delay(1000);
        digitalWrite(led, LOW);
        break;
    }
  }
}
