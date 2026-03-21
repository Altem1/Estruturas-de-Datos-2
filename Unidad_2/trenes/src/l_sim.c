#include "../include/l_sim.h"

TNodoS *crea_nodoL(char direccion, int pasos){
	TNodoS *aux;
	aux = (TNodoS *) malloc (sizeof(TNodoS));
	if(aux != NULL){
		aux -> direccion = direccion;
        aux -> pasos = pasos;
		aux -> siguiente = NULL;
	}
	return aux;
}

void imprime_lista(TNodoS *cab){
	//Se puede usar una variable aux =  cab
	printf("Cab ->");
	while(cab != NULL){
		printf("| %c - %d | -> ", cab -> direccion, cab -> pasos);
		cab = cab -> siguiente;
	}
	printf("NULL");
}

void inserta_finalL(TNodoS **c, char direccion, int pasos){
    
    TNodoS *corre;
    
    if(*c == NULL){
        *c = crea_nodoL(direccion, pasos);
    }else{
        
        corre = *c;

        while( corre -> siguiente != NULL ){
            corre = corre -> siguiente;
        }
        corre -> siguiente = crea_nodoL(direccion, pasos);
    }
}

void elimina_inicio(TNodoS **c){
 
    TNodoS *aux;

    if(*c){
        aux = *c;
        *c  = (*c) -> siguiente;
        free(aux);
    }
}