//Anodo comum

#define soma 10
#define subtracao 11
                             //    A B C D E F G
byte seven_seg_digits[16][7] = { { 0,0,0,0,0,0,1 },  // = 0
                                 { 1,0,0,1,1,1,1 },  // = 1
                                 { 0,0,1,0,0,1,0 },  // = 2
                                 { 0,0,0,0,1,1,0 },  // = 3
                                 { 1,0,0,1,1,0,0 },  // = 4
                                 { 0,1,0,0,1,0,0 },  // = 5
                                 { 0,1,0,0,0,0,0 },  // = 6
                                 { 0,0,0,1,1,1,1 },  // = 7
                                 { 0,0,0,0,0,0,0 },  // = 8
                                 { 0,0,0,1,1,0,0 },  // = 9
                                 { 0,0,0,1,0,0,0 },  // = A
                                 { 1,1,0,0,0,0,0 },  // = B
                                 { 0,1,1,0,0,0,1 },  // = C
                                 { 1,0,0,0,0,1,0 },  // = D
                                 { 0,1,1,0,0,0,0 },  // = E
                                 { 0,1,1,1,0,0,0 }   // = F
                               };

int contador = 0;


void setup() 
{                
  pinMode(2, OUTPUT);//A   
  pinMode(3, OUTPUT);//B
  pinMode(4, OUTPUT);//C
  pinMode(5, OUTPUT);//D
  pinMode(6, OUTPUT);//E
  pinMode(7, OUTPUT);//F
  pinMode(8, OUTPUT);//G
  pinMode(9, OUTPUT);//Ponto
  pinMode(soma,INPUT_PULLUP);
  pinMode(subtracao,INPUT_PULLUP);
  digitalWrite(9, HIGH); //Desligando o ponto

  Serial.begin(9600);
}

void loop() 
{ 

  if(digitalRead(soma) == LOW)//LOW, pois ele  Pull UP
  {

    contador++;  

    if(contador  == 16 )
    {
      contador = 0; 
    }

    sevenSegWrite(contador);

    Serial.println(contador,HEX); 

    delay(200);
  }
  else if(digitalRead(subtracao) == LOW) 
  {
    contador --;

    if(contador < 0)
    {
      contador = 15; 
    }

    sevenSegWrite(contador);

    Serial.println(contador,HEX); 

    delay(200);   
  }  
}  


void sevenSegWrite(byte digit)
{
  byte pin = 2; //Pino inicial do arduino

  for (byte segCount = 0; segCount < 7; segCount++) 
  {
    digitalWrite(pin, seven_seg_digits[digit][segCount]);//Pega o valor ma matriz e joga no pino da vez;
    pin++;//Passa para o proximo pino  
  } 
} 
