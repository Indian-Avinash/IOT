#include <SoftwareSerial.h>
SoftwareSerial gsm(7,8);
#define ir 3
int a;
void setup() {
Serial.begin(9600);
gsm.begin(9600);
pinMode(ir,INPUT);
}
//void test(){
//    while (gsm.available()>0)
//   Serial.write(char(gsm.read()));
//}
void loop() {
  a = digitalRead(ir);
  if (a==0){
  delay(5000);
  gsm.println("AT");
  delay(1000);
//  test();
  gsm.println("AT+CMGF=1");
  delay(1000);
//  test();
//  gsm.println("ATD9390291253;");
    gsm.println("AT+CMGS=\"+919390291253\"\r");
    delay(1000);
//    test();
  gsm.println("i ma using software serial library");
    delay(1000);
  gsm.println(char(26));
  delay(1000);
  Serial.println("SMS Sent");
  delay(1000);
  }else if (a==1){
    
    Serial.println("No Danger");
    
    
  }
  



}
