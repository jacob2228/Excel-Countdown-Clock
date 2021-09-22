#include <Servo.h>
#include <DS3231.h>
#define day1 6
#define day2 5
#define hr 4
#define mins 3
#define secs 2

int clockno,steps=0,ti,j,nod,startupdata;
int d,d1,d2,d1f,d2f,tp2,l;
char ans;
int esec;
int tp=90;
int flag=0,v=1,startflag=0,sflag=0,stemp;
double i=0;
DS3231 rtc(SDA,SCL);

Time t;
Servo servo1;
Servo servo2;

void setup()
{
  pinMode(day1,OUTPUT);
  pinMode(day2,OUTPUT);
  pinMode(hr,OUTPUT);
  pinMode(mins,OUTPUT);
  pinMode(secs,OUTPUT);
  Serial.begin(9600);
  rtc.begin();
  servo1.attach(day1);
  servo2.attach(day2);
  
 
  
  
}
void loop()
{
  
  t=rtc.getTime();
  stepper(t.sec,secs);
  //stepper(t.min,mins);
  if(t.mon==8)
  d=(31-t.date)+34;
  if(t.mon==9)
  d=(30-t.date)+4;
  if(t.mon==10)
  d=4-t.date;
  Serial.println(d);
  d2=d%100;
  //Serial.println(d2);
  tp2=d/10;
  d1=tp2%10;
  d1f=(d1*18);
  d2f=(d2*18);
  //Serial.println(d1);
  servo1.write(d1f);
  servo2.write(d2f);

  
  
  
  
 
  
}
void startup()
{
  Serial.println("Enter which clock you what to change ");
  Serial.println("1.SEC CLOCK 1");
  Serial.println("2.MINS CLOCK 2");
  
 
  while(Serial.available()==0){
  startupdata=Serial.read();
  if(Serial.available())
  break;
   }
   startflag=startupdata%10;
   steps=(startupdata/10)%100;
   clockno=clockno+1;
   

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

  
  if(flag==0)
  {  
    
 for(l=0;l<=x;l++)
 {
   if(l==v)
   {
     v=v+5;
     continue;
   }
   i=i+1.25;
 }
   flag =1; 
  }  
    //Serial.println(i);
     
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
  
 
   if(x==59)
  {
     i=0;
  }
}
void creset()
{
  
}

 
