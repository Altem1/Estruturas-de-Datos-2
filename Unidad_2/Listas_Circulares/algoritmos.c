#include "./algoritmos.h"

TNodo *crea_nodo(tipo d){
	TNodo *aux;
	aux = (TNodo *) malloc (sizeof(TNodo));
	if(aux != NULL){
		aux->info = d;
		aux->sig = NULL;
	}
	return aux;
}

void imprime_lista_cir(TNodo *cab){

    TNodo *corre;
    corre = cab;

    do{
        printf("%d -> ", corre -> info);
        corre = corre -> sig;
    }while(corre != cab);

}

void inserta_inicio_cir_ini_fin(TNodo **cab, tipo d, int band){

    TNodo *aux, *corre;
    aux = crea_nodo(d);

    if(!*cab){
        aux -> sig = *cab;
    }

    for(corre = *cab; corre -> sig != *cab; corre = corre -> sig );
    
    corre -> sig = aux;
    aux -> sig = *cab;

    if(band == 0)
        *cab = aux;

}

void inserta_ord_cir(TNodo **cab, tipo d){

    TNodo *aux, *corre, *ant;

    if(!*cab || d <=  (*cab)-> info ){

        inserta_inicio_cir_ini_fin(cab, d, 0);

    }else{

        while (corre -> sig != cab && corre -> info < d){
            
            ant = corre;
            corre = corre -> sig;

        }

        aux = crea_nodo(d);

        if( corre->info > d){
            ant -> sig = aux;
            aux -> sig = corre;
        }else{
            aux -> sig = corre ->sig;
            corre -> sig = aux;
        }
    }

}