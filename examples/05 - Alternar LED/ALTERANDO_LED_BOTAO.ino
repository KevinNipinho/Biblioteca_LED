#include <Arduino.h>
#include <LED.h>

Led ledA(45); // Declarada o LED no pino 45

const uint8_t pinBotao = 0; // Declarado pino do botáo

void setup() 
{
  // Não é necessário nada aqui.
}

void loop() 
{
  bool estadoAtualBotao = digitalRead(pinBotao);
  static bool estadoAnteriorBotao = HIGH;

  if(estadoAnteriorBotao && !estadoAtualBotao)
  {
    ledA.alterar(); // altera o estado do LED
  }
  estadoAnteriorBotao = estadoAtualBotao;

  ledA.update(); // Verifica e atualiza o estado do LED
}


