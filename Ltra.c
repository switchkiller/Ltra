//WHITE LINE FOLLOWER --CYBERBREAKIN-- 

int rm1=7;
int rm2=6;
int lm1=4;
int lm2=5;

void switchoff();
void forward();
void reverse();
void left();
void right();
void powerLeft();
void powerRight();

void setup()
{
  pinMode(rm1,OUTPUT);    
  pinMode(rm2,OUTPUT);
  pinMode(lm1,OUTPUT);
  pinMode(lm2,OUTPUT);
  Serial.begin(9600);  
}

void loop()
{  
  int flag=0;
  int sensor1=digitalRead(A0);
  int sensor2=digitalRead(A1);
  int sensor3=digitalRead(A2);
  int sensor4=digitalRead(A3);
  int sensor5=digitalRead(A4);
  int sensor6=digitalRead(A5);

  
  if((sensor1==HIGH)&& (sensor2==HIGH) && (sensor3==HIGH) && (sensor4==HIGH) && (sensor5==LOW) && (sensor6==LOW)) //L-junction
  { Serial.print("L-junction invaded\n");   
    forward();
  }

  if((sensor1==LOW)&& (sensor2==LOW) && (sensor3==LOW) && (sensor4==LOW) && (sensor5==LOW) && (sensor6==LOW)) //SHUTDOWN CONDITION
  { Serial.print("System-shutdown\n");    
    switchoff();
  }
 
  if((sensor1==LOW)&& (sensor2==LOW) && (sensor3==HIGH) && (sensor4==HIGH) && (sensor5==LOW) && (sensor6==LOW)) // FORWARD
  { Serial.print("Go forward\n");    
    forward();
  }

  if((sensor1==LOW)&& (sensor2==HIGH) && (sensor3==HIGH) && (sensor4==HIGH) && (sensor5==LOW) && (sensor6==LOW)) //CURVE RIGHT TURN
  { Serial.print("Curve detected!\n");
    if (sensor2!=LOW)
    { Serial.print("Right\n");
      right();}
    else if(sensor2==HIGH)
    {  Serial.print("Left\n");
      forward();}
  }

  if((sensor1==LOW)&& (sensor2==LOW) && (sensor3==HIGH) && (sensor4==HIGH) && (sensor5==HIGH) && (sensor6==LOW)) // CURVE LEFT TURN
  { Serial.print("Curve detected!\n");    
    if (sensor5!=LOW)
    {  Serial.print("Left\n");
      left();}
    else if (sensor5==HIGH)
      {Serial.print("Go forward\n");  
      forward();}
  }

}

void forward()
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

void switchoff()
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