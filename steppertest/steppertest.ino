
#define stp 2
void setup()
{
  pinMode(stp,OUTPUT);
  
}
void loop()
{
  digitalWrite(stp,LOW);
  delay(1);
  digitalWrite(stp,HIGH);
  
  
  delay(1250);
  
}
