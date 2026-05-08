#ifndef ARBOL_H
#define ARBOL_H

#include <stdio.h>
#include <stdlib.h>

typedef int tipo;

typedef struct nodB{
	tipo info;
	struct nodB *izq;
	struct nodB *der;
}TNodoB;

void preorden(TNodoB *r);
void postorden(TNodoB *r);
void inorden(TNodoB *r);
int contarNodos(TNodoB *r);
void busqueda(TNodoB *r, int numero, int *esta);
int contar_hojas(TNodoB *r);
int altura(TNodoB *r);
void elimina_nodo(TNodoB **r, tipo clave);
TNodoB *izq_mas_der(TNodoB **r);

#endif