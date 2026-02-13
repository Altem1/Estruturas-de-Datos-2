#include <stdio.h>
#include <stdlib.h>

//Estructura
typedef struct{
    int n_col;
    char *vocales;
}TVocal;

void crea_arreglo2D(char ***ptr2D, int nr, int c);
void crea_arreglo1D(TVocal **arr, int nr);
void capturar_arreglo(char **a, int nr, int nc);
void imprime_arreglo(char **a, int nr, int nc);
void vocal(char **a, int nr, TVocal *estruc);
void imprime_estructura(TVocal *a, int nr);

int main(){

    char **arreglo2D;
    TVocal *estruc;
    crea_arreglo1D(&estruc, 2);
    crea_arreglo2D(&arreglo2D, 2, 10);
    capturar_arreglo(arreglo2D, 2, 10);
    imprime_arreglo(arreglo2D, 2, 10);
    vocal(arreglo2D, 2, estruc);
    imprime_estructura(estruc, 2);

    return 0;

}


void crea_arreglo2D(char ***ptr2D, int nr, int c){

    
    *ptr2D= (char **)malloc(sizeof(char *)*nr);//Arreglo de punteros
    if(!ptr2D){
        printf("Error");
    }
    
    for(int i=0; i<nr; i++){
    
        *(*ptr2D+i) = (char *) malloc(sizeof(char)*c);
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

void crea_arreglo1D(TVocal **arr, int nr){

    *arr = (TVocal*)malloc(sizeof(TVocal)*nr);
    for(int i=0; i<nr; i++){

        (*arr+i)->n_col = 0;
        (*arr+i)->vocales = NULL;

    }
    if(*arr==NULL){
        printf("No se puede crear el arreglo\n");
    }

}

void capturar_arreglo(char **a, int nr, int nc){

    for (int r = 0; r < nr; r++){
        
            printf("Elemento[%d]: ", r);
            scanf("%s", *(a+r));
    }
}

void imprime_arreglo(char **a, int nr, int nc){

    for (int r = 0; r < nr ; r++){
        
        printf("Elemento guardado[%d]: %s\n",r+1, *(a+r));

    }
}

void vocal(char **a, int nr, TVocal *estruc){

    int cont=0;

    for (int r = 0; r < nr ; r++){

        for(int c=0; *(*(a+r)+c) != '\0' ; c++){

            char le=*(*(a+r)+c);

            if( le == 'a' || le == 'e' || le == 'i' || le == 'o' || le == 'u' ||
                le == 'A' || le == 'E' || le == 'I' || le == 'O' || le == 'U' ){

                    (estruc+r)->vocales=(char*)realloc((estruc+r)->vocales, (((estruc+r)->n_col)+1)*sizeof(char));
                    *(((estruc+r)->vocales)+((estruc+r)->n_col)) = le;
                    ((estruc+r)->n_col)++;
                    
            }
        }
    }
}

void imprime_estructura(TVocal *a, int nr){

    for(int i=0; i<nr; i++){

        printf("\nVocales del renglon [%d]", i+1);

        for(int j=0; j<(a->n_col); j++){

            printf("%c", *(a->vocales+j+i));

        }

        *(a+i);
        printf("\n");

        //basta ya no aguanto
    }

}