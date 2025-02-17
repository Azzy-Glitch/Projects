#define in1 9
#define in2 3
#define in3 5
#define in4 6
#include <Servo.h>
Servo lservo;
Servo rservo;
Servo uservo;
int lpos = 180;
int rpos = 0 ;
int upos = 85;
int state;
int red=2;
int green=4;
int yellowr=7;
int white=8;
int yellowl=13;
void setup() 
{
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  Serial.begin(9600);
  lservo.attach(10);
  rservo.attach(11);
  uservo.attach(12);
}
void loop() 
{
  if (Serial.available() > 0) {
    state = Serial.read();
    switch (state) 
    {
      case 'F': //moves forward 
        digitalWrite(green, HIGH);
        digitalWrite(yellowr, LOW);
        digitalWrite(white, LOW);
        digitalWrite(red, LOW);
        digitalWrite(yellowl, LOW);
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);
        break;
      case 'B': //moves backward
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);
        break;
      case 'L': //starts rotating counterclockwise
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);
        break;
      case 'R': //starts rotating clockwise
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);
        break;
      case 'S': //stops moving
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, LOW);
        break;
      case 'A': //left arm goes down      
        for( ; lpos>=90 ; lpos--)
        {
          lservo.write(lpos);
          delay(15);
        }
        break;
      case 'C': //left arm goes up
        for( ; lpos<=180 ; lpos++)
        {
          lservo.write(lpos);
          delay(15);
        }
        break;
      case 'D': //right arm goes up      
        for(; rpos<=90 ; rpos++)
        {
          rservo.write(rpos);
          delay(15);
        }        
        break;
      case 'E': //right arm goes down
        for(; rpos>=0 ; rpos--)
        {
          rservo.write(rpos);
          delay(15);
        }
        break;
      case 'G': //looks right
        for(; upos>=0 ; upos--)
        {
          uservo.write(upos);
          delay(15);
        }        
        delay(2000);
        for(; upos<=85 ; upos++) //returns to straight face
        {
          uservo.write(upos);
          delay(15);
        }
        break;        
      case 'I': //looks left);
        for(; upos<=180 ; upos++)
        {
          uservo.write(upos);
          delay(15);
        }        
        delay(2000);
        for(; upos>=85 ; upos--) //returns to straight face
        {
          uservo.write(upos);
          delay(15);
        }
        break;
      case 'H': //moves forward for 1.5 seconds
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);
        delay(1500);
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, LOW);
        break;
      case 'J': //turn right
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);
        delay(430);
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, LOW);
        break;
      case 'K': //turn left
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);
        delay(430);
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, LOW);
        break;
      case 'M': //face backwards
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);
        delay(820);
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, LOW);
        break;
      case 'N': //rotate clockwise
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);
        delay(1640);
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, LOW);
        break;
      case 'O': //rotate counterclockwise
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);
        delay(1640);
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, LOW);
        break;
}
}
}

