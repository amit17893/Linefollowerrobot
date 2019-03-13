const int sp1=A0,sp2=A1,sp3=5,sp4=4,sp5=3,sp6=2,sp7=A2,sp8=A4;
int s1,s2,s3,s4,s5,s6,s7,s8;

void setup() {
  pinMode(sp1,INPUT);
  pinMode(sp2,INPUT);
  pinMode(sp3,INPUT);
  pinMode(sp4,INPUT);
  pinMode(sp5,INPUT);
  pinMode(sp6,INPUT);
  pinMode(sp7,INPUT);
  pinMode(sp8,INPUT);
  Serial.begin(9600);
    // put your setup code here, to run once:

}

void loop() {
  
  s1=digitalRead(sp1);
  s2=digitalRead(sp2);
  s3=digitalRead(sp3);
  s4=digitalRead(sp4);
  s5=digitalRead(sp5);
  s6=digitalRead(sp6);
  s7=digitalRead(sp7);
  s8=digitalRead(sp8);
  Serial.println(s1);
  Serial.println(s2);
  Serial.println(s3);
  Serial.println(s4);
  Serial.println(s5);
  Serial.println(s6);
  Serial.println(s7);
  Serial.println(s8);
  delay(1000);
  Serial.println("value");
  // put your main code here, to run repeatedly:

}
