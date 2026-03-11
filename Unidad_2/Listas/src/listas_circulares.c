#include "../include/listas_circulares.h"
#include "../include/listas_simples.h"

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

void elimina_inicio_final_cir(TNodo **cab, int band){

    TNodo *aux, *corre, *anterior;

    if(!*cab){
        aux = *cab;

        if ( aux -> sig == *cab ) {
            *cab = NULL;
            free(aux);
        }else{
            
            corre = *cab;
            while (corre -> sig != cab) {
                anterior = corre;
                corre = corre -> sig;
            }

            if(band = 0){ //con 1 indicamos que eliminara al inicio
                *cab = (*cab) -> sig;
                corre -> sig = *cab;
                anterior = NULL;
                free(anterior);
            }else{ //cualquier otro numero eliminamos al final
                anterior -> sig = *cab;
                corre = NULL;
                free(corre);
            }
        }
    }
}

void elimina_x_cir(TNodo, tipo d){

    

}