#include "LED.H"

Led::Led(uint8_t pin):
    pino (pin),
    estado (LOW),
    desligarPorTempo(false),
    desligarNoMomento(0),
    tempoAnteriorPiscar(0),
    tempoEspera(0),
    estadoPiscar(false),
    repeticoes(0)
{
    pinMode(pin, OUTPUT)
}

void Led::ligar()
{
    Reset = true;
    estado = HIGH;
}
void Led::ligar(uint32_t tempoLigado_ms)
{
    estado = HIGH;
    desligarPorTempo = true;
    desligarNoMomento = (millis() + tempoLigado_ms);
    estadoPiscar = false;
}

void Led::desligar()
{
    Reset = true;
    estado = LOW;
}

void Led::piscar()
{
    estadoPiscar = true;
    tempoEspera = 500;
    tempoAnteriorPiscar = millis();
    estado = HIGH;
    desligarPorTempo = false;
}

void Led::piscar(float frequencia)
{
    estadoPiscar = true;
    tempoEspera = (1000.0f / (2.0f * frequencia));
    tempoAnteriorPiscar = millis();
    estado = HIGH;
    desligarPorTempo = false;
}

void Led::piscar(float frequencia, uint16_t repeticoes)
{
    estadoPiscar = true;
    tempoEspera = (1000.0f / (2.0f * frequencia));
    tempoAnteriorPiscar = millis();
    estado = HIGH;
    this->repeticoes = repeticoes * 2;
    desligarPorTempo = false;
}

void Led::funcaoDesligamento()
{
    if (millis() >= desligarNoMomento)
    {
        estado = LOW;
        desligarPorTempo = false;
    }
}

void Led::funcaoPiscar()
{
    if (millis() - tempoAnteriorPiscar >= tempoEspera)
    {
        estado = !estado;
        tempoAnteriorPiscar = millis();
        if (repeticoes > 0)
        {
            repeticoes--;
            if (repeticoes == 0)
            {
                estadoPiscar = false;
                estado = LOW;
            }
        }
    }
}
void Led::funcaoReset()
{
    estadoPiscar = false;
    desligarPorTempo = false;
}

bool Led::getEstado()
{
    return estado;
}

uint8_t Led::getPino()
{
    return pino;
}

void Led::setEstado(bool estado)
{
    Reset = true;
    this->estado = estado;
}

void Led::alterar()
{
    Reset = true;
    estado = !estado;
}

void Led::update()
{
    if (desligarPorTempo)
        funcaoDesligamento();

    if (estadoPiscar)
        funcaoPiscar();

    if (Reset)
        funcaoReset();

    digitalWrite(pino, estado);
}