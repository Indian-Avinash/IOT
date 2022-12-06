//#define IR 7
int relay;
#define Relay_1 3
//#define Relay_2 9
void setup() {
  // put your setup code here, to run once:
//  pinMode(IR,INPUT);
  pinMode(Relay_1,OUTPUT);
//  pinMode(Relay_2,OUTPUT);

}
void loop() {
  // put your main code here, to run repeatedly:
//  a = digitalRead(IR);
//  if(a==0){    
    digitalWrite(Relay_1,LOW);
    delay(1000);
    digitalWrite(Relay_1,LOW);
    delay(1000);
    digitalWrite(Relay_1,HIGH);
    delay(1000);
    digitalWrite(Relay_1,HIGH);
    delay(1000);
//  }
//  else{
//    digitalWrite(Relay_1,HIGH);
//    digitalWrite(Relay_2,HIGH);
//  }
}
