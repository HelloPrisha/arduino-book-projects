const int trigPin = 10; 
const int echoPin = 9;
int led = 5;


void setup() {
  pinMode(8, OUTPUT); // Buzzer 1
  pinMode(led, OUTPUT); // LED
  pinMode(6, OUTPUT); // Buzzer 2
  pinMode(7, OUTPUT); // Buzzer 3
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}


void loop() {
  if (getDistance() <= 50) { // Trigger alarm if object is within 50 cm
    // Alarm pattern for buzzer 1
    for (float f = 1000; f < 2200; f += 20) {
      tone(8, f);
      delay(10);
    }
    for (float f = 2200; f > 1000; f -= 20) {
      tone(8, f);
      delay(10);
    }
    noTone(8);
    delay(50);


    // Alarm pattern for buzzer 2
    for (float f = 2000; f > 500; f *= 0.97) {
      tone(7, f);
      delay(10);
    }
    noTone(7);
    delay(50);


    // Alarm pattern for buzzer 3
    tone(6, 2200, 250);
    delay(250);
    noTone(6);
    delay(50);


    // LED blinking alert
    for (int i = 0; i < 3; i++) {
      digitalWrite(led, HIGH);
      delay(50);
      digitalWrite(led, LOW);
      delay(50);
    }
  }
}
float getDistance() {
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  unsigned long duration = pulseIn(echoPin, HIGH);
  return (duration * 0.0343) / 2; // Convert to cm
}
