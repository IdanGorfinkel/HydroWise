// int valvePin = 2;
int ledPin = 13;
int delayValve = 1500;
int delayOpenValve = 500;
bool valveOpen = false;
int LastTime = 0;
int reasWaterSensor = A0;
int sensorValue;


void setup() {
  // put your setup code here, to run once:
  pinMode(valvePin,OUTPUT);
  // pinMode(ledPin,OUTPUT);
  Serial.begin(9600);
  // digitalWrite(valvePin, LOW);
  // digitalWrite(ledPin, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
valveOpen = false;
Serial.println(reasWaterSensor);
if (millis()-LastTime>=delayValve){
  sensorValue = analogRead(reasWaterSensor);
  if (sensorValue<450){
    valveOpen = true;
  }
  else{
    valveOpen = false;
  }
  LastTime = millis();
}

if(valveOpen){
  digitalWrite(valvePin,HIGH);
  delay(delayOpenValve);

  digitalWrite(valvePin, LOW);
  
}
else{
  digitalWrite(valvePin,LOW);
  digitalWrite(ledPin,LOW);
}

}
  


