#define joyX A0
#define joyY A1
int x;
int y;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(joyX,INPUT);
  pinMode(joyY,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  x = analogRead(joyX);
  y = analogRead(joyY);
  Serial.print("X_cordinate :");
  Serial.println(x);
  delay(1000);
  Serial.print("Y_cordinate :");
  Serial.println(y);
  

}
