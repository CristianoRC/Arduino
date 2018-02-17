#define sensor A0
#define buzzer 2
#define LED 3

void setup()
{
  pinMode(sensor,INPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(LED,OUTPUT);
  Serial.begin(9600);
} 

void loop()
{
  float valorSensor = analogRead(sensor);
  Serial.println(valorSensor);
  if(valorSensor > 200)
  {
    digitalWrite(buzzer,HIGH);
    digitalWrite(LED,HIGH);
  }
  else
  {
    digitalWrite(buzzer,LOW);
    digitalWrite(LED,LOW);
  }
  delay(250);
}



