const int trigger_front=8;
const int echo_front=7;

const int trigger_left=11;
const int echo_left=10;

const int trigger_right=13;
const int echo_right=12;

const int ML0=3;
const int ML1=5;
const int MR0=9;
const int MR1=6;

const int x=10;    //center threshold
const int y=5;    //left
const int z=10;    //right
long raw_front,front,raw_left,left,raw_right,right;
//int center,right,left; 
void setup()
    {
        Serial.begin(9600);
        
        pinMode(trigger_front, OUTPUT); 
        pinMode(echo_front, INPUT);
        
        pinMode(trigger_left, OUTPUT);
        pinMode(echo_left, INPUT);        
        
        pinMode(trigger_right, OUTPUT);
        pinMode(echo_right, INPUT); 
             
        pinMode(ML0, OUTPUT);
        pinMode(ML1, OUTPUT);
        
        pinMode(MR0, OUTPUT);
        pinMode(MR1, OUTPUT);       
        delay(500);
    
}

void loop() {
     0
     sensor();
      if(front > x)
      forward();
      else  if(right >z)
    {
    //forward();
        //delay(100);  
     right_check();
    }
   else  if(left > y)
     { 
        left_check();
     }
      
 else if(left < y && front < x && right < z)
   turn_around();
    
}

void forward()
{ 
  
  digitalWrite(MR0,HIGH);
  digitalWrite(MR1,LOW);
  digitalWrite(ML0,HIGH);
  digitalWrite(ML1,LOW);
}
void left_turn()
{  
  
  digitalWrite(MR0,HIGH);
  digitalWrite(MR1,LOW);
  digitalWrite(ML0,LOW);
  digitalWrite(ML1,LOW);
  
}
void right_turn()
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
void stop_it()
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
void turn_around()
{
  
  do{
    Hright();
    sensor();
  }
  while(front < x);
}  

void left_check()
{
  do{
    Hleft();
    sensor();
  }
  while(front < x);
}

void right_check()
{
  do{
    Hright();
    sensor();
  }
  while(front < x);
}    
void sensor()
{
digitalWrite(trigger_front, LOW);  
     delayMicroseconds(2);               
     digitalWrite(trigger_front, HIGH);   
     delayMicroseconds(10);               
     digitalWrite(trigger_front, LOW);  
     raw_front = pulseIn(echo_front, HIGH);
     front = (raw_front/2)/29.1;
     Serial.print(" front \t");
     Serial.println(front);
    
     digitalWrite(trigger_left, LOW);
     delayMicroseconds(2);
     digitalWrite(trigger_left, HIGH);
     delayMicroseconds(10);
     digitalWrite(trigger_left, LOW); 
     raw_left = pulseIn(echo_left, HIGH);
     left =  (raw_left/2)/29.1;
     
     Serial.print(" left \t");
     Serial.println(left);
     
     digitalWrite(trigger_right, LOW);
     delayMicroseconds(2);
     digitalWrite(trigger_right, HIGH);
     delayMicroseconds(10);
     digitalWrite(trigger_right, LOW); 
     raw_right = pulseIn(echo_right, HIGH);
     right =  (raw_right/2)/29.1;
     
     Serial.print(" right \t");
     Serial.println(right);
}


