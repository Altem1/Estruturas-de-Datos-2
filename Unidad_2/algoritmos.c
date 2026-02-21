#include <stdio.h>
#include <stdlib.h>
#include "algoritmos.h"

int menu(){
    int opcion;

    printf("Ingresa la opcion: ");
    printf("\n1.- Crear nodo \n2- Impirmir lista\n3- Inserta inicio \n4.- Inserta final \n5.- Inserta ordenado\n6.- Elimina inicio \n7.- Eliminar final \n8.- Salir ");
    printf("\n\tElige: ");
    scanf("%d", &opcion);

    return opcion;
}

TNodo *crea_nodo(tipo d){
	TNodo *aux;
	aux = (TNodo *) malloc (sizeof(TNodo));
	if(aux != NULL){
		aux->info = d;
		aux->sig = NULL;
	}
	return aux;
}

void imprime_lista(TNodo *cab){
	//Se puede usar una variable aux =  cab
	printf("Cab ->");
	while(cab != NULL){
		printf("%d -> ", cab->info);
		cab=cab->sig;
	}
	printf("NULL");
}

void inserta_inicio(TNodo **c, tipo d){
    
    TNodo *aux;
    aux = crea_nodo(d);

    if(aux){
        
        aux->sig = *c;
        *c = aux;

    }
    
}

void inserta_final(TNodo **c, tipo d){
    
    TNodo *corre;
    
    if(*c == NULL){
        *c = crea_nodo(d);
    }else{
        
        corre = *c;

        while( corre->sig != NULL ){
            corre = corre -> sig;
        }
        corre -> sig = crea_nodo(d);
    }
}

void inserta_finalR(TNodo **c, tipo d){
    
    if ( *c == NULL ){
        *c = crea_nodo(d);
    }else{
        inserta_finalR(&((*c)->sig), d);
    }

}

void inserta_ordenado(TNodo **c, tipo d){

    TNodo *corre;
    TNodo *anterior;

    if(*c==NULL || d < (*c) -> info) {
        inserta_inicio(c, d);
    }else{
        corre=*c;
        while(corre != NULL && d > corre -> info ){
            anterior = corre;
            corre = corre -> sig;
        }
        anterior -> sig = crea_nodo(d);
        anterior -> sig -> sig = corre;
    }

}

void inserta_ordenadoR(TNodo **c, tipo d){
    if( *c == NULL || d < (*c) -> info) {
        inserta_inicio(c, d);
    }else{
        inserta_ordenadoR(&((*c)->sig), d);
    }
}

void elimina_inicio(TNodo **c){
 
    TNodo *aux;

    if(*c){
        aux = *c;
        *c  = (*c)->sig;
        free(aux);
    }
}

void elimina_final(TNodo **c){

    TNodo *anterior, *corre;

    if(!*c){
        printf("Error: El nodo esta vacio");
        return;
    }else{
        corre = *c;
        while( corre -> sig != NULL){
            anterior = corre;
            corre = corre -> sig;
        }

        anterior -> sig = NULL;

    }

}

void elimina_finalR(TNodo **c){

    if( (*c) -> sig == NULL){
        *c = NULL;
    }else{
        elimina_finalR(&(( *c ) -> sig));
    }

}