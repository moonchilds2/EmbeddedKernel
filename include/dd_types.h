//cabeçalho que define tipos de dados e estruturas relacionados aos drivers;
//serve como interface para padronizar a criação e o uso de drivers no sistema;

#ifndef DD_TYPES_H
#define DD_TYPES_H
		
	//Ponteiro de funaoo para driver
	typedef char(*ptrFuncDrv)(void * parameters); //recebe parametro void* e retorna char 
	
	
	//estrutura do driver
	typedef struct{
		char id;
		ptrFuncDrv *funcoes; //array de ponteiros para funcoes, onde cada funcao representa uma operacao especifica q o driver realiza
							 // por ex. no caso do led seria: ligar, desligar, alternar, etc.

		ptrFuncDrv initFunc; // ponteiro para funcao de inicializacao do driver, chamada p config. hardware e preparar driver p uso.
	}driver;
	
	
	// retorna ponteiro para um driver, e sera usado para criar funcoes para retornar drivers especificos
	typedef driver*(ptrGetDrv)(void);
	
#endif
