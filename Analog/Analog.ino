#define potenciometro A2
#define LED 3

void setup()
{
  pinMode(potenciometro,INPUT);
  pinMode(LED,OUTPUT);
  
  Serial.begin(9600);
  
}


void loop()
{
    int fadeValue = analogRead(potenciometro);
    
    fadeValue = fadeValue / 4,11;
    
    analogWrite(LED,fadeValue);
    
    Serial.println(fadeValue);
}
