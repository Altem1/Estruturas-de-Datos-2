#include "../include/d_enl.h"

TNodoD *crea_nodoD(numero estacion){

    TNodoD *aux;
    aux = (TNodoD *) malloc (sizeof(TNodoD));

    if(aux != NULL){
        aux -> estacion = estacion;
        aux -> siguiente = aux -> anterior = NULL;
    }
    
    return aux;
}

void inicializa(TCabs **cabs){

    *cabs = (TCabs *) malloc(sizeof(TCabs));
    if (*cabs != NULL) {
        (*cabs) -> ini = (*cabs) -> fin = NULL;
    }

}

void inserta_finalD(TCabs *cabs, numero estacion) {
    TNodoD *nuevo = crea_nodoD(estacion);

    if (nuevo != NULL) {
        // Caso 1: La lista está vacía
        if (cabs->fin == NULL) {
            cabs->ini = cabs->fin = nuevo;
        } 
        // Caso 2: Ya hay elementos
        else {
            nuevo -> anterior = cabs -> fin;
            cabs -> fin -> siguiente = nuevo;
            cabs -> fin = nuevo;
        }
    }
}

void imprimer(TCabs *cabs){

    TNodoD *corre;

    if (cabs == NULL || cabs -> ini == NULL){
        printf("Lista vacia\n");
        return;
    }

    corre = cabs -> ini;

    while (corre != NULL){
        printf("| %d | --> ", corre -> estacion);
        corre = corre ->siguiente;
    }

    printf("NULL\n");

}