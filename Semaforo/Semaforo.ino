#define    verde 4
#define  amarelo 3
#define vermelho 2

boolean ativarAlerta = false;

void setup()
{
  pinMode(amarelo,OUTPUT);
  pinMode(verde,OUTPUT);
  pinMode(vermelho,OUTPUT); 

  Serial.begin(9600);
}

void loop()
{
  verificarAlerta();

  if(!ativarAlerta)
  {
    SinalVerde();
    delay(5000);

    SinalAmarelo();
    delay(1500);

    SinalVermelho();
    delay(5000); 
  }
  else
  {
    SinalAlerta();
  }
}

void verificarAlerta()
{
  String leitura = Serial.readString();

  Serial.println(leitura);

  if(leitura == "ativar\n")
  {
    ativarAlerta = true;
  }
  else if(leitura == "desativar\n")
  {
    ativarAlerta  = false;
  }

}

void SinalVerde()
{
  DesligarLuzes();

  Serial.println(verde);

  digitalWrite(verde,HIGH);
}

void SinalAmarelo()
{
  DesligarLuzes();

  Serial.println(amarelo);

  digitalWrite(amarelo,HIGH);
}

void SinalVermelho()
{
  DesligarLuzes();

  Serial.println(vermelho);

  digitalWrite(vermelho,HIGH);
}

void SinalAlerta()
{
  SinalAmarelo();
  delay(1500);

  Serial.println(0);
  DesligarLuzes();
  delay(500);
}

void DesligarLuzes()
{
  digitalWrite(amarelo,LOW);
  digitalWrite(verde,LOW);
  digitalWrite(vermelho,LOW); 
}


