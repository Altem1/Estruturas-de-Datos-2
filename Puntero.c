#include<stdio.h>
#define TAM 10

void captura(int *pa, int x);
void suma(int *pa1, int *pa2, int *pa3, int x);
void imprimir(int *pa,int x);

int main(){

    int a1[TAM], a2[TAM], a3[TAM];
    int tam;
    int t;

    printf("Cuantos numeros ingresaras: ");
    scanf("%d", &tam);
    if(tam>TAM){
        printf("El nunero ingresado supera el limite, se definira con el limite %d", TAM);
        t=TAM;
    }else{
        t=tam;
    }
    printf("\nCaptura arreglo 1: \n");
    captura(a1, t);
    printf("\nCaptura arreglo 1: \n");
    captura(a2, t);
    suma(a1, a2, a3, t);

    printf("\nArreglo 1: \n");
    imprimir(a1, t);
    printf("\nArreglo 2: \n");
    imprimir(a2, t);
    printf("\nArreglo 3: \n");
    imprimir(a3, t);
}

void captura(int *pa, int x){

    for(int i=0; i<x; i++){
        printf("Ingresa el %d elemento del arreglo: ", i+1);
        scanf("%d", (pa+i));
    }

}

void suma(int *pa1, int *pa2, int *pa3, int x){

    int i=0;
    int xt=x;
    while(i<x){

        *(pa3+i) = *(pa1+i) + *(pa2+(xt-1-i));
        i++;
        xt=x;

    }

}

void imprimir(int *pa,int x){

    for(int i=0; i < x; i++){

        printf("[ %d ]", *(pa+i));

    }

}
