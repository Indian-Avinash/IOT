#include <EEPROM.h>
#define led 3
int Address = 0;
int Value = 0;
int a,Status;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  int d = EEPROM.read(Address);
  pinMode(led,OUTPUT); 
  Serial.print(d);
  digitalWrite(led,d);
  delay(3000);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led,HIGH);
  Status = 1;
  EEPROM.write(Address,Status);  
  delay(3000);
  digitalWrite(led,LOW);
  
  Status = 0; 
  EEPROM.write(Address,Status); 
  delay(3000);
}
