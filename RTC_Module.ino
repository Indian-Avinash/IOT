/*RTC module with Arduino.
  created by the SriTu Tech team.
  Read the code below and use it for any of your creation
*/                                                                                    
#include <DS3231.h>
#include <RTClib.h>
#define Relay 3
int Year,Month,Day,Hour,Minute,Second;
 RTC_DS3231 rtc;
// DS3231 rtc(SDA, SCL);
 int a;
// Time t;
void setup() {
  rtc.begin();
  Serial.begin(9600);
  pinMode(Relay,OUTPUT);
  rtc.adjust(DateTime(2022,10,13,3,45,30)); //(12,00,00)
//  rtc.setDate(0, 0, 0); //(7,9,2020)
}
void loop() {
//  Serial.println(rtc.getTimeStr());

  DateTime now = rtc.now();
  Year=now.year();
  Month=now.month();
  Day=now.day();
  Hour=now.hour();
  Minute=now.minute();
  Second=now.second(); 
  Serial.println(String(Year)+":"+String(Month)+":"+String(Day)+":"+String(Hour)+":"+String(Minute)+":"+String(Second));
//  Serial.println(now.year());
//  Serial.println(now.month());
//  Serial.println(now.day());
//  Serial.println(now.hour());
//  Serial.println(now.minute());
//  Serial.println(now.second());
////  t.sec = 0;
//  Serial.print(now.year(), DEC);
//  Serial.print(t.sec);
  if (Hour == 10 && Minute == 50){
    digitalWrite(Relay,LOW);    
  }else{
    digitalWrite(Relay,HIGH);
  }
//  Serial.println("----");
//  delay(1000);

  
}
