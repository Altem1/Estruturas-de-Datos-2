#include "listas_simples.h"

tipo evaluar_polinomio(TNodo *cab, tipo x);
void derivada_polinomio(TNodo *cab, TNodo **derivada);
int menu();

int main(){

    int opcion;
    tipo coef, expo, x, resultado;
    TNodo *cab = NULL, *derivada = NULL;

    do{
        opcion = menu();

        switch (opcion){
            case 1: //Capturar polinomio

                printf("Coeficiente: ");
                scanf("%d", &coef);
                printf("Exponente: ");
                scanf("%d", &expo);
                if(coef != 0 ){
                    inserta_ordenadoR(&cab, coef, expo);
                }
                printf("\033[H\033[J");

                break;
            
            case 2: //Imprimir
                printf("\033[H\033[J");
                printf("Imprimiendo ecuacion: ");
                imprime_lista(cab);
                break;

            case 3: //Evaluar polinomio
                printf("\033[H\033[J");
                printf("Ingresa el valor de X: ");
                scanf("%d", &x);
                imprime_lista(cab);
                resultado = evaluar_polinomio(cab, x);
                printf("\nResultado = %d \n", resultado);
                break;

            case 4: //derivada
                printf("\033[H\033[J");
                while(derivada != NULL){
                    elimina_inicio(&derivada);
                }
                printf("La derivada dx/dy\n");
                derivada_polinomio(cab, &derivada);
                imprime_lista(cab);
                printf("\n");
                imprime_lista(derivada);
                break;

            default:

                printf("Saliendo del programa: ");
                break;
        }

    } while (opcion > 0 && opcion < 5);
    
}

void derivada_polinomio(TNodo *cab, TNodo **derivada){
    
    tipo coefi, expo;

    if(cab){

        while(cab){

            coefi = cab -> coef * cab -> exp;
            expo = cab -> exp - 1;
            if(coefi != 0 ){
                inserta_ordenadoR(derivada, coefi, expo);
            }
            cab = cab -> sig;
        }
    }
}

tipo evaluar_polinomio(TNodo *cab, tipo x){

    tipo resultado = -99999999;

    if(cab){
        resultado = 0;

        while ( cab ){
            resultado += cab -> coef * pow(x, cab -> exp);
            cab = cab -> sig;
        }
    }
    return resultado;
}

int menu(){

    int opcion;
    printf("\nSelecciona: \n");
    printf("\t1.- Capturar polinomio\n");
    printf("\t2.- Imprimir polinomio\n");
    printf("\t3.- Evaluar el polinomio para un valor de X\n");
    printf("\t4.- Calcular la derivada del polinomio\n");
    printf("\t5.- Salir\n");
    printf("\tEleccion: ");
    scanf("%d", &opcion);

    return opcion;

}
