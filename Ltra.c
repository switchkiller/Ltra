//WHITE LINE FOLLOWER --CYBERBREAKIN-- 

int rm1=7;
int rm2=6;
int lm1=4;
int lm2=5;
int sensor[6]={0,0,0,0,0,0}

void shutdown();
void foward();
void reverse();
void left();
void right();
void powerLeft();
void powerRight();

void setup()
{
  pinMode(9,OUTPUT); // PWM--9
  pinMode(10,OUTPUT); // PWM--10	
  pinMode(rm1,OUTPUT);		
  pinMode(rm2,OUTPUT);
  pinMode(lm1,OUTPUT);
  pinMode(lm2,OUTPUT);
  Serial.begin(9600);  
}

void loop()
{  
  int flag=0;
  int sensor[1]=digitalRead(A0);
  int sensor[2]=digitalRead(A1);
  int sensor[3]=digitalRead(A2);
  int sensor[4]=digitalRead(A3);
  int sensor[5]=digitalRead(A4);
  int sensor[6]=digitalRead(A5);

                     
  if((sensor[1]==LOW)&& (sensor[2]==LOW) && (sensor[3]==LOW) && (sensor[4]==LOW) && (sensor[5]==LOW) && (sensor[6]==LOW)) //SHUTDOWN CONDITION
  {	    
    shutdown();
  }
 
  if((sensor[1]==LOW)&& (sensor[2]==LOW) && (sensor[3]==HIGH) && (sensor[4]==HIGH) && (sensor[5]==LOW) && (sensor[6]==LOW)) // FORWARD
  { 
    foward();
  }

  if((sensor[1]==LOW)&& (sensor[2]==HIGH) && (sensor[3]==HIGH) && (sensor[4]==HIGH) && (sensor[5]==LOW) && (sensor[6]==LOW)) //CURVE RIGHT TURN
  {	
    if (sensor[2]!=LOW)
      right();
    else if(sensor[2]==HIGH)
      foward();
  }

  if((sensor[1]==LOW)&& (sensor[2]==LOW) && (sensor[3]==HIGH) && (sensor[4]==HIGH) && (sensor[5]==HIGH) && (sensor[6]==LOW)) // CURVE LEFT TURN
  {
    if (sensor[5]!==LOW)
      left();
    else if (sensor[5]==HIGH)
      foward();
  }

  













  if(a>150 && b>150 && c<150 && d<150 &&  e<150 && f>150)
      {digitalWrite(rm1,HIGH);
      digitalWrite(rm2,LOW);
      digitalWrite(lm1,HIGH);
      digitalWrite(lm2,LOW);}
  //BWWWBB
  if(a>150 && b<150 && c<150 && d<150 &&  e>150 && f>150)
      {digitalWrite(rm1,HIGH);
      digitalWrite(rm2,LOW);
      digitalWrite(lm1,HIGH);
      digitalWrite(lm2,LOW);}
  
  //LEFT    
  //WWBBBB
  if(a<150 && b<150 && c>150 && d>150 &&  e>150 && f>150)
      {digitalWrite(rm1,HIGH);
      digitalWrite(rm2,LOW);
      digitalWrite(lm1,LOW);
      digitalWrite(lm2,LOW);}  
  //WWWBBB
  if(a<150 && b<150 && c<150 && d>150 &&  e>150 && f>150)
      {digitalWrite(rm1,HIGH);
      digitalWrite(rm2,LOW);
      digitalWrite(lm1,LOW);
      digitalWrite(lm2,LOW);} 
  //WWWWBB
  if(a<150 && b<150 && c<150 && d<150 &&  e>150 && f>150)
      {
        if(flag==1)
        {
       digitalWrite(rm1,HIGH);
      digitalWrite(rm2,LOW);
      digitalWrite(lm1,LOW);
      digitalWrite(lm2,LOW);
        }
        else
        {
          digitalWrite(rm1,HIGH);
          digitalWrite(rm2,LOW);
          digitalWrite(lm1,HIGH);
          digitalWrite(lm2,LOW);
        }
      } 
  //BWWBBB
  if(a>150 && b<150 && c<150 && d>150 &&  e>150 && f>150)
      {digitalWrite(rm1,HIGH);
      digitalWrite(rm2,LOW);
      digitalWrite(lm1,LOW);
      digitalWrite(lm2,LOW);}

  //RIGHT    
  //BBWWWW
  if(a>150 && b>150 && c<150 && d<150 &&  e<150 && f<150)
      {
        if (flag==1)
        {
        digitalWrite(rm1,LOW);
        digitalWrite(rm2,LOW);
        digitalWrite(lm1,HIGH);
        digitalWrite(lm2,LOW);
        }
      else
      {
          digitalWrite(rm1,HIGH);
          digitalWrite(rm2,LOW);
          digitalWrite(lm1,HIGH);
          digitalWrite(lm2,LOW);
      }
    }  
  //BBBWWW
  if(a>150 && b>150 && c>150 && d<150 &&  e<150 && f<150)
      {digitalWrite(rm1,LOW);
      digitalWrite(rm2,LOW);
      digitalWrite(lm1,HIGH);
      digitalWrite(lm2,LOW);} 
  //BBBBWW
  if(a>150 && b>150 && c>150 && d>150 &&  e<150 && f<150)
      {digitalWrite(rm1,LOW);
      digitalWrite(rm2,LOW);
      digitalWrite(lm1,HIGH);
      digitalWrite(lm2,LOW);} 
  //BBBWWB
  if(a>150 && b>150 && c>150 && d<150 &&  e<150 && f>150)
      {digitalWrite(rm1,LOW);
      digitalWrite(rm2,LOW);
      digitalWrite(lm1,HIGH);
      digitalWrite(lm2,LOW);}
      
  //STOP 
  
  //BBBBBB
  if (a>150 && b>150 && c>150 && d>150 &&  e>150 && f>150)
      {digitalWrite(rm1,LOW);
      digitalWrite(rm2,LOW);
      digitalWrite(lm1,LOW);
      digitalWrite(lm2,LOW);
      
      flag=1;
      }
}

void foward()
{
        digitalWrite(rm1,HIGH);
        digitalWrite(rm2,LOW);
        digitalWrite(lm1,HIGH);
        digitalWrite(lm2,LOW);
}

void reverse()
{
        digitalWrite(rm1,LOW);
        digitalWrite(rm2,HIGH);
        digitalWrite(lm1,LOW);
        digitalWrite(lm2,HIGH);
}

void shutdown()
{
        digitalWrite(rm1,LOW);
        digitalWrite(rm2,LOW);
        digitalWrite(lm1,LOW);
        digitalWrite(lm2,LOW);
}

void right()
{
        digitalWrite(rm1,LOW);
        digitalWrite(rm2,LOW);
        digitalWrite(lm1,HIGH);
        digitalWrite(lm2,LOW);
}

void powerRight()
{
        digitalWrite(rm1,LOW);
        digitalWrite(rm2,HIGH);
        digitalWrite(lm1,HIGH);
        digitalWrite(lm2,LOW);
}

void left()
{
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  digitalWrite(lm1,LOW);
  digitalWrite(lm2,LOW);
}

void powerLeft()
{
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  digitalWrite(lm1,LOW);
  digitalWrite(lm2,HIGH);
}