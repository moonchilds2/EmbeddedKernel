#include "include/drv_button.h"

static driver meu_botao;          // Instância do driver de botão
static ptrFuncDrv my_funcs[BUTTON_END]; // Array de funções do driver

// Função para ler o estado do botão
char readButton(void* parameters) {
    // Converte o parâmetro para o pino desejado
    uint8_t pino = (uint8_t)parameters;

    // Lê o estado do pino (HIGH ou LOW)
    if (digitalRead(pino) == HIGH) {
        return 1; // Botão pressionado
    } else {
        return 0; // Botão solto
    }
}

// Função de inicialização do driver
char initButton(void* parameters) {
    // Converte o parâmetro para o pino desejado
    uint8_t pino = (uint8_t)parameters;

    // Configura o pino como entrada
    pinMode(pino, INPUT);

    // Define o ID do driver
    meu_botao.id = pino;

    return SUCCESS;
}

// Função para obter o driver de botão
driver* getButtonDriver(void) {
    meu_botao.initFunc = initButton;      // Associa a função de inicialização
    my_funcs[BUTTON_READ] = readButton;  // Associa a função de leitura
    meu_botao.funcoes = my_funcs;        // Associa o array de funções
    return &meu_botao;                   // Retorna o driver
}