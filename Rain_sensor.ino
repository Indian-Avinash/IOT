#define rain 8
int a;
void setup() {
  // put your setup code here, to run once:
  pinMode(rain,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
   a = digitalRead(rain);
   Serial.println(a);
  

}
