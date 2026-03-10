#ifndef ALGORITMOS_H
#define ALGORITMOS_H

#include <stdio.h>
#include <stdlib.h>

typedef int tipo;

typedef struct nodo{
	tipo info;
	struct nodo *sig;
}TNodo;

TNodo *crea_nodo(tipo d);
void imprime_lista_cir(TNodo *cab);

#endif