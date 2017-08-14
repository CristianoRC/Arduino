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


void setup() {                
  pinMode(2, OUTPUT);//A   
  pinMode(3, OUTPUT);//b
  pinMode(4, OUTPUT);//B
  pinMode(5, OUTPUT);//C
  pinMode(6, OUTPUT);//D
  pinMode(7, OUTPUT);//E
  pinMode(8, OUTPUT);//F
  pinMode(9, OUTPUT);//Ponto

  digitalWrite(9, HIGH); //Desligando o ponto
}
void sevenSegWrite(byte digit)
{
  byte pin = 2; //Pino inicial do arduino
  
  for (byte segCount = 0; segCount < 7; ++segCount) 
  {
    digitalWrite(pin, seven_seg_digits[digit][segCount]);//Pega o valor ma matriz e joga na porta digital;
    ++pin;//Passa para o proximo pino  
  } 
} 

//Conta de 0 a 9
void loop() {   
  for (byte count = 0; count < 17; count++) 
  {
    delay(1000);
    sevenSegWrite(count - 1); 
  }

  delay(4000);   // Aguarda 4 segundos para recomeçar a contar
}  




