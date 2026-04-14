#ifndef LED_h
#define LED_h

#include <Arduino.h>

/**
 * @class Led
 * @brief Classe para controle náo bloqueante de um LED.
 * Permite ligar, desligar, ligar por tempo determindo,
 * piscar continuamente e piscar por quantidade definida.
 *
 * @note O metódo update() deve ser chamado continuamente  dentro do loop().
 */
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

    /**
     * @brief Processa a lógica de piscada do LED.
     */
    void funcaoPiscar();

    /**
     * @brief Processa a lógica de RESET do programa.
     */
    void funcaoReset();

    /**
     * @brief Processa o desligamento temporizado.
     */
    void funcaoDesligamento();

public:
    /**
     * @brief Constroi um objeto Led.
     * @param pin Número do pino digital onde o LED está conectado
     */
    Led(uint8_t pin);

    /**
     * @brief liga o LED continuamente.
     */
    void ligar();

    /**
     * @brief liga o LED por um determinado tempo.
     * @param tempoLigado_ms tempo, em milissegundos que o LED ficará ligado.
     */
    void ligar(uint32_t tempoLigado_ms);

    /**
     * @brief Desliga o LED e cancela os modos automáticos.
     */
    void desligar();

    /**
     * @brief Inicia uma piscada continua em 1 Hz.
     */
    void piscar();

    /**
     * @brief Pisca o LED uma quantidade definida de vezes.
     * @param frenquencia frenquência de piscada em HZ do LED.
     */
    void piscar(float frequencia);

    /**
     * @brief Pisca o LED uma quantidade definida de vezes.
     * @param frequencia frequência da piscada em HZ do LED.
     * @param repeticoes quantidade total de piscadas do LED.
     */
    void piscar(float frequencia, uint16_t repeticoes);

    /**
     * @brief Retorna o estado atual do LED.
     */
    bool getEstado();

    /**
     * @brief Retorna o pino atual em que está conectado o LED.
     */
    uint8_t getPino();

     /**
     * @brief Define manualmente o estado do LED em ligado ou desligado.
     * @param estado HIGH para ligado, LOW para desligado.
     */
    void setEstado(bool estado);

    /**
     * @brief Define o LED com o estado oposto do atual.
     */
    void alterar();

    /**
     * @brief Atualiza o programa e estados do LED.
     */
    void update();
};

#endif