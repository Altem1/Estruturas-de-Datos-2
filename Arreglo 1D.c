#include <stdlib.h>
#include <stdio.h>

int *crea_arreglo(int n);
void captura(int *a, int n);
float promedio(int *a, int n);
void imprime(int *a, int n, float prom);

int main(){

    int *arreglo, n;
    float prom=0.0;
    printf("Tam del arreglo: ");
    scanf("%d", &n);
    arreglo=crea_arreglo(n);
    captura(arreglo, n);
    prom=promedio(arreglo, n);
    imprime(arreglo, n , prom);
    libera_arreglo1D(&arreglo);
}

int *crea_arreglo(int n){

    int *ptra;
    ptra = (int*)malloc(sizeof(int)*n);
    if(!ptra){
        printf("No se puede crear el arreglo\n");
    }
    return ptra;

}

void captura(int *a, int n){

    for (int i = 0; i < n; i++){
        printf("Elemento [%d]: ", i+1);
        scanf("%d", (a+i));
    }
}

float promedio(int *a, int n){

    float prom=0.0;

    for(int i=0; i<n; i++){
    
        prom+= *(a+i);
    
    }

    return(prom/n);

}

void imprime(int *a, int n, float prom){

    int *p=a;
    int i=0;

    while(p<a+n){
    
        printf("Elemento [%d]: %d\n", i++, *p);
        p++;

    }

    printf("Promedio: %f", prom);
}

void libera_arreglo1D(int **ar1d){
    free(*ar1d);
    *ar1d=NULL;
}
