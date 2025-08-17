int a=11, b=9, c=6, d=4, e=3, f=2, g=5, h=7, i=10, j=12, k=13, l=8;


void setup() {
  pinMode(a, OUTPUT); pinMode(b, OUTPUT); pinMode(c, OUTPUT); pinMode(d, OUTPUT);
  pinMode(e, OUTPUT); pinMode(f, OUTPUT); pinMode(g, OUTPUT); pinMode(h, OUTPUT);
  pinMode(i, OUTPUT); pinMode(j, OUTPUT); pinMode(k, OUTPUT); pinMode(l, OUTPUT);
}


void loop() {
  ZERO(); delay(600); AllLow(); delay(600);
  NINE(); delay(600); AllLow(); delay(600);
  EIGHT(); delay(600); AllLow(); delay(600);
  SEVEN(); delay(600); AllLow(); delay(600);
  SIX(); delay(600); AllLow(); delay(600);
  FIVE(); delay(600); AllLow(); delay(600);
  FOUR(); delay(600); AllLow(); delay(600);
  THREE(); delay(600); AllLow(); delay(600);
  TWO(); delay(600); AllLow(); delay(600);
  ONE(); delay(600); AllLow(); delay(600);
  BLINK();
}


// --- Utility Functions ---
void AllLow() { digitalWrite(a,LOW); digitalWrite(b,LOW); digitalWrite(c,LOW); digitalWrite(d,LOW);
  digitalWrite(e,LOW); digitalWrite(f,LOW); digitalWrite(g,LOW); digitalWrite(h,LOW);
  digitalWrite(i,LOW); digitalWrite(j,LOW); digitalWrite(k,LOW); digitalWrite(l,LOW); }


void ZERO() { AllLow(); digitalWrite(a,HIGH); digitalWrite(b,HIGH); digitalWrite(c,HIGH);
  digitalWrite(d,HIGH); digitalWrite(e,HIGH); digitalWrite(f,HIGH); digitalWrite(g,HIGH);
  digitalWrite(h,HIGH); digitalWrite(i,HIGH); digitalWrite(j,HIGH); digitalWrite(k,HIGH); }


void ONE() { AllLow(); digitalWrite(a,HIGH); digitalWrite(b,HIGH); digitalWrite(c,HIGH); digitalWrite(d,HIGH); }


void TWO() { AllLow(); digitalWrite(c,HIGH); digitalWrite(d,HIGH); digitalWrite(e,HIGH); digitalWrite(f,HIGH);
  digitalWrite(i,HIGH); digitalWrite(j,HIGH); digitalWrite(l,HIGH); digitalWrite(k,HIGH); }


void THREE() { AllLow(); digitalWrite(a,HIGH); digitalWrite(b,HIGH); digitalWrite(c,HIGH); digitalWrite(d,HIGH);
  digitalWrite(e,HIGH); digitalWrite(f,HIGH); digitalWrite(h,HIGH); digitalWrite(j,HIGH); digitalWrite(l,HIGH); digitalWrite(k,HIGH); }


void FOUR() { AllLow(); digitalWrite(a,HIGH); digitalWrite(b,HIGH); digitalWrite(c,HIGH); digitalWrite(d,HIGH);
  digitalWrite(f,HIGH); digitalWrite(g,HIGH); digitalWrite(h,HIGH); digitalWrite(l,HIGH); }


void FIVE() { AllLow(); digitalWrite(a,HIGH); digitalWrite(b,HIGH); digitalWrite(d,HIGH); digitalWrite(e,HIGH);
  digitalWrite(f,HIGH); digitalWrite(g,HIGH); digitalWrite(h,HIGH); digitalWrite(j,HIGH); digitalWrite(l,HIGH); digitalWrite(k,HIGH); }


void SIX() { AllLow(); digitalWrite(a,HIGH); digitalWrite(b,HIGH); digitalWrite(d,HIGH); digitalWrite(e,HIGH);
  digitalWrite(f,HIGH); digitalWrite(g,HIGH); digitalWrite(h,HIGH); digitalWrite(i,HIGH); digitalWrite(j,HIGH); digitalWrite(l,HIGH); digitalWrite(k,HIGH); }


void SEVEN() { AllLow(); digitalWrite(a,HIGH); digitalWrite(b,HIGH); digitalWrite(c,HIGH); digitalWrite(d,HIGH); digitalWrite(e,HIGH); digitalWrite(f,HIGH); }


void EIGHT() { AllLow(); digitalWrite(a,HIGH); digitalWrite(b,HIGH); digitalWrite(c,HIGH); digitalWrite(d,HIGH); digitalWrite(e,HIGH); digitalWrite(f,HIGH);
  digitalWrite(g,HIGH); digitalWrite(h,HIGH); digitalWrite(i,HIGH); digitalWrite(j,HIGH); digitalWrite(l,HIGH); digitalWrite(k,HIGH); }


void NINE() { AllLow(); digitalWrite(a,HIGH); digitalWrite(b,HIGH); digitalWrite(c,HIGH); digitalWrite(d,HIGH); digitalWrite(e,HIGH);
  digitalWrite(f,HIGH); digitalWrite(g,HIGH); digitalWrite(h,HIGH); digitalWrite(l,HIGH); }


void allHIGH() { digitalWrite(a,HIGH); digitalWrite(b,HIGH); digitalWrite(c,HIGH); digitalWrite(d,HIGH);
  digitalWrite(e,HIGH); digitalWrite(f,HIGH); digitalWrite(g,HIGH); digitalWrite(h,HIGH); digitalWrite(i,HIGH);
  digitalWrite(j,HIGH); digitalWrite(l,HIGH); digitalWrite(k,HIGH); }


void BLINK() { allHIGH(); delay(500); AllLow(); allHIGH(); delay(500); AllLow();
  allHIGH(); delay(500); AllLow(); allHIGH(); delay(500); AllLow(); allHIGH(); delay(500); AllLow(); }
