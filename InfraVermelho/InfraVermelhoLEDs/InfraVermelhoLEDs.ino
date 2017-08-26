#include <IRremote.h> 

#define Vermelho 3
#define Verde 6
#define Amarelo 5
#define receptor 11
#define buzzer 2

#define codigoVermelho 0xDAEA83EC
#define codigoVerde 0x2BAFCEEC
#define codigoAmarelo 0xB5210DA6

IRrecv irrecv(receptor);  
decode_results results;

void setup()
{
  pinMode(Vermelho,OUTPUT); 
  pinMode(Verde,OUTPUT);
  pinMode(Amarelo,OUTPUT);
  pinMode(buzzer,OUTPUT); 

  irrecv.enableIRIn(); // Inicializa o receptor IR 
  Serial.begin(9600); 
}

void loop()
{
  if (irrecv.decode(&results)) 
  {
    Serial.println(results.value,HEX);

    switch(results.value)
    {
    case codigoVermelho:
      controleLedVermelho();
      break;
    case codigoVerde:
      controleLedVerde();
      break;
    case codigoAmarelo:
      controleLedAmarelo();
      break;
    }

    delay(250);
    irrecv.resume(); //Recebe o proximo valor.

  }

}

void controleLedVerde()
{
  if(digitalRead(Verde) == LOW)
  {
    digitalWrite(Verde,HIGH);    
  }
  else
  {
    digitalWrite(Verde,LOW);   
  }
}

void controleLedVermelho()
{
  if(digitalRead(Vermelho) == LOW)
  {
    digitalWrite(Vermelho,HIGH);    
  }
  else
  {
    digitalWrite(Vermelho,LOW);   
  }
}

void controleLedAmarelo()
{    
  if(digitalRead(Amarelo) == LOW)
  {
    digitalWrite(Amarelo,HIGH);    
  }
  else
  {
    digitalWrite(Amarelo,LOW);   
  }
}  











