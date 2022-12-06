#define x 2
#define y 3
#define z 4
int a;
int b;
int c;
void setup() {
  // put your setup code here, to run once:
  pinMode(x,INPUT);
  pinMode(y,INPUT);
  pinMode(z,INPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("X-axis");
  a = analogRead(x);
  Serial.println(a);
  delay(1000);
  Serial.println("Y-axis");
  b = analogRead(y);
  Serial.println(b);
  delay(1000);
  Serial.println("Z-axis");
  c = analogRead(z);
  Serial.println(c);
  delay(1000);
  

}
