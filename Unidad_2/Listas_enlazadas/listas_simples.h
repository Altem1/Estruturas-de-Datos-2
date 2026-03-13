#ifndef LISTAS_SIMPLES_H
#define LISTAS_SIMPLES_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef int tipo;

typedef struct nodo{
	tipo coef;
	tipo exp;
	struct nodo *sig;
}TNodo;

//Listas Simples
TNodo *crea_nodo(tipo coefi, tipo expo);
void imprime_lista(TNodo *cab);
void inserta_inicio(TNodo **cab, tipo coefi, tipo expo);
void inserta_final(TNodo **c, tipo coefi, tipo expo);
void inserta_finalR(TNodo **c, tipo coefi, tipo expo);
void inserta_ordenado(TNodo **C, tipo coefi, tipo expo);
void inserta_ordenadoR(TNodo **C, tipo coefi, tipo expo);
void elimina_inicio(TNodo **c);
void elimina_final(TNodo **c);
void elimina_finalR(TNodo **c);
int elimina_x(TNodo **cab, tipo coefi, tipo expo);   
int elimina_xR(TNodo **cab, tipo coefi, tipo expo);

#endif