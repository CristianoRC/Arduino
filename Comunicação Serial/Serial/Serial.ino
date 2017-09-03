int led = 10;          
int brightness = 0;
int fadeAmount = 5;    


void setup()  
{ 
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  
  Serial.println("Comunicacao serial efetuada com sucesso com Arduino Uno!");
} 

void loop()  
{ 
  char resultadoSerial = Serial.read();
  
  if(resultadoSerial == 'L')
  {
      digitalWrite(led,HIGH);
      Serial.println("Led ligado com sucesso!");
  }
  else if(resultadoSerial == 'D')
  {
    digitalWrite(led,LOW);
    Serial.println("Led desligado com sucesso!");
  }
  
  delay(50);                            
}
