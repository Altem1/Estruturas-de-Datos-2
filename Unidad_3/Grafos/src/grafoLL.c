#include "../include/grafoLL.h"
#include "../include/grafo.h"

TNodoV *crea_grafoLL(TGrafoMR g){

    return convierte_mr_a_ll(g);

}

TNodoV *convierte_mr_a_ll(TGrafoMR g){

    int r, c;
    TNodoV *g1=NULL;
    TNodoV *o, *d;

    for (int i=0; i< g.nv; i++){
        inserta_vertice(&g1, *(g.vertices + i));
    }

    for (r = 0, o = g1 ; o != NULL ; r++, o = o -> siguiente ){

        for(c = 0, d = g1 ; d != NULL ; c++, d = d -> siguiente){

            if (*(*(g.mR+r)+c)==1){
                inserta_arista(&o -> abajo, d);
            }

        }

    }

    return g1;

}

TNodoV *crea_nodoV(int v){
    TNodoV *aux;
    aux = (TNodoV*) malloc(sizeof(TNodoV));
    if(aux){
        aux -> vertice = v;
        aux -> siguiente = NULL;
        aux -> abajo = NULL;
    }
    return aux;
}

void inserta_lista(TNodoV **cab, TNodoV *nuevo){

    if(!nuevo){
        return;
    }

    if(!*cab){
        *cab = nuevo;
    }else{
        inserta_lista(&((*cab) -> siguiente), nuevo);
    }

}

void inserta_vertice(TNodoV **g, int v){

    TNodoV *aux;

    aux = crea_nodoV(v);
    if(aux){
        inserta_lista(g, aux);
    }

}

void inserta_arista(TNodoA **cab, TNodoV *d){

    TNodoA *nuevo;

    nuevo = crea_nodoA(d);
    if(!nuevo){
        return;
    }

    if(!*cab){
        *cab = nuevo;
        return;
    }

    TNodoA *aux = *cab;
    while(aux -> siguiente){
        aux = aux -> siguiente;
    }
    aux -> siguiente = nuevo;

}

TNodoA *crea_nodoA(TNodoV *d){
    TNodoA *aux;
    aux = (TNodoA*) malloc(sizeof(TNodoA));
    if(aux){
        aux -> arriba = d;
        aux ->siguiente = NULL;
    }
    return (aux);
}

void imprime_grafoLL(TNodoV *g){

    TNodoV *o;
    TNodoA *a;

    for (o = g; o != NULL; o = o -> siguiente){
        for (a = o -> abajo; a != NULL; a = a -> siguiente){
            printf("%c -> %c\n");
            o -> vertice, a -> arriba -> vertice;
        }
    }

}

