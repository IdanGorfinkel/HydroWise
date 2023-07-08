#include <Servo.h>
int readTurbine =A0;
int servoPin = 9; 
Servo myServo;
int readV;
float deg ;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myServo.attach(servoPin);
  pinMode(readTurbine,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  readV = analogRead(readTurbine);
  Serial.println(readV);
  deg = (1023-readV)/5.683;
  // Serial.println(deg);
  myServo.write(deg);
  
}
