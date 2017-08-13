#include <IRremote.h>

#define receptor 11  
#define buzzer A5

#define aumentar 0x68733A46
#define diminuir 0x83B19366

float som = 0;

IRrecv irrecv(receptor);  
decode_results results;  

void setup()  
{  
  pinMode(buzzer, OUTPUT);   
  Serial.begin(9600);  
  irrecv.enableIRIn(); // Inicializa o receptor IR  
}  

void loop()  
{  
  if (irrecv.decode(&results))  
  {  
    //Serial.print("Valor lido : ");  
    //Serial.println(results.value, HEX);  
    switch(results.value)
    {
    case aumentar:
      som = som + 05;
      break;
    case diminuir:
      som = som - 05;
      break;
    }

    Serial.print("Volume : ");  
    Serial.println(som);  

    analogWrite(buzzer,som);  

    irrecv.resume(); //Le o próximo valor  
  }  
}  




