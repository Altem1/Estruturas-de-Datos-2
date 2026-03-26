#ifndef LISTAS_DE_LISTAS_H
#define LISTAS_DE_LISTAS_H

#include <stdio.h>
#include <stdlib.h>

typedef struct nodoA{
    int clave;
    char *nombre;
    struct nodoA *sig;
}TNAlumno;

typedef struct nodoC{
  
    char *carrera;
    TNAlumno lista;
	struct nodoC *sig;
}TNCarrera;

void inserta_alumno(int clave, char *nombre, char *carrera, TNCarrera **Cab);
TNCarrera *inserta_ordenado(TNCarrera **c, char *carrera);
void inserta_ordenadoA(TNAlumno **cab, int clave, char *nombre);
void inserta_inicio(TNAlumno **c, int clave, char *nombre);
TNCarrera *crea_nodoC(char *carrera);
TNAlumno *crea_nodoA(char *c, int clave, char *nombre);
void buscar_clave(TNCarrera **cab, int clave, TNAlumno **aux);
void elimina_x_clave(TNCarrera **c, int clave);

#endif
