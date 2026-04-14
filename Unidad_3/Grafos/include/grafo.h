#ifndef GRAFOS_H
#define GRAFOS_H

#include <stdio.h>
#include <stdlib.h>

typedef int tipo;

typedef struct{
    tipo *vertices;
    int **mR;
    int nv;
}TGrafoMR;

#endif
