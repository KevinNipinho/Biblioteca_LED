#ifndef LED_h
#define LED_h

#include <Arduino.h>


class Led
{

private:
    uint8_t pino;
    bool estado; 
    bool desligarPorTempo;
    uint32_t desligarNoMomento = false;

    uint32_t tempoAnteriorPiscar;
    uint32_t tempoEspera;
    bool estadoPiscar;
    uint16_t repeticoes;

    bool Reset;

    void funcaoPiscar();
    void funcaoReset();
    void funcaoDesligamento();

public:
    Led (uint8_t pin); // Método Construtor, Deverá ter o mesmo nome da Classe 
    
    void ligar(); //? OK
    void ligar(uint32_t tempoLigado_ms); //? OK

    void desligar();//? OK
    
    void piscar();//? OK
    void piscar(float frequencia);//? OK
    void piscar(float frequencia, uint16_t repeticoes);//? OK
    
    bool getEstado();//? OK
    uint8_t getPino();//? OK

    void setEstado(bool estado);//? OK

    void alterar();//? OK

    void update(); //? OK
};

#endif