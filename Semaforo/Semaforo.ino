#define amarelo   3
#define verde     2
#define vermelho  4


void setup()
{
  pinMode(amarelo,OUTPUT);
  pinMode(verde,OUTPUT);
  pinMode(vermelho,OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  //SinalAlerta();
  
  SinalVerde();
  delay(2000);

  SinalAmarelo();
  delay(750);

  SinalVermelho();
  delay(2000);
}


void SinalVerde()
{
  DesligarLuzes();

  digitalWrite(verde,HIGH);
}

void SinalAmarelo()
{
  DesligarLuzes();

  digitalWrite(amarelo,HIGH);
}

void SinalVermelho()
{
  DesligarLuzes();

  digitalWrite(vermelho,HIGH);
}

void SinalAlerta()
{
  SinalAmarelo();
  delay(750);

  DesligarLuzes();
  delay(750);
}

void DesligarLuzes()
{
  digitalWrite(amarelo,LOW);
  digitalWrite(verde,LOW);
  digitalWrite(vermelho,LOW); 
}












