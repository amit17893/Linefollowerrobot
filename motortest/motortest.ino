const int ML0=3,ML1=5,MR0=9,MR1=6;
void setup() {
  pinMode(ML0,OUTPUT);
  pinMode(ML1,OUTPUT);
  pinMode(MR0,OUTPUT);
  pinMode(MR1,OUTPUT);
  
  //  analogWrite(sl,255);//sets the motors speed   100
  //analogWrite(sr,255);//sets the motors speed   120
  // put your setup code here, to run once:

}

void loop() {
  //analogWrite(sl,100);//sets the motors speed   100
  //analogWrite(sr,140);//sets the motors speed   120
digitalWrite(MR0,HIGH);
  digitalWrite(MR1,LOW);
 digitalWrite(ML0,HIGH);
  digitalWrite(ML1,LOW);
  delay(10000);
     digitalWrite(MR1,HIGH);
  digitalWrite(MR0,LOW);
 digitalWrite(ML1,HIGH);
  digitalWrite(ML0,LOW);
  delay(10000);
    digitalWrite(MR0,HIGH);
  digitalWrite(MR1,LOW);
  digitalWrite(ML0,LOW);
  digitalWrite(ML1,HIGH);
}

