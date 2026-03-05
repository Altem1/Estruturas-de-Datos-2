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

TNodoD *crea_nodo(tipo d){

    TNodoD *aux;
    aux = (TNodoD *) malloc (sizeof(TNodoD));

    if(aux != NULL){
        aux -> info = d;
        aux ->sig = aux -> ant = NULL;
    }
    
    return aux;
}

void inicializa(TCabs *cabs){

    cabs -> ini = cabs -> fin = NULL;

}

void inserta_ordenada(TCabs *cabs, tipo d){

    TNodoD *corre, *aux;
    aux = crea_nodo;

    if( aux ){

        if(cabs -> ini == NULL || d < cabs -> ini -> info){

        inserta_inicio(cabs, d);

        }
        else if(d > cabs -> fin -> info){
            insertaFinal(cabs, d);
        }else{

            corre = cabs -> ini;

            while(corre -> info < d){
                corre = corre-> sig;
            }

            aux -> sig = corre;
            aux -> ant = corre -> ant;
            corre -> ant -> sig = aux;
            corre -> ant = aux;

        }
    }
}

tipo elimina_inicio (TCabs *cabs){

    TNodoD *aux;
    tipo inf;

    if( cabs -> ini ){

        aux = cabs -> ini;
        cabs -> ini = aux -> sig;

        if( cabs -> ini == NULL ){
            cabs -> fin = NULL;
        }

    }

    inf = aux -> info;
    free (aux);
    return inf;

}

tipo elimina_final (TCabs *cabs){

    TNodoD *aux;
    tipo inf;

    if( cabs -> fin ){

        aux = cabs -> fin;
        cabs -> fin = aux -> ant;

        if( cabs -> fin == NULL ){
            cabs -> ini = NULL;
        }

    }

    inf = aux -> info;
    free (aux);
    return inf;

}

//Tarea elimina x 
int elimina_x(TCabs *cabs, tipo x) {
    TNodoD *corre;
    int band = -1; // se regresa -1 en dado caso que no encuentre x

    if (cabs->ini != NULL) {// verifico que tenga algun dato
        
        if (cabs->ini->info == x ) {// si en caso que en la cabecera de inicio -> info este el dato x
            return elimina_inicio(cabs); //se elimina
            band = 1;
        }
        
        if (cabs->fin->info == x) {//si en caso que en la cabecera del final -> info este el dato x
            return elimina_final(cabs); //se elimina
            band = 1;
        }

        corre = cabs->ini->sig; //como ya comprobamos que x no esta en el inicio
        //entonces se le asigna la siguiente direccion
        while (corre != NULL && corre->info != x) {//mientras corre no llegue al final y no encuentre info
            corre = corre->sig;//seguira corriendo hasta que encuentre x
        }
        //for(corre = cabs -> ini; corre != NULL && corre -> info != x; corre = corre -> sig); //busqueda
        //en caso de que encuentre x
        if (corre != NULL) {
            corre->ant->sig = corre->sig; //se quita el nodo y se enlaza los brazos
            corre->sig->ant = corre->ant;
            
            band = 1; // regresamos el valor de info
            free(corre); // se libera la memoria del nodo donde esta x
        }
    }
    
    return band; // regresamos info
}

//pilas y colas hacer las funciones.