#include <stdlib.h>

void crea_arreglo2D(int ***ptr2D, int nr, int c);
void capturar_arreglo(int **a, int nr, int nc);
void imprime_arreglo(int **a, int nr, int nc);

int main(){


    
}


void crea_arreglo2D(int ***ptr2D, int nr, int c){

    int **ptr2D;
    ptr2D= (int **)malloc(sizeof(int *)*nr);//Arreglo de punteros
    if(!ptr2D){
        printf("Error");
    }
    
    for(int i=0; i<nr; i++){
    
        *(*ptr2D+i) = (int *) malloc(sizeof(int)*c);
        if(!*(*ptr2D+i)){

            printf("Error no se pudo asignar el espacio de memoria");

            while(i>=0){

                i--;
                free(*(*ptr2D+i));
            
            }

            free(*ptr2D);
            *ptr2D=NULL;
            break;
        
        }
    
    }

}

void capturar_arreglo(int **a, int nr, int nc){

    for (int r = 0; r < nr; r++){
        
        for (int c = 0; c < nc; c++){
            
            printf("Elemento[%d][%d]: ", r, c);
            scanf("%d", *(a+r)+c);

        }
    }
}

void imprime_arreglo(int **a, int nr, int nc){

    for (int r = 0; r < nr; r++){
        
        for (int c = 0; c < nc; c++){
            
            printf("Elemento[%d][%d] %d\n: ", r, c, *(*(a+r)+c));

        }
    }
}