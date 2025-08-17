#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
const int swL = 4;
const int swR = 5;
float multiplier = 1.0;
String unit = "cm";
float l = 0, w = 0;
const int trigPin = 9;
const int echoPin = 8;
int screen = 1;
float perUnitCost = 2.5;
byte Sqr[] = { B00110,B00001,B00010,B00111,B00000,B00000,B00000,B00000 };
byte Tick[] = { B00000,B00001,B00011,B10110,B11100,B01000,B00000,B00000 };
void setup() {
  pinMode(swL, INPUT);
  pinMode(swR, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  lcd.createChar(0, Sqr);
  lcd.createChar(1, Tick);
  lcd.init();
  lcd.backlight();
}
void loop() {
  switch (screen) {
    case 1: screen1(); break;
    case 2: screen2(); break;
    case 3: screen3(); break;
    case 4: screen4(); break;
  }


  if (digitalRead(swL) == HIGH) {
    if (screen == 1) {
      changeUnit();
    } else if (screen == 2 || screen == 3) {
      if (l == 0) l = getDistance();
      else if (w == 0) w = getDistance();
      recording();
      dataSaved();
    }
    delay(400);
  }


  if (digitalRead(swR) == HIGH) {
    screen = (screen == 4) ? 1 : screen + 1;
    lcd.clear();
    delay(400);
  }
}
void screen1() {
  lcd.setCursor(0, 0);
  lcd.print("Select Unit:");
  lcd.setCursor(0, 1);
  lcd.print(unit);
}
void screen2() {
  float cm = getDistance();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Distance:");
  lcd.setCursor(0, 1);
  lcd.print(cm * multiplier);
  lcd.print(unit);
  delay(500);
}
void screen3() {
  lcd.setCursor(0, 0);
  lcd.print("Length: ");
  lcd.print(l * multiplier);
  lcd.print(unit);


  lcd.setCursor(0, 1);
  lcd.print("Width: ");
  lcd.print(w * multiplier);
  lcd.print(unit);
}
void changeUnit() {
  if (unit == "cm") { unit = "in"; multiplier = 1 / 2.54; }
  else if (unit == "in") { unit = "ft"; multiplier = 1 / 30.48; }
  else if (unit == "ft") { unit = "cm"; multiplier = 1.0; }
}
float getDistance() {
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  unsigned long duration = pulseIn(echoPin, HIGH);
  return (duration * 0.0343) / 2;
}
void screen4() {
  float area = (l * multiplier) * (w * multiplier);
  lcd.setCursor(0, 0);
  lcd.print("Area: ");
  lcd.print(area);
  lcd.print(unit);
  lcd.write(0);


  lcd.setCursor(0, 1);
  lcd.print("Cost: $");
  lcd.print(area * perUnitCost);
}
void recording() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Recording");
  for (int j = 0; j < 4; j++) {
    delay(500);
    lcd.print(".");
  }
}
void dataSaved() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Data Saved ");
  lcd.write(1);
  lcd.setCursor(0, 1);
  lcd.print(getDistance());
  lcd.print(unit);
  delay(2000);
}
