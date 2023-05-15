// pin setup
int valvePin = 2;
int waterSensor = 7;
int sevsorReader = A0;

// vlaues
int sensorValue;
int delayOpenValve = 1000;
int delayCloseValve = 1000;

void setup() {
  // put your setup code here, to run once:
  pinMode(valvePin,OUTPUT);
  pinMode(waterSensor,OUTPUT);
  Serial.begin(9600);
}

void loop() {

// taking sensor value
digitalWrite(waterSensor,HIGH);
sensorValue = analogRead(sevsorReader);
Serial.println(sensorValue);
digitalWrite(waterSensor,LOW);


if(sensorValue <600){
  // water not found valve opens
  digitalWrite(valvePin,HIGH);
  delay(delayOpenValve);
  // valve close after refilling
  digitalWrite(valvePin, LOW);
}

else{
    // water dectadet valve remain close
digitalWrite(valvePin, LOW);
delay(delayCloseValve); 
}

}

  
