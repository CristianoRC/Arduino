/*  Data e hora com modulo RTC DS1302 - Alimentaço 3,3V */
#define rele 3
#include <virtuabotixRTC.h>

byte CLK = 6;
byte DAT = 7;
byte RST = 8;

byte HoraLigar[2] = {06,29};
byte MinutosDesligar = 20;

//                (clock, data, rst)
virtuabotixRTC relogio(CLK, DAT,RST);

void setup()
{
  // (segundos, minutos, hora, dia da semana, dia do mes, mes, ano)
  relogio.setDS1302Time(5, 56, 20, 7, 26, 8, 2017);

  pinMode(3,OUTPUT);
}

void loop()
{
  relogio.updateTime();

  if(LigarLampada())
  {
    digitalWrite(rele, HIGH);
  }
  else
  {
    digitalWrite(rele, LOW);
  } 

  delay(3000);
}

boolean LigarLampada()
{
  if(relogio.hours == HoraLigar[0]  && (relogio.minutes >= HoraLigar[1]) && (relogio.minutes <= HoraLigar[1] + MinutosDesligar))
  {
    return true;
  }
  else
  {
    return false; 
  }
}

