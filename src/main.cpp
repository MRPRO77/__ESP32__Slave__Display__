/*******************************************************************************
   Título:      TCC  Engenharia Mecatrônica.

   Descrição:   C L P   ---  I H M

   Processador: ROBOCORE ESP32 Slave
   
   Geração Multifolhas


   Desenvolvido: MRPRO Tecnologia e Automação

   Autor: Tecnologo. Marcelo Rodrigues     Crea-SP 5070505617

   Data de Inicio: 02/09/2023       Versão:   2023.1.0

        

 
*******************************************************************************/  
/* ============================================================================  
                                                              
                                       _                      
                                      / \                     
                                     |oo >                    
                                     _\=/_                    
                    ___         #   /  _  \   #               
                   /<> \         \\//|/.\|\\//                
                 _|_____|_        \/  \_/  \/                 
                | | === | |          |\ /|                    
                |_|  0  |_|          \_ _/                    
                 ||  0  ||           | | |                    
                 ||__*__||           | | |                    
                |* \___/ *|          []|[]                    
                /=\ /=\ /=\          | | |                    
________________[_]_[_]_[_]_________/_]_[_\___________________________________
                                                                             
============================================================================== */


// ========================================================================================================
// --- Bibliotecas Auxiliares ---
#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include "wire.h"


#define myAdress 0x07

const int LED_ESP32 = 13;

#define ReleledPin 32 // numero do pino onde o LED esta conectado
// funcao executada sempre que algum dado e recebido no barramento I2C
// vide "void setup()"
void receiveEvent(int howMany) {
  // verifica se existem dados para serem lidos no barramento I2C
  if (Wire.available()) {
    // le o byte recebido
    char received = Wire.read();

    // se o byte recebido for igual a 0, apaga o LED
    if (received == 0) {
      digitalWrite(ReleledPin, LOW);
    }

    // se o byte recebido for igual a 1 acende o LED
    if (received == 1) {
      digitalWrite(ReleledPin, HIGH);
    }
  }
}





void setup() {
  
  Serial.begin(115200);
  // ingressa ao barramento I2C com o endereço definido no myAdress (0x07)
  Wire.begin(myAdress);
 

  //Registra um evento para ser chamado quando chegar algum dado via I2C
  Wire.onReceive(receiveEvent);

  pinMode(ReleledPin, OUTPUT);  // configura o pino do LED como saida
  digitalWrite(ReleledPin,HIGH);
}

void loop() {
  // nada para ser exexutado
}

