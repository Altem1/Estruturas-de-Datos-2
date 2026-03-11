#ifndef LISTAS_CIRCULARES_H
#define LISTAS_CIRCULARES_H

#include <stdio.h>
#include <stdlib.h>

typedef int tipo;

typedef struct nodo{
	tipo info;
	struct nodo *sig;
}TNodo;

void imprime_lista_cir(TNodo *cab);
void inserta_inicio_cir_ini_fin(TNodo **cab, tipo d, int band);
void inserta_ord_cir(TNodo **cab, tipo d);
void elimina_inicio_final_cir(TNodo **cab, int band);
void elimina_x_cir(TNodo **cab, tipo d);

#endif