#ifndef LISTAS_DE_LISTAS_H
#define LISTAS_DE_LISTAS_H

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

#endif
