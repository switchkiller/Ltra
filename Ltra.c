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

  
  if((sensor[1]==LOW)&& (sensor[2]==LOW) && (sensor[3]==LOW) && (sensor[4]==LOW) && (sensor[5]==LOW) && (sensor[6]==LOW)) //L-junction
  { Serial.printf("L-junction invaded\n");   
    forward();
  }

  if((sensor[1]==LOW)&& (sensor[2]==LOW) && (sensor[3]==LOW) && (sensor[4]==LOW) && (sensor[5]==LOW) && (sensor[6]==LOW)) //SHUTDOWN CONDITION
  {	Serial.printf("System-shutdown\n");    
    shutdown();
  }
 
  if((sensor[1]==LOW)&& (sensor[2]==LOW) && (sensor[3]==HIGH) && (sensor[4]==HIGH) && (sensor[5]==LOW) && (sensor[6]==LOW)) // FORWARD
  { Serial.printf("Go forward\n");    
    foward();
  }

  if((sensor[1]==LOW)&& (sensor[2]==HIGH) && (sensor[3]==HIGH) && (sensor[4]==HIGH) && (sensor[5]==LOW) && (sensor[6]==LOW)) //CURVE RIGHT TURN
  {	Serial.printf("Curve detected!\n");
    if (sensor[2]!=LOW)
      Serial.printf("Right\n");
      right();
    else if(sensor[2]==HIGH)
      Serial.printf("Left\n");
      foward();
  }

  if((sensor[1]==LOW)&& (sensor[2]==LOW) && (sensor[3]==HIGH) && (sensor[4]==HIGH) && (sensor[5]==HIGH) && (sensor[6]==LOW)) // CURVE LEFT TURN
  { Serial.printf("Curve detected!\n");    
    if (sensor[5]!==LOW)
      Serial.printf("Left\n");
      left();
    else if (sensor[5]==HIGH)
      Serial.printf("Go forward\n");  
      foward();
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