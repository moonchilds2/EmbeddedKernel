#include <TimerOne.h>
#include "include/kernel.h"
#include "include/drv_led.h"
#include "include/drv_button.h"

// Declaração dos drivers
driver* led;
driver* botao;

void setup() {
    // Declara os processos
    process p1 = {tst1, 1, 0}; // Processo para os LEDs
    process p2 = {tst2, 1, 0}; // Processo para o botão

    // Inicializa os drivers
    led = getLedDriver();
    led->initFunc((void*)18); // Inicializa o LED no pino 18

    botao = getButtonDriver();
    botao->initFunc((void*)2); // Configura o botão no pino 2

    // Inicialização dos periféricos
    Serial.begin(9600);

    // Inicializa o kernel
    kernelInit();

    // Adição dos processos no kernel
    if (kernelAddProc(&p1) == SUCCESS) {
        Serial.println("Processo do LED adicionado!");
    }

    if (kernelAddProc(&p2) == SUCCESS) {
        Serial.println("Processo do botão adicionado!");
    }

    // Configura o timer para gerar interrupções a cada 1 segundo (1000000 microssegundos)
    Timer1.initialize(1000000);
    Timer1.attachInterrupt(tick); // Associa a função tick() à interrupção do timer

    // Execução do kernel
    kernelLoop();
}

// Função chamada na interrupção do timer
void tick() {
    kernelTick(); // Atualiza os deadlines dos processos
}

// Processo para controlar os LEDs
char tst1(void) {
    // Alterna o estado de cada LED
    led->funcoes[LED_FLIP]((void*)18); // Alterna o LED no pino 18
    led->funcoes[LED_FLIP]((void*)19); // Alterna o LED no pino 19
    led->funcoes[LED_FLIP]((void*)20); // Alterna o LED no pino 20
    led->funcoes[LED_FLIP]((void*)21); // Alterna o LED no pino 21

    Serial.println("Alternando LEDs...");
    return REPEAT; // Repete o processo
}

// Processo para ler o estado do botão
char tst2(void) {
    int estado = botao->funcoes[BUTTON_READ]((void*)2); // Lê o estado do botão no pino 2
    if (estado == 1) {
        Serial.println("Botão pressionado!");
    } else {
        Serial.println("Botão solto!");
    }
    return REPEAT; // Repete o processo
}

// Loop vazio (o kernel já está sendo executado em kernelLoop())
void loop() {}