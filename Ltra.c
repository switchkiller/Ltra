//CURVE FOLLOWING

int rm1=7;
int rm2=6;
int lm1=4;
int lm2=5;


void setup()
{
  pinMode(rm1,OUTPUT);
  pinMode(rm2,OUTPUT);
  pinMode(lm1,OUTPUT);
  pinMode(lm2,OUTPUT);
  
  
}

void loop()
{  
int flag=0;
  int a=analogRead(0);
  int b=analogRead(1);
  int c=analogRead(2);
  int d=analogRead(3);
  int e=analogRead(4);
  int f=analogRead(5);

                     
 //FORWARD
 //BBWWBB
 if(a>150 && b>150 && c<150 && d<150 &&  e>150 && f>150)
      {digitalWrite(rm1,HIGH);
      digitalWrite(rm2,LOW);
      digitalWrite(lm1,HIGH);
      digitalWrite(lm2,LOW);}
  //BBWWWB
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
