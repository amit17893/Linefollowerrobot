const int ML0=8,ML1=9,MR0=12,MR1=13,sl=11,sr=10;
const int sp1=A0,sp2=A1,sp3=5,sp4=4,sp5=3,sp6=2,sp7=A2,sp8=A3;
int s1,s2,s3,s4,s5,s6,s7,s8;
void setup() {
   pinMode(ML0,OUTPUT);
  pinMode(ML1,OUTPUT);
  pinMode(MR0,OUTPUT);
  pinMode(MR1,OUTPUT);
  pinMode(sl,OUTPUT);
  pinMode(sr,OUTPUT);
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
  // put your main code here, to run repeatedly:
   analogWrite(sl,50+10);//sets the motors speed   100
  analogWrite(sr,60+12);//sets the motors speed   120
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
  if(s1==1&&s2==1&&s3==1&&s4==0&&s5==0&&s6==1&&s7==1&&s8==1)
      forward();
  else if(s1==1&&s2==1&&s3==0&&s4==0&&s5==0&&s6==1&&s7==1&&s8==1||s1==1&&s2==1&&s3==1&&s4==0&&s5==1&&s6==1&&s7==1&&s8==1)
      left();
  else if(s1==1&&s2==0&&s3==0&&s4==0&&s5==0&&s6==1&&s7==1&&s8==1)
      Hleft();        
   else if(s1==0&&s2==0&&s3==0&&s4==0&&s5==0&&s6==1&&s7==1&&s8==1)
      Hleft();
   else if(s1==1&&s2==1&&s3==0&&s4==0&&s5==1&&s6==1&&s7==1&&s8==1||s1==1&&s2==1&&s3==0&&s4==1&&s5==1&&s6==1&&s7==1&&s8==1)
       left();
   else if(s1==1&&s2==0&&s3==0&&s4==0&&s5==1&&s6==1&&s7==1&&s8==1||s1==1&&s2==0&&s3==1&&s4==1&&s5==1&&s6==1&&s7==1&&s8==1||s1==0&&s2==0&&s3==1&&s4==1&&s5==1&&s6==1&&s7==1&&s8==1||s1==0&&s2==1&&s3==1&&s4==1&&s5==1&&s6==1&&s7==1&&s8==1)
        Hleft();
   else if(s1==0&&s2==0&&s3==0&&s4==0&&s5==1&&s6==1&&s7==1&&s8==1)
       Hleft();
   else if(s1==1&&s2==1&&s3==1&&s4==0&&s5==0&&s6==0&&s7==1&&s8==1||s1==1&&s2==1&&s3==1&&s4==1&&s5==0&&s6==1&&s7==1&&s8==1||s1==1&&s2==1&&s3==1&&s4==1&&s5==1&&s6==0&&s7==1&&s8==1)
        right();
      else if(s1==1&&s2==1&&s3==1&&s4==0&&s5==0&&s6==0&&s7==0&&s8==1||s1==1&&s2==1&&s3==1&&s4==1&&s5==1&&s6==1&&s7==0&&s8==0||s1==1&&s2==1&&s3==1&&s4==1&&s5==1&&s6==1&&s7==1&&s8==0)
         Hright();
      else if(s1==1&&s2==1&&s3==1&&s4==0&&s5==0&&s6==0&&s7==0&&s8==0)
         Hright();
      else if(s1==1&&s2==1&&s3==1&&s4==1&&s5==0&&s6==0&&s7==1&&s8==1||s1==1&&s2==1&&s3==1&&s4==1&&s5==1&&s6==1&&s7==0&&s8==1)
           right();
           else if(s1==1&&s2==1&&s3==1&&s4==1&&s5==0&&s6==0&&s7==0&&s8==1)
         Hright();
         else if(s1==1&&s2==1&&s3==1&&s4==1&&s5==0&&s6==0&&s7==0&&s8==0)
         Hright();
         else if(s1==0&&s2==0&&s3==0&&s4==0&&s5==0&&s6==0&&s7==0&&s8==0)
           forward();
           else if(s1==1&&s2==1&&s3==1&&s4==1&&s5==1&&s6==1&&s7==1&&s8==1)
           {
             //pause();
             //forward();
                                 
           }
}
void forward()
{
  digitalWrite(MR0,HIGH);
  digitalWrite(MR1,LOW);
  digitalWrite(ML0,HIGH);
  digitalWrite(ML1,LOW);
}
void left()
{
  digitalWrite(MR0,HIGH);
  digitalWrite(MR1,LOW);
  digitalWrite(ML0,LOW);
  digitalWrite(ML1,LOW);
}
void right()
{
  digitalWrite(MR0,LOW);
  digitalWrite(MR1,LOW);
  digitalWrite(ML0,HIGH);
  digitalWrite(ML1,LOW);
}
void Hleft()
{
  digitalWrite(MR0,HIGH);
  digitalWrite(MR1,LOW);
  digitalWrite(ML0,LOW);
  digitalWrite(ML1,HIGH);
}
void Hright()
{
  digitalWrite(MR0,LOW);
  digitalWrite(MR1,HIGH);
  digitalWrite(ML0,HIGH);
  digitalWrite(ML1,LOW);
}
void pause()
{
  digitalWrite(MR0,LOW);
  digitalWrite(MR1,LOW);
  digitalWrite(ML0,LOW);
  digitalWrite(ML1,LOW);
}
void back()
{
  digitalWrite(MR0,LOW);
  digitalWrite(MR1,HIGH);
  digitalWrite(ML0,LOW);
  digitalWrite(ML1,HIGH);
}




