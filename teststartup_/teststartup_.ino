
#define day1 2
#define day2 3
#define hr 4
#define mins 5
#define secs 6

int clockno,steps,flag;

void setup()
{
  pinMode(day1,OUTPUT);
  pinMode(day2,OUTPUT);
  pinMode(hr,OUTPUT);
  pinMode(mins,OUTPUT);
  pinMode(secs,OUTPUT);
  Serial.begin(9600);
  
}
void loop()
{
  digitalWrite(day1,LOW);
  delay(1);
  digitalWrite(day1,HIGH);
  delay(1250);
  
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
