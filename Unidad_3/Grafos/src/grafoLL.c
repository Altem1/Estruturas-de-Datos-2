#include "../include/grafoLL.h"
#include "../include/grafo.h"

static int contar_vertices(TNodoV *g){
    int total = 0;
    for(TNodoV *aux = g; aux != NULL; aux = aux->siguiente){
        total++;
    }
    return total;
}

static int indice_de_nodo(TNodoV **vertices, int n, TNodoV *nodo){
    for(int i = 0; i < n; i++){
        if(*(vertices + i) == nodo){
            return i;
        }
    }
    return -1;
}

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

void busqueda_amplitud_LL(TNodoV *g, int vo){
    if(!g){
        return;
    }

    int n = contar_vertices(g);
    if(n <= 0){
        return;
    }

    TNodoV **vertices = (TNodoV**)malloc(sizeof(TNodoV*) * n);
    int *visitados = (int*)calloc(n, sizeof(int));
    int *cola = (int*)malloc(sizeof(int) * n);

    if(!vertices || !visitados || !cola){
        free(vertices);
        free(visitados);
        free(cola);
        return;
    }

    int inicio = -1;
    TNodoV *aux = g;
    for(int i = 0; i < n && aux != NULL; i++, aux = aux->siguiente){
        *(vertices + i) = aux;
        if(aux->vertice == vo){
            inicio = i;
        }
    }

    if(inicio == -1){
        free(vertices);
        free(visitados);
        free(cola);
        return;
    }

    int frente = 0;
    int fin = 0;
    *(visitados + inicio) = 1;
    *(cola + fin++) = inicio;

    while(frente < fin){
        int actual = *(cola + frente++);
        TNodoV *origen = *(vertices + actual);
        printf("%d -> ", origen->vertice);

        for(TNodoA *arista = origen->abajo; arista != NULL; arista = arista->siguiente){
            int idx = indice_de_nodo(vertices, n, arista->arriba);
            if(idx != -1 && *(visitados + idx) == 0){
                *(visitados + idx) = 1;
                *(cola + fin++) = idx;
            }
        }
    }

    free(vertices);
    free(visitados);
    free(cola);
}

