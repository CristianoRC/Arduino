#define btn 5
#define rele 3

void setup()
{
  pinMode(btn, INPUT_PULLUP);
  pinMode(rele, OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  int estadoBtn = digitalRead(btn);

  if(estadoBtn == HIGH)
  {
    digitalWrite(rele,LOW); 
  }
  else
  {
    digitalWrite(rele,HIGH); 
  }

}



