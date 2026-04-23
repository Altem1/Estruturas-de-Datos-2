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

void crea_grafo(TGrafoMR *g, char *nom_arch);
void ingresar_d(char *nom_arch, TGrafoMR *g);
void crea_arreglo2D(int ***ptr2D, int nr, int c);
char *crea_arreglo1D(int n);
int calcular_n_vertices(char *nom_arch);
void imprime_grafoMR(TGrafoMR g);
void agrega_vertice(TGrafoMR *g, int v);
void agrega_relacion(TGrafoMR *g, int o, int d, int tip);

#endif
