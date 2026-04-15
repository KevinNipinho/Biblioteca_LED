#include <Arduino.h>
#include <LED.h>

Led ledA(45); // Declarada o LED no pino 45

const uint8_t pinBotao = 0; // Declarado pino do botáo

void setup() 
{
  ledA.piscar(10,1000); // Pisca o LED 1000 vezes em 10 Hz.
}

void loop() 
{
  ledA.update(); // Atualizando o estado do LED

  if(millis() >= 5000) // verifica o tempo passado
  {
    ledA.desligar(); // interrompe as piscadas e desliga o LED
  }
}


