#include "./algoritmos.h"

TNodo *crea_nodo(int matricular){
	TNodo *aux;
	aux = (TNodo *) malloc (sizeof(TNodo));
	if(aux != NULL){
		aux->matricula = matricular;
		aux->sig = NULL;
	}
	return aux;
}

void imprime_conjunto(TNodo *cab, char conj){
	//Se puede usar una variable aux =  cab
	printf("Conjunto %c ( ", conj);
	while(cab != NULL){
		printf("%d , ", cab -> matricula);
		cab = cab -> sig;
	}
	printf("NULL )");
}

void inserta_conjunto(TNodo **c, int matricular ){
    
    TNodo *aux;
    TNodo *buscar = busqueda(*c, matricular);

    if( buscar == NULL ){
        aux = crea_nodo(matricular);
        aux -> sig = *c;
        *c = aux;
    }
}

int elimina(TNodo **cab, int matricular){

    TNodo *corre, *anterior;
    int band = 0;

    if( *cab ){

        if( (*cab) -> matricula == matricular ){
            corre = *cab;
            *cab = corre -> sig;
            free(corre);
            band = 1;
        } else {

            corre = *cab;
            while ( corre != NULL && corre -> matricula != matricular){
                
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

TNodo *busqueda(TNodo *cab, int matricula){

    TNodo *aux = NULL;
    TNodo *corre = cab;

    while(corre != NULL){
        if(corre -> matricula == matricula){
            aux = corre;
            break;
        }
        corre = corre -> sig;
    }
    
    return aux;
}