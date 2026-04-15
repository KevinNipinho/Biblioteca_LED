#include <Arduino.h>
#include <LED.h>

Led ledA(45); // Declarada o LED no pino 45

const uint8_t pinBotao = 0; // Declarado pino do botáo

void setup() 
{
  ledA.piscar(3,21); // Pisca o LED 21 vezes em 3 Hz.
}

void loop() 
{
  ledA.update(); // Verifica e atualiza o estado do LED
}


