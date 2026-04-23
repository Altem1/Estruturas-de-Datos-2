#ifndef GRAFOVR_H
#define GRAFOVR_H

#include <stdio.h>
#include <stdlib.h>

typedef int Tipo; 

typedef struct list {
    int destino;
    struct list *siguiente;  
} TLista;

typedef struct ar {
    Tipo dato;
    TLista *conexion;    
} TArreglo;

typedef struct grafo {
    int num_vertices;   
    int capacidad;  
    TArreglo *conexiones; 
} TGrafo;

void crea_grafo(TGrafo *g);
void inserta_vertice(TGrafo *g, Tipo dato);
void insertar_conexion(TGrafo *g, Tipo origen, Tipo destino);

int existe_vertice(TGrafo *g, Tipo dato);
int existe_conexion(TGrafo *g, Tipo origen, Tipo destino);
int buscar_indice(TGrafo *g, Tipo dato);

void inserta_inicio(TLista **c, Tipo destino);
TLista *crea_nodoA(Tipo destino);

void busqueda_prof_VR(TGrafo *g, Tipo vo);
void bprof_VR(TGrafo *g, int v, int *vis);

void imprime_grafo(TGrafo *g);
void destruye_grafo(TGrafo *g);

#endif