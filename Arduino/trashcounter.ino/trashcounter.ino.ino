int a,b,c,d,e,f,g;
int timer=0;
int led=8,temp;
int current;
int initial;
int pin1=0;
int A=0,B=0,C=0,D=0;

void setup()
{
  //Serial.begin(9600);
  pinMode(0,OUTPUT);
  pinMode(1,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,INPUT);
  pinMode(10,INPUT);
  pinMode(11,INPUT);
  pinMode(12,INPUT);
  pinMode(13,OUTPUT);
}



void loop()
{
  digitalWrite(led, HIGH);   
  delay(10);
  digitalWrite(led, LOW);  
  timer = analogRead(A0);
  timer = ((timer*1.0/1024)*1500)+500 ;
 
  A=digitalRead(9);
  B=digitalRead(10);
  C=digitalRead(11);
  D=digitalRead(12);
  
  //Serial.println(timer);
  
  initial=millis();
  current=initial;
  while (current-initial<=timer)
   {
      current=millis();
      digitalWrite(1,1);
      digitalWrite(0,0);
    
      a = (!A && B && !C && !D)
      || (!A && !B && !C && D) 
      || (A && B && C && !D) 
      || (A && !B && C && D);
      b = (!A && B && !C && D) 
      || (!A && B && C && !D) 
      || (A && B && !C && !D) 
      || (A && B && C && D);
      c = (!A && !B && C && !D);
      d = (!B && !C && D) 
      || (!A && B && !C && !D) 
      || (A && !B && D) 
      || (!A && B && C && D) 
      || (A && B && C && !D);
      e = (D)
      ||(!A && B && !C) 
      || (A && B && C);
      f = (!B && C&& D) 
      || (!A && !B && D) 
      || (D && !A && C) 
      || (C &&!A && !B)
      || (!C &&A && B);
      g = (!A && B  && C && D) 
      || (!A && !B && !C) 
      || (A && !B && C);
      
      
if(A==1 && B==1 &&C==0 &&D==0)
      {
        temp=b;
        b=c;
        c=temp;
      }
      
      writenum(a,b,c,d,e,f,g);
      delay(10);
      
      digitalWrite(0,1);
      digitalWrite(1,0); 
      
       if (A==1&&(B==1||C==1))
      {
         writenum(1,0,0,1,1,1,1);
      }
      else
      {
         writenum(0,0,0,0,0,0,1);
      }
      delay(10);
  } 
}

void writenum(int a,int b,int c,
int d,int e,int f,int g)
{
 digitalWrite(13,a);
 digitalWrite(2,b);
 digitalWrite(3,c);
 digitalWrite(4,d);
 digitalWrite(5,e);
 digitalWrite(6,f);
 digitalWrite(7,g);
}
