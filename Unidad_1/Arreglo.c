#include <stdio.h>
#include <stdlib.h>

void capturarArreglo(int *arr, int n);
float calcularPromedio(int *arr, int n);
void mostrarDatos(int *arr, int n, float promedio);

int main() {
    int n;
    int *ptrArreglo;
    float promedio;

    printf("---Iniciando---\n");
    printf("Cuantos numeros vamos a capturar?: ");
    scanf("%d", &n);

    ptrArreglo = (int*) malloc(n * sizeof(int));

    if (ptrArreglo == NULL) {
        printf("Error: No se pudo asignar memoria.\n");
        return 1;
    }

    capturarArreglo(ptrArreglo, n);
    promedio = calcularPromedio(ptrArreglo, n);
    mostrarDatos(ptrArreglo, n, promedio);

    return 0;
}

void capturarArreglo(int *arr, int n) {
    printf("\n--- Capturando datos ---\n");
    for (int i = 0; i < n; i++) {
        printf("Dame el valor %d: ", i + 1);
        scanf("%d", (arr + i));
    }
}

float calcularPromedio(int *arr, int n) {
    int suma = 0;
    for (int i = 0; i < n; i++) {
        suma += *(arr + i);
    }
    return (float)suma / n;
}

void mostrarDatos(int *arr, int n, float promedio) {
    printf("\n--- Resultados ---\n");
    printf("El arreglo contiene: ");
    for (int i = 0; i < n; i++) {
        printf("[ %d ]", *(arr + i));
    }
    printf("\nEl promedio calculado es: %.2f\n", promedio);
}
    
/*
int *crea_arreglo(int n);
voif captura(int *a, int n);
float promedio(int *a, int n);
void imprime(int *a, int n, float prom);

int main(){

    int *arreglo, n;
    printf("Tam del arreglo: ");
    scanf("%d", &n);
    arreglo=crea_arreglo(n);
    pro=promedio(arreglo, n);
    imprime(arreglo, n , pro);

}

int *crea_arreglo(int n){

    int *ptra;
    ptra = (int*)malloc(sizeof(int)*n);
    if(!ptra){
        printf("No se puede crear el arreglo\n");
    }
    return ptra;

}

voif captura(int *a, int n){

    printf("Elemento %d:", i);
    scamf("%d", a+1);

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
    
        printf("Elemento %d: %d\n", i++, *p);
        p++;

    }

    printf("Promedio: %f", prom);
}

------------------------------------------------------------------------------------------------------------------
int ** crea_arreglo2D(int nr, int c);


int main(){
}


int ** crea_arreglo2D(int nr, int c){

    int **ptr2D;
    ptr2D= (int **)malloc(sizeof(int *)*nr);//Arreglo de punteros
    if(!ptr2D){
        printf("Error");
    }
    
    for(int i=0; i<nr; i++){
    
        *(ptr2D+r) = (int *) malloc(sizeof(int)*c);
        if(!*(ptr2D+i)){

            printf("Error no se pudo asignar el espacio de memoria");

            while(i>=0){

                i--;
                free(*(ptr2D+r));
            
            }

            free(ptr2D);
            ptr2D=NULL;
            break;
        
        }
    
    }

}

*/
