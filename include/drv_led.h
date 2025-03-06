#ifndef DRV_LED_H
	#define DRV_LED_H
	#include "dd_types.h"
	#include "kernel.h"
	#include <avr/io.h>
	
	//lista de funcoes do driver
	enum {
		
		LED_SET, LED_FLIP, LED_END
	};
	
	//funcao de acesso ao driver
	
	driver * getLedDriver(void);
		
	
#endif
