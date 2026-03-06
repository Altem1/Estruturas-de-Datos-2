#include <stdio.h>
#include <stdlib.h>
#include "algoritmos.h"



int main(){

    TNodo *cab = NULL;
    int op;
    tipo d;

    do{
        
        op = menu();

        switch (op){
            case 1:
                printf("Ingresa el valor de 'd': ");
                scanf("%d", &d);
                cab=crea_nodo(d);
                break;
            case 2: 
                printf("Impresion de la lista");
                imprime_lista(cab);
                break;
            
            case 3:
                printf("Ingresa el contenido a ingresar: ");
                scanf("%d", &d);
                inserta_inicio(&cab, d);
                break;
            
            case 4: 
                printf("Ingresa el contenido a ingresar: ");
                scanf("%d", &d);
                inserta_final(&cab, d);
                break;

            case 5: 
                printf("Ingresa el contenido a ingresar: ");
                scanf("%d", &d);
                inserta_ordenado(&cab, d);
                break;

            case 6:
                printf("Eliminando del inicio...");
                elimina_inicio(&cab);
                break;

            case 7:
                printf("Eliminando del final...");
                elimina_final(&cab);
                break; 
                
            default:
                printf("Saliendo el programa...\n");
                break;
        }

    }while (op < 8 && op > 0);
    

}
