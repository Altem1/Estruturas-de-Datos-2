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
void liberar_estructura(TVocal **vocal, int nr);
void libera_arreglo1D(char **ar1d);
void liberar_arreglo2D(char ***ar2d, int nr);

int main(){

    char **arreglo2D;
    TVocal *estruc;

    int nr;
    printf("Ingresa el numero de renglones: ");
    scanf("%d", &nr);

    crea_arreglo1D(&estruc, nr);
    crea_arreglo2D(&arreglo2D, nr, 10);
    capturar_arreglo(arreglo2D, nr, 10);
    imprime_arreglo(arreglo2D, nr, 10);
    vocal(arreglo2D, nr, estruc);
    imprime_estructura(estruc, nr);
    liberar_estructura(&estruc, nr);
    liberar_arreglo2D(&arreglo2D, nr);

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
            char *a;

            if( le == 'a' || le == 'e' || le == 'i' || le == 'o' || le == 'u' ||
                le == 'A' || le == 'E' || le == 'I' || le == 'O' || le == 'U' ){

                   (estruc+r) -> vocales = ( char *) realloc ((estruc+r) -> vocales, ((( estruc + r ) -> n_col ) + 1) * sizeof(char));
                    *(((estruc+r) -> vocales)+((estruc+r)->n_col)) = le;
                    ((estruc+r)->n_col)++;
                    
           
                  }
        }
    }
}
void imprime_estructura(TVocal *a, int nr){

    for(int i=0; i<nr; i++){

        printf("\nVocales del renglon [%d]", i+1);

        for(int j=0; j<((a+i)->n_col); j++){

            printf("%c", *((a+i)->vocales+j));

        }

        *(a+i);
        printf("\n");

        //basta ya no aguanto
    }

}
void liberar_estructura(TVocal **vocal, int nr){

    for(int i = 0; i < nr ; i++){

        free((*vocal+i)->vocales);
        ((*vocal+i)->vocales)=NULL;
    }

    free(*vocal);
}
void libera_arreglo1D(char **ar1d){
    free(*ar1d);
    *ar1d=NULL;
}
void liberar_arreglo2D(char ***ar2d, int nr){
    
    for(int i=0; i<nr; i++){
        
        libera_arreglo1D(( *ar2d + i ));
    }
    
    free(*ar2d);
    *ar2d=NULL;
    
}
