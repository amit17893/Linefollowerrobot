//final code.  
const int ML0=6,ML1=7,MR0=8,MR1=9,sl=11,sr=10,led=12,led2=13;
const int sp1=A0,sp2=A1,sp3=5,sp4=4,sp5=3,sp6=2,sp7=A2,sp8=A4,sp9=A5;
int s1,s2,s3,s4,s5,s6,s7,s8,s9;
char path[60],path1[60];
int len=0,j=0;
void setup() {
   pinMode(ML0,OUTPUT);
  pinMode(ML1,OUTPUT);
  pinMode(MR0,OUTPUT);
  pinMode(MR1,OUTPUT);
  pinMode(sl,OUTPUT);
  pinMode(sr,OUTPUT);
  pinMode(led,OUTPUT);
  pinMode(led2,OUTPUT);
   pinMode(sp1,INPUT);
  pinMode(sp2,INPUT);
  pinMode(sp3,INPUT);
  pinMode(sp4,INPUT);
  pinMode(sp5,INPUT);
  pinMode(sp6,INPUT);
  pinMode(sp7,INPUT);
  pinMode(sp8,INPUT);
    pinMode(sp9,INPUT);
  analogWrite(sl,0);//sets the motors speed   100
  analogWrite(sr,0);//sets the motors speed   120
  Serial.begin(9600);
  
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  //digitalWrite(led,HIGH);
  pulse();
/* //mazeright();
 lfr();
 pause();
 delay(1000);
 forward();
 delay(300);
 sensorread();
 if(s1==1 &&s2==1 && s3==1 && s4==1 && s5==1 && s6==1 && s7==1 && s8==1)
 {
 Hright();
 delay(720);
 //forward();
 //delay(200);
 pause();
 //delay(2000);
 lfrarray();
 }
 pause();
 delay(3000);
 */   lfr();  
   sensorread();
     if(s1==0 && s2==0 && s3==0 && s4==0 && s5==0 && s6==0 && s7==0 && s8==0)
     {
      //digitalWrite(led2,HIGH);
      delay(500);
      digitalWrite(led2,LOW);        
      pause();
     // while(1);
      reverseleft();  //back 180
     }
    else if(s1==1 ||s2==1 ||(s1==1 && s2==1 && s4==1 && s5==1) )
           { 
           rotateleft();  //left 90 degree
            }
            else
             {
              //analogWrite(sl,255);//sets the motors speed   100
              //analogWrite(sr,145);//sets the motors speed   120
                         
                          forward();
                          delay(400);  //go forward check for path either right or straight.
                         
             
                           // pulse();
                          sensorread();
                         path[len]='S';
                        int flag=0;               
                        if(s1==0 && s2==0 && s3==0 && s4==0 && s5==0 && s6==0 && s7==0 && s8==0)
                         {
                            //analogWrite(sl,130);//sets the motors speed   100
                            // analogWrite(sr,100);//sets the motors speed   120    
                             //forward();
                             //delay(50);
                             flag=1;
                             Tpulse();
                              //mazeright();//take right if straight path not available.
                              only();
                              pulse();
                                path[len]='R';
                                 // pulse();
                           }
                           Serial.print("control in ");
                           Serial.println(path[len]);            
                           len++; //update array value.
              if(flag==0)
              {
                pause();
                //digitalWrite(led,HIGH);
                //delay(500);
                digitalWrite(led,LOW);
                forward();
                analogWrite(sl,60);//sets the motors speed   100
                analogWrite(sr,90);//sets the motors speed   120
                lfrarray();//balance from "L' point
                pulse();
              }
             
              if(path[len-2]=='B')
                      {
                           shortPath();
                      }
             
             }
             
             
 
}  
void call_forward()
{
  forward();
  digitalWrite(led,HIGH);
  delay(50);
  }

void sensoranalog()
{
  
s1=analogRead(sp1);
  s2=digitalRead(sp2);
  s3=digitalRead(sp3);
  s4=digitalRead(sp4);
  s5=digitalRead(sp5);
  s6=digitalRead(sp6);
  s7=digitalRead(sp7);
  s8=analogRead(sp8);
  s9=analogRead(sp9);
  /*Serial.println(s1);
  Serial.println(s2);
  Serial.println(s3);
  Serial.println(s4);
  Serial.println(s5);
  Serial.println(s6);
  Serial.println(s7);
  Serial.println(s8);*/
}

