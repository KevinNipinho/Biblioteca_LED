#include <Arduino.h>
#include <LED.h>

Led ledA(45);

void setup() 
{
  //Náo é necessário nada aqui.
}

void loop() 
{
  ledA.ligar(3000); // Liga o LED e desliga depois da quantidade declarada de tempo em milissegundos.
  ledA.update(); // Verifica e atualiza o estado do LED.
}
