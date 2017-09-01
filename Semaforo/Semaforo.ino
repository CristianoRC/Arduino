#define amarelo   3
#define verde     2
#define vermelho  4


void setup()
{
  pinMode(amarelo,OUTPUT);
  pinMode(verde,OUTPUT);
  pinMode(vermelho,OUTPUT);
}

void loop()
{
  SinalVerde();
  delay(2000);

  SinalAmarelo();
  delay(300);

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

void DesligarLuzes()
{
  digitalWrite(amarelo,LOW);
  digitalWrite(verde,LOW);
  digitalWrite(vermelho,LOW); 
}