void sensorread()
{
  
s1=digitalRead(sp1);
  s2=digitalRead(sp2);
  s3=digitalRead(sp3);
  s4=digitalRead(sp4);
  s5=digitalRead(sp5);
  s6=digitalRead(sp6);
  s7=digitalRead(sp7);
  s8=digitalRead(sp8);
   s9=digitalRead(sp9);
  /*Serial.println(s1);
  Serial.println(s2);
  Serial.println(s3);
  Serial.println(s4);
  Serial.println(s5);
  Serial.println(s6);
  Serial.println(s7);
  Serial.println(s8);
  */
}
void pulse()
{
 analogWrite(sl,100);//sets the motors speed   100//255
  analogWrite(sr,140);//sets the motors speed   120//180
}
void Tpulse()
{
analogWrite(sl,70);//sets the motors speed   100
  analogWrite(sr,110);//sets the motors speed   120

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
void lfrarray()
{    sensorread();     
  if(s1==0&& (s2==1 ||s3==1|| s4==1 || s5==1||s6==1 ||s7==1 )&&s8==0)
        {
          sensorread(); 
         if(s3==0 && s4==1 && s5==1 && s6==0)
         forward();
         else if((s3==0 && s4==1 && s5==0 && s6==0)||(s3==1 && s4==1 && s5==0 && s6==0)||(s3==1 && s4==1 && s5==1 && s6==0)||(s3==1 && s4==0 && s5==0 && s6==0))
           left();
         else if((s3==0 && s4==0 && s5==1 && s6==0)||(s3==0 && s4==0 && s5==1 && s6==1)||(s3==0 && s4==1 && s5==1 && s6==1)||(s3==0 && s4==0 && s5==0 && s6==1))
           right();

           pulse();
           lfr();
        }
          
    else 
    { 
      forward();
      //delay(10);
      pause();
       pulse();
      delay(100);
                  
    }
}

void lfr()
{    sensorread();     
  if(s1==0&& s2==0 && (s3==1|| s4==1 || s5==1||s6==1 ) && s7==0 &&s8==0)
        {
          sensorread(); 
         if(s3==0 && s4==1 && s5==1 && s6==0)
         forward();
         else if((s3==0 && s4==1 && s5==0 && s6==0)||(s3==1 && s4==1 && s5==0 && s6==0)||(s3==1 && s4==1 && s5==1 && s6==0)||(s3==1 && s4==0 && s5==0 && s6==0))
           left();
         else if((s3==0 && s4==0 && s5==1 && s6==0)||(s3==0 && s4==0 && s5==1 && s6==1)||(s3==0 && s4==1 && s5==1 && s6==1)||(s3==0 && s4==0 && s5==0 && s6==1))
           right();
           
           lfr();
        }
          
    else 
    { 
      forward();
      //delay(10);
      pause();
      sensorread();
     delay(100);
                  
    }
}

void lfr2()
{    sensorread();     
  if(s1==0&& s2==0 && (s3==1|| s4==1 || s5==1||s6==1 ) && s7==0 &&s8==0)
        {
          sensorread(); 
         if(s4==1 && s5==1)
         forward();
         else if( s4==1 && s5==0)
         {  
           analogWrite(sl,200);//sets the motors speed   100//255
           analogWrite(sr,200);//sets the motors speed   120//180
           left();
           pulse();
         }
         else if(s4==0 && s5==1)
         {
           analogWrite(sl,200);//sets the motors speed   100//255
          analogWrite(sr,200);//sets the motors speed   120//180
           right();
           pulse();
         }  
           lfr2();
        }
          
    else 
    { 
      forward();
      //delay(10);
      pause();
     // delay(100);
                  
    }
}

void shortPath(){
 int shortDone=0;
  if(path[len-3]=='L' && path[len-1]=='R'){
    len-=3;
    path[len]='B';
    //Serial.println("test1");
    shortDone=1;
  }
   
  if(path[len-3]=='L' && path[len-1]=='S' && shortDone==0){
    len-=3;
    path[len]='R';
    //Serial.println("test2");
    shortDone=1;
  }
   
  if(path[len-3]=='R' && path[len-1]=='L' && shortDone==0){
    len-=3;
    path[len]='B';
    //Serial.println("test3");
    shortDone=1;
  }
  
   
  if(path[len-3]=='S' && path[len-1]=='L' && shortDone==0){
    len-=3;
    path[len]='R';
    //Serial.println("test4");
    shortDone=1;
  }
     
  if(path[len-3]=='S' && path[len-1]=='S' && shortDone==0){
    len-=3;
    path[len]='B';
    //Serial.println("test5");
    shortDone=1;
  }
    if(path[len-3]=='L' && path[len-1]=='L' && shortDone==0){
    len-=3;
    path[len]='S';
    //Serial.println("test6");
    shortDone=1;
  }
  
  path[len+1]='D';
  path[len+2]='D';
  len++;
  //Serial.print("Path length: ");
  //Serial.println(len);
  //printPath();
}
void replay()
{  
     if(path1[j]=='D')
    {
       pause();
       for(int i=0;i<40;i++)
       {
       Serial.print(path[i]);
       }
       digitalWrite(led,HIGH);
       delay(10000000);
       //led on
  }
  else if(path1[j]=='R')
  {
                              forward();
                              delay(400);
                            Tpulse();
                              mazeright();
                              pulse();
  
           
  }
  else if(path1[j]=='L')
  {
            //Tpulse();
             forward();
            delay(300);
               mazeleft();
               pulse();
               lfr();       
  } 
  else if(path1[j]=='S')
  {
              
                          forward();
                          delay(400);
                     digitalWrite(led,HIGH);
                            lfrarray();
              
              
  }
//len++;
j++;
pause();
delay(1000);
  lfr();
replay();

}
void mazeleft()
{  //analogWrite(sl,200);//sets the motors speed   100
  //analogWrite(sr,200);//sets the motors speed   120
 
Hleft();
delay(200);
do
{
Hleft();
sensorread();
}
  while( (s4==0 ||s5==0 ) );
}

void mazeright()
{
  Hright();
  delay(150); //150
do
{
Hright();
sensorread();
}
//while(!( s1==0&&s2==0&&s3==0&&s4==1&&s5==1&&s6==0&&s7==0&&s8==0));
  while( s4==0 || s5==0);
}
void only()
{
  Hright();
  delay(125); //150
do
{
Hright();
sensorread();
}
//while(!( s1==0&&s2==0&&s3==0&&s4==1&&s5==1&&s6==0&&s7==0&&s8==0));
  while( s4==0 || s5==0);
}

void rotateright()
{
    forward();
    delay(100);
    sensorread();
    delay(200); 
    if((s1==0 && s2==0 && s3==0 && (s4==1 ||s5==1 )&& s6==0 && s7==0 && s8==0 )|| ( s1==0 && s2==0 && s3==1 && s4==1 && s5==0 && s6==0 && s7==0 && s8==0 ) ||( s1==0&&s2==0&&s3==0&&s4==0&&s5==1&&s6==1&&s7==0&&s8==0)  || ( s1==0&&s2==0&&s3==1&&s4==1&&s5==1&&s6==0&&s7==0&&s8==0) )
   {
    lfr();
   }
   else if(s1==0&&s2==0&&s3==0&&s4==0&&s5==0&&s6==0&&s7==0&&s8==0)
   {
    Serial.println("ZZZZZZZZZZZ    RIGHT ZZZZZZZZZZZZZZ");
   mazeright();
   }
}
void rotateleft()
           { 
            forward();
            delay(400);
            //Tpulse();
            sensorread();
            if(s1==1 && s2==1 && s3==1 && s4==1 && s5==1 && s6==1 && s7==1 && s8==1)
              {  
                pause();
                path[len]='D';
                len++;
                Serial.println("dead end");
                      if(path[len-2]=='B')
                      {
                           shortPath();
                      }
                      int  k=0;
                      //blink led for 20 second on final point.
                 while(k<4)
                 {
                   /*for(int i=0;i<40;i++)
                   {
                    Serial.print(path[i]);
                   }
                Serial.println("<SFGDFHDFHGDGDRHDHDGDRRHDTHTDGHT>");
                */
                
                     digitalWrite(led,HIGH);
                     delay(1000);
                     digitalWrite(led,LOW);
                     delay(100);
                      k++;
                }
                //len=0;
                 
                j=0;
                for(int i=len;i>=0;i--)
                {
                 if(path[i]=='D')
                  continue;
                 else if(path[i]=='L')
                 {
                  path1[j]='R';
                  j++;
                 }
                 else if(path[i]=='R')
                 {
                  path1[j]='L';
                   j++;
                 }
                 else if(path[i]=='S')
                 {
                  path1[j]='S';
                   j++;
                 }
                }
                pause();
                back();
                delay(300);
                Hright();
                 delay(720);
                  //forward();
                  //delay(100);
                j=0;
                lfrarray();
                lfr();
                replay(); //now to go on shortest path
              }
               mazeleft();
               //pulse();
              path[len]='L';
                len++;
                Serial.println("left turn");
                      if(path[len-2]=='B')
                      {
                           shortPath();
                      }
                  lfr();    
                      
           }

 void reverseleft()
           { 
            forward();
            //delay(200);
             //analogWrite(sl,140);//sets the motors speed   100
               //    analogWrite(sr,110);//sets the motors speed   120
               mazeright();
               //pulse();
              path[len]='B';
                len++;
                Serial.println (" reverse " );
                      if(path[len-2]=='B')
                      {
                           shortPath();
                      }
                  lfr();    
                  
                      
           }
          
