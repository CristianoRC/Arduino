/*  Data e hora com modulo RTC DS1302 - Alimentaço 3,3V   */

byte CLK = 6;
byte DAT = 7;
byte RST = 8;

#include <virtuabotixRTC.h>

//                (clock, data, rst)
virtuabotixRTC relogio(CLK, DAT,RST);


void setup()
{
  Serial.begin(9600);

  // (segundos, minutos, hora, dia da semana, dia do mes, mes, ano)
  relogio.setDS1302Time(00, 50, 20, 7, 26, 8, 2017);
}


void loop()
{
  relogio.updateTime();

  //Dia da semana
  Serial.print("Data & hora: ");
  Serial.print(DiasDaSemana(relogio.dayofweek));
  Serial.print(", ");

  //Dia/Mes/Ano
  Serial.print(relogio.dayofmonth);
  Serial.print("/");
  Serial.print(relogio.month);
  Serial.print("/");
  Serial.print(relogio.year);
  Serial.print("   ");

  //Hora:Minuto:Segundo
  if(relogio.hours < 10)
    Serial.print("0");
  Serial.print(relogio.hours);
  Serial.print(":");

  if(relogio.minutes < 10)
    Serial.print("0");

  Serial.print(relogio.minutes);
  Serial.print(":");

  if(relogio.seconds < 10)
    Serial.print("0");

  Serial.print(relogio.seconds);


  Serial.print("\n");
  delay(1000);//Atualizando a cada 1 segundo.
}


String DiasDaSemana(int dia)
{
  switch(dia)
  {
  case 1:
    return "Domingo";
    break;
  case 2:
    return "Segunda-Feira";
    break;
  case 3:
    return "Terça-Feira";
    break;
  case 4:
    return "Quarta-Feira";
    break;
  case 5:
    return "Quinta-Feira";
    break;
  case 6:
    return "Sexta-Feira";
    break;
  case 7:
    return "Sabado";
    break;
  }
}














