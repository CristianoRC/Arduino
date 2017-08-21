/*
 Typical pin layout used:
 ________________________________________________________________________________________
 MFRC522      Arduino       Arduino   Arduino    Arduino          Arduino                |
 Reader/PCD   Uno/101       Mega      Nano v3    Leonardo/Micro   Pro Micro              |
 Signal      Pin          Pin           Pin       Pin        Pin              Pin        |
 ________________________________________________________________________________________|
 RST/Reset   RST          9             5         D9         RESET/ICSP-5     RST        |
 SPI SS      SDA(SS)      10            53        D10        10               10         |
 SPI MOSI    MOSI         11 / ICSP-4   51        D11        ICSP-4           16         |
 SPI MISO    MISO         12 / ICSP-1   50        D12        ICSP-1           14         |
 SPI SCK     SCK          13 / ICSP-3   52        D13        ICSP-3           15         |
 ________________________________________________________________________________________|
 
 Library Version: 1.1.3
 */

#include <SPI.h>
#include <MFRC522.h>

#define UidCartao EC 15 03 6B 
#define UidChaveiro 96 06 00 A4

#define buzzer 3

#define SS_PIN 10
#define RST_PIN 9

String TagID = "";

MFRC522 mfrc522(SS_PIN, RST_PIN);	// Create MFRC522 instance.

void setup() 
{
  Serial.begin(9600);	// Inicia a serial
  SPI.begin();		// Inicia  SPI bus
  mfrc522.PCD_Init();	// Inicia MFRC522
  pinMode(buzzer,OUTPUT);

  Serial.println("Aproxime o seu cartao do leitor...");
  Serial.println();
}

void loop() 
{
  if (mfrc522.PICC_IsNewCardPresent())   // Verifica se ha novos cartes para leitura
  {
    mfrc522.PICC_ReadCardSerial(); //Le um novo carto

    //Mostra UID na serial
    Serial.print("UID da tag :");

    for (byte i = 0; i < mfrc522.uid.size; i++) 
    {
      TagID.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
      TagID.concat(String(mfrc522.uid.uidByte[i], HEX));
    }

    TagID.toUpperCase();
    Serial.println(TagID);

    digitalWrite(buzzer,HIGH);
    delay(20);
    digitalWrite(buzzer,LOW);  
  }  
  
  TagID = "";
  delay(500);

} 












