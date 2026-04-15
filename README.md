# Biblioteca LED

Biblioteca simples para controle não bloqueante de LEDs com Arduino e ESP32.

A classe `Led` permite:

- ligar o LED.
- ligar O LED por tempo determinado.
- desligar o LED.
- alternar estado do LED.
- piscar continuamente por tempo indeterminado.
- piscar uma quantidade definida de vezes e em Hz.

O funcionamento é não bloqueante, usando `millis()`.  
Por isso, o método `update()` deve ser chamado repetidamente dentro do `loop()`.

---

## Estrutura da biblioteca

```text
LED/
├── library.json
├── README.md
├── LICENSE
├── src/
│   ├── LED.h
│   └── LED.cpp
└── examples/
```

---

## Authors

- [@KevinNipinho](https://github.com/KevinNipinho)