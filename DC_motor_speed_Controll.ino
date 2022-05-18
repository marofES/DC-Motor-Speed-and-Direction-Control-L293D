const int pot_pin = A0;
const int clockWise = 13;
const int antiClockWise = 12;
const int pin1 = 11;
const int pin2 = 10;

int potValue = 0;
int motorValue = 0;
int clockWiseState = 0;
int antiClockWiseState = 0;

void setup() {
 pinMode(clockWise,INPUT_PULLUP);
 pinMode(antiClockWise,INPUT_PULLUP);
 pinMode(pin1,OUTPUT);
 pinMode(pin2,OUTPUT);

}

void loop() {
  potValue = analogRead(pot_pin);

  motorValue = map(potValue,0,1023,0,255);

  clockWiseState = digitalRead(clockWise);
  antiClockWiseState = digitalRead(antiClockWise);

  if(clockWiseState == LOW)
  {
    analogWrite(pin1,motorValue);
    digitalWrite(pin2,LOW);
  }
  else if(antiClockWiseState == LOW)
  {
    analogWrite(pin2,motorValue);
    digitalWrite(pin1,LOW);
  }
  else
  {
    digitalWrite(pin1,LOW);
    digitalWrite(pin2,LOW);
  }  

}
