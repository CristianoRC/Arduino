#include <Stepper.h>

#define in1 11 
#define in2 10
#define in3  9
#define in4  8
#define potVelocidade A1

int passosPorCiclo = 200;

Stepper Motor(passosPorCiclo,in1,in3,in2,in4);

void setup()
{
  Motor.setSpeed(120); //120 RPM
}

void loop()
{
  if(analogRead(potVelocidade) < 511)
  {
    Motor.step(passosPorCiclo * -1); 
  }
  else
  {
    Motor.step(passosPorCiclo); 
  }
}









