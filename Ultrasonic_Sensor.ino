#define echoPin 4
#define trigPin 5
int TIME ;
int Distance;
int buzzer = 3;


void setup() {
  // put your setup code here, to run once:
  pinMode(echoPin,INPUT);
  pinMode(trigPin,OUTPUT);
  pinMode(buzzer,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);

  TIME = pulseIn(echoPin,HIGH);
  Distance = TIME * 0.034/2;
  if (Distance > 5){
    digitalWrite(buzzer,HIGH);
  }else{
    digitalWrite(buzzer,LOW);
  }
  
  Serial.print("Distance : ");
  Serial.print(Distance);
  Serial.println("cm");
  

}
