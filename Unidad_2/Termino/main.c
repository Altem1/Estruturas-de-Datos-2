#include "algoritmos.h"

//terminar tarea.

int main(){



}

float evalua_polinomio(TNodo *p, int x){

    float suma;
    TNodo *corre;

    for( corre = p ; corre != NULL; corre = corre->sig ){

        suma += pow(x, corre->info.exp)*corre->info.coef;

    }

}

void derivada(TNodo *p, TNodo **pp){

    TNodo *corre;
    TNodo *aux;

    TTermino d;

    for( corre = p ; corre != NULL; corre = corre->sig ){

        if(corre -> info.exp > 0){
            d.coef = corre -> info.coef * corre -> info.exp;
            d.exp = corre -> info.exp-1;
            inserta_final(pp, d);
        }

    }

}
