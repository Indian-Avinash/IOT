#include <SoftwareSerial.h>
SoftwareSerial gsm(7,8);//using 7,8 as tx,rx
#define echoPin 4
#define trigPin 5
#define Relay_1 3
int TIME ;
int Distance;
int buzzer = 3;
int sensorValue;
int sensorPin = 5;

void setup() {
  // Assinging the input and output 
  pinMode(echoPin,INPUT);
  pinMode(trigPin,OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(sensorPin,INPUT);
  pinMode(Relay_1,OUTPUT);
  Serial.begin(9600);
  gsm.begin(9600); //initializing the gsm 

}

void loop() {
  // put your main code here, to run repeatedly:
  //intializing the ultrasonic sensors
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW); 
  TIME = pulseIn(echoPin,HIGH);
  Distance = TIME * 0.034/2;
 //////////////intializing the mq135 pin
  sensorValue = analogRead(sensorPin);
 ///from here the main code works
 ///when the distance is less than 5cm the mq135 sensor starts working 
 ///when the analog value is greater than 600 and relay turns on 
 ///A call goes to the registered number  
  if (Distance < 5){   
     if (sensorValue > 600) {
    digitalWrite(buzzer,HIGH);
    delay(100);
    digitalWrite(buzzer,LOW);
    digitalWrite(Relay_1,LOW);
    gsm.println("ATD9390291253;"); ///insert your number here  
     }
  }else{
    digitalWrite(buzzer,LOW);
    digitalWrite(Relay_1,HIGH);
  } 
  sensorValue = analogRead(sensorPin);       // read analog input pin A5
  Serial.print("AirQuality Value: ");
  Serial.println(sensorValue, DEC);
  Serial.print("Distance : ");
  Serial.print(Distance);
  Serial.println("cm");
}
