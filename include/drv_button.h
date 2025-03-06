#ifndef DRV_BUTTON_H
#define DRV_BUTTON_H

#include "dd_types.h"
#include "kernel.h"
#include <avr/io.h>

// Lista de funções do driver
enum {
    BUTTON_READ, // Função para ler o estado do botão
    BUTTON_END   // Fim da enumeração
};

// Função de acesso ao driver
driver* getButtonDriver(void);

#endif