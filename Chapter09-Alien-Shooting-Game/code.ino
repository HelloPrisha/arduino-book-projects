#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27, 16, 2);
int swMove = 4;  // Right button to move rocket
int swFire = 5;  // Left button to fire
int rocketPos = 0;
int alienPos = 0;


byte rocketChar[] = {
  B00100,
  B01110,
  B10101,
  B11111,
  B10101,
  B01110,
  B00100,
  B01010
};
byte alienChar[] = {
  B11111,
  B11111,
  B10101,
  B01110,
  B10001,
  B11111,
  B01010,
  B11011
};
byte explosionChar[] = {
  B00000,
  B01010,
  B01010,
  B00000,
  B10001,
  B10001,
  B01110,
  B00000
};
byte sadChar[] = {
  B00000,
  B01010,
  B01010,
  B00000,
  B01110,
  B10001,
  B00000,
  B00000
};
void setup() {
  pinMode(swMove, INPUT);
  pinMode(swFire, INPUT);
  lcd.init();
  lcd.backlight();
  randomSeed(analogRead(0));


  lcd.createChar(0, rocketChar);
  lcd.createChar(1, alienChar);
  lcd.createChar(2, explosionChar);
  lcd.createChar(3, sadChar);


  lcd.setCursor(0, 0);
  lcd.print("  GAME STARTING");
  delay(1500);
  lcd.clear();
}
void loop() {
  rocketPos = 0;
  alienPos = 0;
  for (int i = 0; i < 16; i++) {
    lcd.clear();
    lcd.setCursor(alienPos, 0);
    lcd.write(byte(1)); // Alien
    lcd.setCursor(rocketPos, 1);
    lcd.write(byte(0)); // Rocket


    for (int j = 0; j < 6; j++) {
      delay(50);
      if (digitalRead(swMove) == HIGH) {
        lcd.setCursor(rocketPos, 1);
        lcd.print(" ");
        rocketPos++;
        if (rocketPos > 15) rocketPos = 0;
        lcd.setCursor(rocketPos, 1);
        lcd.write(byte(0));
        delay(200);
      }
      if (digitalRead(swFire) == HIGH) {
        if (rocketPos == alienPos) {
          showHit();
        } else {
          showMiss();
        }
        return;
      }
    }
    alienPos++;
    if (alienPos > 15) {
      return;
    }
  }
}
void showHit() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("  DIRECT HIT!");
  lcd.setCursor(7, 1);
  lcd.write(byte(2)); // Explosion
  delay(1000);
}
void showMiss() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("  SHOT MISSED!");
  lcd.setCursor(7, 1);
  lcd.write(byte(3)); // Sad face
  delay(2000);
}
