#ifndef DOBLEMENTE_ENLAZADO_H
#define DOBLEMENTE_ENLAZADO_H
#include <stdio.h>
#include <stdlib.h>

typedef int numero;

//Estructura para la ruta del tren
typedef struct nodoD{
    int estacion;
    struct nodoD *siguiente;
    struct nodoD *anterior;
}TNodoD;

typedef struct {
    TNodoD *ini, *fin;
}TCabs;

TNodoD *crea_nodoD(numero estacion);
void inicializa(TCabs **cabs);
void inserta_finalD(TCabs *cabs, numero estacion);
void imprimer(TCabs *cabs);

#endif