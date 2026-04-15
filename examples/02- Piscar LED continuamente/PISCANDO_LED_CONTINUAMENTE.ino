#include <Arduino.h>
#include <LED.h>

Led ledA(45); // Declarada o LED no pino 45

void setup() 
{
  ledA.piscar(); // Pisca o LED uma quantidade inderteminada de vezes em 1 Hz.
}

void loop() 
{
  ledA.update(); // Atualizando o estado do LED
}
