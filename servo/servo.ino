#include<DS3231.h>
#include<Servo.h>
int d,d1,d2,d1f,d2f,tp2;
#define day1 6
#define day2 5
DS3231 rtc(SDA,SCL);

Time t;
Servo servo1;

void setup()
{
  Serial.begin(9600);
  rtc.begin();
  servo1.attach(day1);
}
void loop()
{
  t=rtc.getTime();
  if(t.mon==8)
  d=(31-t.date)+35;
  if(t.mon==9)
  d=(30-t.date)+5;
  if(t.mon==10)
  d=5-t.date;
  //Serial.println(d);
  d2=d%100;
  //Serial.println(d2);
  tp2=d/10;
  d1=tp2%10;
  d1f=d1*10;
  Serial.println(d1);
  servo1.write(d1f);
  
  
}
