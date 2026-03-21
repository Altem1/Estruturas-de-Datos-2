#ifndef LISTAS_CIRCULARES_DOBLEMENTE_ENLAZADAS_H
#define LISTAS_CIRCULARES_DOBLEMENTE_ENLAZADAS_H

#include <stdio.h>
#include <stdlib.h>

typedef int tipo;

typedef struct nodD{
    tipo info;
    struct nodD *sig, *ant;
}TNodoD;

//Listas Circulares Doblemente Enlazadas
TNodoD *crea_nodoD(tipo d);
void imprime_lista_cir_doble(TNodoD *cab);
void inserta_inicio_finalDC(TNodoD **cab, tipo d, int band);
void inserta_ordenadaDC(TNodoD **cab, tipo d);
tipo elimina_inicioDC(TNodoD **cab);
tipo elimina_finalDC(TNodoD **cab);
int elimina_xDC(TNodoD **cab, tipo x);

#endif