#include <stdio.h>
#include <stdlib.h>
#include "algoritmos.h"



int main(){

    TNodo *cab = NULL;
    int op;
    int d;

    do{
        
        op = menu();

        switch (op){
            case 1:
                printf("Ingresa el valor de 'd': ");
                scanf("%d", &d);
                cab=crea_nodo(d);
                break;
            case 2: 
                imprime_lista(cab);
                break;
        
            default:
                break;
        }

    }while (op < 8 && op > 0);
    

}
