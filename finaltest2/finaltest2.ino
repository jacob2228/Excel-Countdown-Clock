
#include <DS3231.h>
#define day1 6
#define day2 5
#define hr 4
#define mins 3
#define secs 2

int clockno,steps,ti,j,nod;
int tp=90;
int flag=0;
double i=0;
DS3231 rtc(SDA,SCL);

Time t;

void setup()
{
  pinMode(day1,OUTPUT);
  pinMode(day2,OUTPUT);
  pinMode(hr,OUTPUT);
  pinMode(mins,OUTPUT);
  pinMode(secs,OUTPUT);
  Serial.begin(9600);
  rtc.begin();
 
  
  
}
void loop()
{ 
  
  t=rtc.getTime();
  stepper(t.sec,secs);
  stepper(t.min,mins);
  
  
  
  
  
 
  
}
void startup()
{
  Serial.println("Enter which clock you what to change ");
  Serial.println("1.DATE CLOCK 1");
  Serial.println("2.DATE CLOCK 2");
  Serial.println("3.HOUR CLOCK ");
  Serial.println("4.MIN CLOCK");
  Serial.println("5.SEC CLOCK");
  clockno=Serial.read();
  clockno=clockno+1;
  Serial.println("Enter the no of steps needed");
  steps=Serial.read();
  for(int i=0;i<steps;i++)
  {
    digitalWrite(clockno,LOW);
    delay(1);
    digitalWrite(clockno,HIGH);
    delay(100);
  }
  
}
void stepper(int x,int y)
{
  if(x==0)
  flag=1;
  
 
  
  if(flag==1)
  {  
    
    
     
     if((x>=i) && (x!=tp))
   {
     digitalWrite(y,LOW);
     delay(1);
     digitalWrite(y,HIGH);
     i=i+1.25;
     Serial.print("\t");
     
     Serial.print(i);
     
     Serial.print("\t");
     
     Serial.println(x);
     
     tp=x;
     
    
   }
    
  }
   if(x==59)
  {
     i=0;
  }
}
