int PUL=7; //define Pulse pin
int DIR = 6; //define Direction pin
int ENA = 5; //define Enable Pin
#define DControl 8 //define Control Pin
int Cont = digitalRead(DControl);
int steps = 480;
void setup() {
pinMode (PUL, OUTPUT);
pinMode (DIR, OUTPUT);
pinMode (ENA, OUTPUT);
}

void loop() {
  
  Cont = digitalRead(DControl);
  while (Cont == HIGH) {
    Cont = digitalRead(DControl);   
    delay(1);
  }
  int j = 0;
  while (Cont == LOW) //Forward 5000 steps
    {
      digitalWrite(DIR, LOW);
      while (j < steps) //Backward 5000 steps
      {
      digitalWrite(PUL, HIGH);
      delayMicroseconds(100);
      digitalWrite(PUL, LOW);
      delayMicroseconds(100);
      j++;
     }
     Cont = digitalRead(DControl);
  }
  delay(1200);
  Cont = digitalRead(DControl);
  while (Cont == HIGH) {
  Cont = digitalRead(DControl);   
  delay(1);
  }
  Cont = digitalRead(DControl);
  j = 0;
  while (Cont == LOW) //Forward 5000 steps
    {     
      digitalWrite(DIR, HIGH);
      while (j < steps) //Backward 5000 steps
      {
      digitalWrite(PUL, HIGH);
      delayMicroseconds(100);
      digitalWrite(PUL, LOW);
      delayMicroseconds(100);
      j++;
      }
      Cont = digitalRead(DControl);
    }
   delay(1200);
}
