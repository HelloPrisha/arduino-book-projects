#include <LiquidCrystal_I2C.h>
#include <Servo.h>


LiquidCrystal_I2C lcd(0x27, 16, 2);


int sensorPin = A0;
const int trigPin = 7;
const int echoPin = 8;


Servo ServoMotor;


void setup() {
  lcd.init();
  lcd.backlight();
  ServoMotor.attach(3);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}


void loop() {
  int sensorValue = analogRead(sensorPin);


  float voltage = sensorValue * (5.0 / 1024.0);
  float temperatureC = (voltage - 0.5) * 100.0;
  float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;
  float cm = getDistance();


  Serial.println(cm);
  if (cm < 9) {
    ServoMotor.write(180); // Open
  } else {
    ServoMotor.write(0);   // Close
  }
  lcd.setCursor(0, 0);
  lcd.print("Celsius: ");
  lcd.print(temperatureC);
  lcd.setCursor(0, 1);
  lcd.print("Fahrenheit: ");
  lcd.print(temperatureF);
  delay(1000);
}


float getDistance() {
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);


  unsigned long duration = pulseIn(echoPin, HIGH);
  float distance = (duration * 0.0343) / 2;
  return distance;
}
