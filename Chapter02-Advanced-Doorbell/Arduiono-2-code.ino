int buzz = 5;   // Buzzer pin
int button = 6; // Button pin


void setup() {
  pinMode(button, INPUT_PULLUP); // Button input with pull-up resistor
  pinMode(buzz, OUTPUT);         // Buzzer output
  Serial.begin(9600);            // Debugging
}


void loop() {
  if (digitalRead(button) == LOW) { // Button pressed
    tone(buzz, 660); delay(140);
    tone(buzz, 550); delay(140);
    tone(buzz, 440);
    noTone(buzz);
  } else {
    noTone(buzz); // Button not pressed
  }
}
