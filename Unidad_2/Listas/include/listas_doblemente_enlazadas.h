#ifndef FUNCIONES_H
#define FUNCIONES_H

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

#endif