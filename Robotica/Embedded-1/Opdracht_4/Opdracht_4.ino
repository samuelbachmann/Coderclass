int E1 = 6;
int M1 = 7;
int E2 = 5;
int M2 = 4;
int pin11 = 11;
int pin10 = 10;
int pin9 = 9;

void setup()
{
    pinMode(M1, OUTPUT);
    pinMode(M2, OUTPUT);
}

void loop()
{
  int value;
  for(value = 100 ; value <= 255; value+=5)
  {
    digitalWrite(M1,LOW);
    digitalWrite(M2,HIGH);
    analogWrite(E1, 100);   //PWM Speed Control
    analogWrite(E2, 100);   //PWM Speed Control
    delay(30);
  }
}
