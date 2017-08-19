/*Leitura analogica*/

#define led 9
#define sensor A0

int sound = 0;
boolean statusLed = false;

void setup()  
{ 
  pinMode(led, OUTPUT);
  Serial.begin(9600);
} 

void loop()  
{ 
  int valorSensor = analogRead(sensor);

  if(valorSensor > 512)//Mais da metada
  {

    if(statusLed)
    {
      digitalWrite(led,LOW);

      statusLed = false;
    }
    else
    {
      digitalWrite(led,HIGH); 

      statusLed = true;
    }
  }
  delay(250);
  Serial.println(valorSensor);
}

/*Digital 
 #define led 9
 #define sensor 3
 
 int sound = 0;
 boolean statusLed = false;
 void setup()  
 { 
 pinMode(led, OUTPUT);
 Serial.begin(9600);
 } 
 
 void loop()  
 { 
 int valorSensor = digitalRead(sensor);
 
 if(valorSensor == HIGH)
 {
 if(statusLed)
 {
 digitalWrite(led,LOW);
 
 statusLed = false;
 }
 else
 {
 digitalWrite(led,HIGH); 
 
 statusLed = true;
 }
 
 delay(100);
 }
 
 Serial.println(valorSensor);
 }*/




