#include<Servo.h>
#include<DS3231.h>

DS3231 rtc(SDA,SCL);
Time t;
int d,angletemp,angle;
int m,flag=0;
Servo mydate;

void setup()
{
  Serial.begin(9600);
  rtc.begin();
  mydate.attach(5);
  digitalWrite(12,HIGH);
  
  
}
void loop()
{ 
  
  
  t=rtc.getTime();
  //Serial.println(t.date);
  if(t.mon==8)
  d=(31-t.date)+35;
  if(t.mon==9)
  d=(30-t.date)+5;
  if(t.mon==10)
  d=5-t.date; 
  
  Serial.print(d); 
  
  angletemp=2.95*d;
  angle=163-angletemp;
  
  //Serial.println(m);
   if(flag==0)
   {
     m=t.min;
     flag=1;
   }  
   sweep();
   mydate.detach();
  //Serial.println(d);
  //mydate.write(0);
}
void sweep()
{ 
  
  if(t.min==m)
 {
   mydate.attach(5);
  for(int i=angle;i<163;i=i+1)
   {
     mydate.write(i);
     delay(100);
     
   }
  

  for(int j=163;j>(angle-3);j=j-1)  
  {
    mydate.write(j);
    delay(100);
  }
   m=t.min+2;
   
 }
 if(m>59)
   m=0;
  
}
