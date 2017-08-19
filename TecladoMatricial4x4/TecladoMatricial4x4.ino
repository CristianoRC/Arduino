//-------   Linhas ------------
#define Linha1 3
#define Linha2 4
#define Linha3 5
#define Linha4 6

//-------  Colunas ------------
#define ColunaA 8
#define ColunaB 9
#define ColunaC 10
#define ColunaD 11

//Mapa de caracteres
char caracteres [4][4]{ 
  'D','#','0','*',
  'C','9','8','7',
  'B','6','5','4',
  'A','3','4','1'
};

void setup()
{
  pinMode(Linha1,OUTPUT);
  pinMode(Linha2,OUTPUT);
  pinMode(Linha3,OUTPUT);
  pinMode(Linha4,OUTPUT);

  pinMode(ColunaA,INPUT);
  pinMode(ColunaB,INPUT);
  pinMode(ColunaC,INPUT);
  pinMode(ColunaD,INPUT);

  Serial.begin(9600);
  Serial.println("Aguardando acionamento das teclas...");
  Serial.println();
}


void loop()
{
  for(int ln = 3;ln < 7;ln++)
  {
    digitalWrite(Linha1,LOW);//Desativa todas as linhas e ativa uma por vez
    digitalWrite(Linha2,LOW);
    digitalWrite(Linha3,LOW);
    digitalWrite(Linha4,LOW);
    digitalWrite(ln,HIGH);

    //Verificacao das colunas

    if(digitalRead(ColunaA) == HIGH)
    {
      imprimirCaractere(ln-2,1);
      while(digitalRead(ColunaA) == HIGH){
      }//No fica jogando infinitamente a funço acima na tela
    }

    if(digitalRead(ColunaB) == HIGH)
    {
      imprimirCaractere(ln-2,2);
      while(digitalRead(ColunaB) == HIGH){
      }
    }

    if(digitalRead(ColunaC) == HIGH)
    {
      imprimirCaractere(ln-2,3);
      while(digitalRead(ColunaC) == HIGH){
      }
    }

    if(digitalRead(ColunaD) == HIGH)
    {
      imprimirCaractere(ln-2,4);
      while(digitalRead(ColunaD) == HIGH){
      }
    }
  }
  delay(10);
}


void imprimirCaractere(int linha, int coluna)
{
  Serial.print("Caractere: ");
  Serial.println(caracteres[linha -1][coluna -1]);
  delay(10);
}








