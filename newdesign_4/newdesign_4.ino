#include<Servo.h>
#include<DS3231.h>

int minspin=3;
int hourspin=5;
int dayspin=6;
int trig =2;
int echo =4;
DS3231 rtc(SDA,SCL);
Time t;
int d,m,angletempdays,angledays;
int h,angletemphours,anglehours;
int angletempmins,anglemins;
int flag=0,flagmins=0,flaghours=0;
int dayc;
int dur,dist;

Servo mymins;
Servo myhours;
Servo mydate;



void setup()
{ 
  pinMode(minspin,OUTPUT);
  pinMode(hourspin,OUTPUT);
  pinMode(dayspin,OUTPUT);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  Serial.begin(9600);
  rtc.begin();
  mymins.attach(minspin);
  myhours.attach(hourspin);
  mydate.attach(dayspin);
  
  mymins.write(85);
  
  
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
   Serial.println(d); 
  angletempdays=3.85*d;
  angledays=170-angletempdays;
  
   if(flag==0)
   {
     m=t.min;
     flag=1;
   } 
 
   sweep();

   mins();
   hours();
   mydate.detach();
  //Serial.println(d);
  //mydate.write(0);
}
void sweep()
{ 
  
  if(t.min==m)
 {
   mydate.attach(dayspin);
  for(int i=angledays;i<=170;i=i+1)
   {
     mydate.write(i);
     delay(100);
     
   }
  

  for(int j=170;j>=(angledays-3);j=j-1)  
  {
    mydate.write(j);
    delay(100);
  }
   m=t.min+2;
   
 }
 if(m>59)
   m=0;
  
}
void hours()
{
  if((d<=0) && (t.hour>=10))
  h=0;
  else if(t.hour<=10)
  h=10-t.hour;
  else 
  h=(24-t.hour)+10;
  
  angletemphours=3.75*h;
  anglehours=3.75*h;
  if(h<10)
  flaghours=0;
  if((h>23)&&(flaghours==0))
  {
   for(int i=anglehours;i>=0;i--) 
   {
     myhours.write(i);
     delay(100);
   }
   flaghours=1;
  }
  
  
  myhours.write(anglehours);
  
}
void mins()
{
  anglemins=78-(1.2*t.min);
  
  if(t.min>20)
  flagmins=0;
  if((t.min==00) &&(flagmins==0))
  {
    for(int i=anglemins;i>=0;i--)
    {
     mymins.write(i);
     delay(100); 
    }
    flagmins=1;
  }
  mymins.write(anglemins);
}
