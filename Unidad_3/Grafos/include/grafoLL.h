#ifndef GRAFOLL_H
#define GRAFOLL_H

#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

typedef int peso;

typedef struct nodv{
		int vertice;
		struct nodv *siguiente;
		struct noda *abajo;
}TNodoV;

//Si tiene peso se agrega la variable que haga la representación
typedef struct nodA{
		//peso costo;
		struct nodA *siguiente;
		TNodoV *arriba;
}TNodoA;

TNodoV *crea_grafoLL(TGrafoMR g);
TNodoV *convierte_mr_a_ll(TGrafoMR g);
TNodoV *crea_nodoV(int v);
TNodoA *crea_nodoA(TNodoV *d);
void inserta_lista(TNodoV **cab, TNodoV *nuevo);
void inserta_vertice(TNodoV **g, int v);
void inserta_arista(TNodoA **cab, TNodoV *d);
void imprime_grafoLL(TNodoV *g);

#endif