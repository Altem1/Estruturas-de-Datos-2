#ifndef LISTAS_CIRCULARES_DOBLEMENTE_ENLAZADAS_H
#define LISTAS_CIRCULARES_DOBLEMENTE_ENLAZADAS_H

#include <stdio.h>
#include <stdlib.h>

typedef int tipo;

typedef struct nodD{
    tipo info;
    struct nodD *sig, *ant;
}TNodoD;



#endif