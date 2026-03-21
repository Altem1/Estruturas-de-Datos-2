#ifndef LISTA_SIMPLE_H
#define LISTA_SIMPLE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    char direccion;
    int pasos;
    struct nodo *siguiente;
}TNodoS;

TNodoS *crea_nodoL(char direccion, int pasos);
void imprime_lista(TNodoS *cab);
void inserta_finalL(TNodoS **c, char direccion, int pasos);
void elimina_inicio(TNodoS **c);

#endif