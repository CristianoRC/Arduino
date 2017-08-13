const int botaoVerde = 2;
const int botaoVermelho = 3;

int botaoVerdeStatus = 0;
int botaoVermelhoStatus = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(botaoVerde, INPUT);
  pinMode(botaoVermelho,INPUT);
}


void loop()
{
    botaoVerdeStatus = digitalRead(botaoVerde);
    botaoVermelhoStatus = digitalRead(botaoVermelho);  
  
    
    if(botaoVerdeStatus)
    {
      Serial.println("Botao verde pressionado!");
    }
   
    if(botaoVermelhoStatus)
    {
       Serial.println("Botao vermelho pressionado!"); 
    }
    delay(200);
 }
