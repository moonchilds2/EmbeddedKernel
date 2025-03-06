#ifndef DRV_LED_H
#define DRV_LED_H

#include "dd_types.h"
#include "kernel.h"
#include <Arduino.h> // Adicione esta linha

// Lista de funções do driver
enum {
    LED_SET, LED_FLIP, LED_END
};

// Função de acesso ao driver
driver* getLedDriver(void);

#endif