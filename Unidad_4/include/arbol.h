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

#endif