
#include <DS3231.h>
#define day1 2
#define day2 3
#define hr 4
#define mins 5
#define secs 6

int clockno,steps,ti,j;
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
  
  if(t.sec==0)
  flag=1;
  
 
  
  if(flag==1)
  {  
    
    
     
     if((t.sec>=i) && (t.sec!=tp))
   {
     digitalWrite(secs,LOW);
     delay(1);
     digitalWrite(secs,HIGH);
     i=i+1.25;
     
     Serial.print(i);
     
     Serial.print("\t");
     
     Serial.println(t.sec);
     
     tp=t.sec;
     
    
   }
    
  }
   if(t.sec==59)
  {
     i=0;
  }
  
 
  
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
void time()
{
}
