#define x A2
#define y A1
#define z A0

float eixo_x = 0;
float eixo_y = 0;
float eixo_z = 0;

void setup()
{
  Serial.begin(9600);
}


void loop()
{
  eixo_x = analogRead(x);
  eixo_y = analogRead(y);
  eixo_z = analogRead(z);

  PrintarCoordenadas();
  
  delay(1000);
}


void PrintarCoordenadas()
{
  Serial.print("X - ");
  Serial.println(eixo_x);
  Serial.print("Y - ");
  Serial.println(eixo_y);
  Serial.print("Z - ");
  Serial.println(eixo_z);
}


