byte unidade = 0;
byte dezena = 0;
byte centena = 0;
byte milhar = 0;

                          //A B C D E F G
byte portaSeguimentos[7] = {2,3,4,5,6,7,8}; 

byte portadigitos[4]     = {9,10,11,12};

byte valoresDisplay[4]   = {0,0,0,0};

                              //   A B C D E F G
byte seteSegDigitos[16][7] = {   { 1,1,1,1,1,1,0 },  // = 0
                                 { 0,1,1,0,0,0,0 },  // = 1
                                 { 1,1,0,1,1,0,1 },  // = 2
                                 { 1,1,1,1,0,0,1 },  // = 3
                                 { 0,1,1,0,0,1,1 },  // = 4
                                 { 1,0,1,1,0,1,1 },  // = 5
                                 { 1,0,1,1,1,1,1 },  // = 6
                                 { 1,1,1,0,0,0,0 },  // = 7
                                 { 1,1,1,1,1,1,1 },  // = 8
                                 { 1,1,1,0,0,1,1 },  // = 9
                                 { 1,1,1,0,1,1,1 },  // = A
                                 { 0,0,1,1,1,1,1 },  // = B
                                 { 1,0,0,1,1,1,0 },  // = C
                                 { 0,1,1,1,1,0,1 },  // = D
                                 { 1,0,0,1,1,1,1 },  // = E
                                 { 1,0,0,0,1,1,1 }   // = F
                               };

void setup()
{
  for(int i = 0; i<7; i++)
  {
    pinMode(portaSeguimentos[i], OUTPUT);    
  }

  for(int i = 0; i<5; i++)
  {
    pinMode(portadigitos[i], OUTPUT);    
  }


  pinMode(9,OUTPUT);

  Serial.begin(9600);

}

void loop()
{


  for(int i = 0;i<5;i++)
  {  
    desativarPortaDigitos();

    digitalWrite(portadigitos[i],LOW);

    ativarSeguimentos(valoresDisplay[i]);

    delay(5);
  }
  
  acrescentarValorDisplay();
}

void ativarSeguimentos(int digito)
{ 
  for(int i = 0; i < 7; i++)
  {
    digitalWrite(portaSeguimentos[i],seteSegDigitos[digito][i]);
  } 
}

void desativarPortaDigitos()
{
  for(int i = 0;i<5;i++)
  {
    digitalWrite(portadigitos[i],HIGH);
  }
}


void acrescentarValorDisplay()
{
  unidade++;
  
  if(unidade > 9)
  {
    dezena++;

    unidade = 0; 
  }

  if(dezena > 9)
  {
    centena++;

    dezena = 0; 
  }

  if(centena > 9)
  {
    milhar++;

    centena = 0; 
  }

  if(milhar > 9)
  {
    unidade = 0;
    dezena = 0;
    centena = 0;
    milhar = 0; 
  }

  valoresDisplay[0] = milhar;
  valoresDisplay[1] = centena;
  valoresDisplay[2] = dezena;
  valoresDisplay[3] = unidade;
  
  Serial.print(valoresDisplay[0]);
  Serial.print(valoresDisplay[1]);
  Serial.print(valoresDisplay[2]);
  Serial.println(valoresDisplay[3]);
}

