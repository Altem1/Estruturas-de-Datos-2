#include "listas_simples.h"

//Listas Simples

TNodo *crea_nodo(tipo coefi, tipo expo){
	TNodo *aux;
	aux = (TNodo *) malloc (sizeof(TNodo));
	if(aux != NULL){
        aux -> coef = coefi;
		aux-> exp = expo;
		aux->sig = NULL;
	}
	return aux;
}

void imprime_lista(TNodo *cab){
	//Se puede usar una variable aux =  cab
	printf("Cab ->");
	while(cab != NULL){
		printf(" %dx^%d + ", cab -> coef, cab -> exp);
        if (cab -> exp == 0){
            printf("\b\b");
        }
        
		cab=cab->sig;
	}
	printf("NULL");
}

void inserta_inicio(TNodo **c, tipo coefi, tipo expo){
    
    TNodo *aux;
    aux = crea_nodo(coefi, expo);

    if(aux){
        
        aux->sig = *c;
        *c = aux;

    }
    
}

void inserta_final(TNodo **c, tipo coefi, tipo expo){
    
    TNodo *corre;
    
    if(*c == NULL){
        *c = crea_nodo(coefi, expo);
    }else{
        
        corre = *c;

        while( corre -> sig != NULL ){
            corre = corre -> sig;
        }
        corre -> sig = crea_nodo(coefi, expo);
    }
}

void inserta_finalR(TNodo **c, tipo coefi, tipo expo){
    
    if ( *c == NULL ){
        *c = crea_nodo(coefi, expo);
    }else{
        inserta_finalR(&((*c)->sig), coefi, expo);
    }

}

void inserta_ordenado(TNodo **c, tipo coefi, tipo expo){

    TNodo *corre;
    TNodo *anterior;

    if(*c==NULL || expo < (*c) -> exp) {
        inserta_inicio(c, coefi, expo);
    }else{
        corre=*c;
        while(corre != NULL && expo > corre -> exp ){
            anterior = corre;
            corre = corre -> sig;
        }
        anterior -> sig = crea_nodo(coefi, expo);
        anterior -> sig -> sig = corre;
    }

}

void inserta_ordenadoR(TNodo **c, tipo coefi, tipo expo){
    if( *c == NULL || expo > (*c) -> exp) {
        inserta_inicio(c, coefi, expo);
    }else if(expo == (*c) -> exp){
        (*c) -> coef += coefi;
    }else{
        inserta_ordenadoR(&((*c)->sig), coefi, expo);
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
    tipo aux=-1;

    if( *c ){
        corre = *c;
        while( corre -> sig != NULL){
            anterior = corre;
            corre = corre -> sig;
        }
        anterior -> sig = NULL;
    }

    free(corre);

}

void elimina_finalR(TNodo **c){

    tipo aux=-1;

    if( (*c) -> sig == NULL ){
        *c = NULL;
    }else{
        elimina_finalR(&(( *c ) -> sig));
    }
}

int elimina_x(TNodo **cab, tipo coefi, tipo expo){

    TNodo *corre, *anterior;
    int band = 0;

    if( *cab ){

        if( (*cab) -> coef == coefi && (*cab) -> exp == expo ){
            corre = *cab;
            *cab = corre -> sig;
            free(corre);
            band = 1;
        } else {

            corre = *cab;
            while ( corre != NULL && corre -> coef != coefi && corre -> exp != expo){
                
                anterior = corre;
                corre = corre ->sig;
            }

            if( corre ){

                anterior -> sig = corre -> sig;
                free(corre);

            }
        }
    }
    return band;
}

int elimina_xR(TNodo **cab, tipo coefi, tipo expo){

    TNodo *corre, *anterior;
    int band = 0;

    if( *cab ){

        if( (*cab) -> coef == coefi && (*cab) -> exp == expo ){
            corre = *cab;
            *cab = corre -> sig;
            free(corre);
            band = 1;
        } else{
            band = elimina_xR(&(*cab)->sig, coefi, expo);
        }
    }

    return band;
}