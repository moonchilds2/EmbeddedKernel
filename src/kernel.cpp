#include "include/drv_led.h"

static driver meu_cartao; // Instância do driver de LED
static ptrFuncDrv my_funcs[LED_END];
static uint8_t leds[] = {18, 19, 20, 21}; // Array de pinos dos LEDs
static uint8_t num_leds = sizeof(leds) / sizeof(leds[0]); // Número de LEDs

// Função para definir o estado do LED
char changePORT(void* parameters) {
    uint8_t pino = (uint8_t)parameters; // Converte o parâmetro para o pino desejado
    digitalWrite(pino, HIGH); // Liga o LED
    return SUCCESS;
}

// Função para alternar o estado do LED
char inverte(void* parameters) {
    uint8_t pino = (uint8_t)parameters; // Converte o parâmetro para o pino desejado
    digitalWrite(pino, !digitalRead(pino)); // Alterna o estado do LED
    return SUCCESS;
}

// Função de inicialização do driver de LED
char initGenerico(void* parameters) {
    for (uint8_t i = 0; i < num_leds; i++) {
        pinMode(leds[i], OUTPUT); // Configura cada pino como saída
    }
    meu_cartao.id = 0; // Define o ID do driver
    return SUCCESS;
}

// Função para obter o driver de LED
driver* getLedDriver(void) {
    meu_cartao.initFunc = initGenerico; // Associa a função de inicialização
    my_funcs[LED_SET] = changePORT; // Associa a função para definir o estado do LED
    my_funcs[LED_FLIP] = inverte; // Associa a função para alternar o estado do LED
    meu_cartao.funcoes = my_funcs; // Associa o array de funções ao driver
    return &meu_cartao; // Retorna o driver
}