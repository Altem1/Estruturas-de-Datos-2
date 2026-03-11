#ifndef LISTAS_DOBLEMENTE_ENLAZADAS_H
#define LISTAS_DOBLEMENTE_ENLAZADAS_H

#include <stdio.h>
#include <stdlib.h>

typedef int tipo;

typedef struct nodD{
    tipo info;
    struct nodD *sig, *ant;
}TNodoD;

typedef struct {
    TNodoD *ini, *fin;
}TCabs;

TNodoD *crea_nodo(tipo d);
void inicializa(TCabs *cabs);
void inserta_inicio(TCabs *cabs, tipo d);
void inserta_final(TCabs *cabs, tipo d);
void inserta_ordenada(TCabs *cabs, tipo d);
tipo elimina_inicio (TCabs *cabs);
tipo elimina_final (TCabs *cabs);
int elimina_x(TCabs *cabs, tipo x);

#endif