#include <Servo.h> 

Servo servoMotor;

int pos = 0;

void setup() 
{ 
  servoMotor.attach(9);
} 


void loop() 
{ 
  for(pos = 0; pos < 180; pos ++) 
  {                                 
    servoMotor.write(pos);          
    delay(5);                      
  } 
  for(pos = 180; pos>=1; pos--)    
  {                                
    servoMotor.write(pos);         
    delay(5);                   
  } 
} 

