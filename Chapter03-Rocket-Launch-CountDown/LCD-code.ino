#include <Adafruit_LiquidCrystal.h>


int seconds = 0;
int led = 2;
Adafruit_LiquidCrystal lcd(0);


void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  digitalWrite(led, HIGH);
}


void loop() {
  for (int i = 10; i <= 10; --i) {
    lcd.print(i);
    delay(600);
    lcd.clear();
    delay(600);
    if (i <= 0) {
      lcd.print("BLAST OFF");
    }
  }
}
