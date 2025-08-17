#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
int Move = 5;
int select = 4;
int homeScreen = 1;
int spot = 1;


void setup() {
  pinMode(Move, INPUT);
  pinMode(select, INPUT);


  lcd.init();
  lcd.backlight();
  randomSeed(analogRead(0));
  spot = random(1, 4);
  lcd.setCursor(0, 0);
  lcd.print("Hide and seek");
  lcd.setCursor(0, 1);
  lcd.print("Look for the person");
  delay(1000);
  lcd.clear();


  showScreen(homeScreen);
}
void loop() {
  if (digitalRead(Move) == HIGH) {
    delay(100);
    homeScreen++;
    if (homeScreen > 3) homeScreen = 1;
    lcd.clear();
    showScreen(homeScreen);
  }
  if (digitalRead(select) == HIGH) {
    delay(300);
    lcd.clear();
    if (homeScreen == spot) {
      lcd.setCursor(0, 0);
      lcd.print("You found me!");
      lcd.setCursor(0, 1);
      lcd.print("Congrats! :)");
    } else {
      lcd.setCursor(0, 0);
      lcd.print("Wrong Room");
      lcd.setCursor(0, 1);
      lcd.print(":( Try again");
    }
    delay(2000);
    reset();
  }
}
void showScreen(int screenNum) {
  switch (screenNum) {
    case 1:
      lcd.setCursor(0, 0);
      lcd.print("Room 1");
      lcd.setCursor(0, 1);
      lcd.print("???");
      break;
    case 2:
      lcd.setCursor(0, 0);
      lcd.print("Room 2");
      lcd.setCursor(0, 1);
      lcd.print("OoOoohOo");
      break;
    case 3:
      lcd.setCursor(0, 0);
      lcd.print("Room 3");
      lcd.setCursor(0, 1);
      lcd.print("Knock me!");
      break;
    default:
      lcd.setCursor(0, 0);
      lcd.print("Not correct room");
      lcd.setCursor(0, 1);
      lcd.print(":(");
      break;
  }
}
void reset() {
  homeScreen = 1;
  spot = random(1, 4);


  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("New Game Started");
  lcd.setCursor(0, 1);
  lcd.print("Who is hiding");
  delay(1000);


  lcd.clear();
  showScreen(homeScreen);
}
