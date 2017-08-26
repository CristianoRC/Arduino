/*Monitorando Temperatura e Umidade com o sensor DHT11*/

#include <DHT.h>
#include <Adafruit_Sensor.h>

#define PortaSensor A0
#define ModeloSensor DHT11

DHT dht(PortaSensor, ModeloSensor);

void setup()
{
  Serial.begin(9600);
  Serial.println("Sensor de Humidade & Temperatura \n Modelo DHT11 ");
  Serial.println("=================================");
  dht.begin();
}


void loop()
{
  float humidade = dht.readHumidity();
  float temperatura = dht.readTemperature();

  if (isnan(temperatura) || isnan(humidade))   // Verifica se o retorno de um dos eh valido
  {
    Serial.println("Erro ao obter os valores!");
  } 
  else 
  {
    Serial.print("Umidade: ");
    Serial.print(humidade);
    Serial.println("%");

    Serial.println("\nTemperatura: ");
    Serial.print(temperatura);
    Serial.println("  C");
    Serial.print(ConverterParaFahrenheit(temperatura));
    Serial.println("  F");
    Serial.print(ConverterParaKelvin(temperatura));
    Serial.println(" K");
  }  

  Serial.println("---------------------------------");

  delay(1500);//Leitura a cada 1,5 s
}


float ConverterParaKelvin(float celsius)
{
  return celsius + 273.15;
}

float ConverterParaFahrenheit(float celsius)
{
  return (9 * celsius + 160) / 5;
}



