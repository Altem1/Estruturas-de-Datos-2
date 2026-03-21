#include "include/d_enl.h"
#include "include/l_sim.h"

void crear_estaciones(TCabs *cab, int estaciones);
void elimina_estaciones(TCabs *cab);
void instrucciones(TNodoS **cabs);
void elimina_instrucciones(TNodoS **cabs);
void menu_instrucciones();
int menu_principal();
void moverse(TNodoS *cabs,TCabs *cab,int estacion_inicial);

int main(){

    TCabs *cab;
    TNodoS *cabS = NULL;
    inicializa(&cab);
    if (cab == NULL) {
        return 1;
    }
    crear_estaciones(cab, 8);
    
    int opcion;
    int estacion_inicial = 1;

    do{
        opcion = menu_principal();

        switch (opcion){
            case 1:

                if (cabS != NULL){
                    printf("\nError primero debes eliminar las intrucciones anteriores\n");
                }else{
                    instrucciones(&cabS);
                    printf("Las instrucciones dadas fueron: \n");
                    imprime_lista(cabS);
                }
                break;
                
            case 2:
                printf("Eliminando...\n");
                elimina_instrucciones(&cabS);
                printf("Instrucciones anteriores eliminadas\n");
                break;

            case 3:
                printf("\nReiniciando estaciones...");
                elimina_estaciones(cab);
                crear_estaciones(cab, 8);
                printf("\nRuta generada con 8 estaciones\n");
                break;

            case 4:
                printf("Ingresa desde que estacion quieres iniciar: ");
                scanf("%d", &estacion_inicial);
                break;

            case 5: //toda la logica de como se movera que miedo
                printf("\nMoviendonos...\n");
                moverse(cabS, cab, estacion_inicial);
                printf("\n");
                break;

            default:
                if (opcion != 6){
                    printf("\nOpcion invalida\n");
                }
                break;
        }


    }while (opcion != 6);
    
    elimina_instrucciones(&cabS);
    elimina_estaciones(cab);

    free(cab);

    return 0;
}

void moverse(TNodoS *cabs,TCabs *cab,int estacion_inicial){

    TCabs aux;
    int camina = 1;

    if (cab == NULL || cab -> ini == NULL || cabs == NULL) return;

    aux = *cab;

    if (estacion_inicial > 1){
        while (aux.ini != NULL && camina < estacion_inicial){
            aux.ini = aux.ini -> siguiente;
            camina++;
        }
    }

    if (aux.ini == NULL){
        aux.ini = cab -> ini;
    }

    while (cabs != NULL){
        int paso = 0;

        switch (cabs -> direccion){
            case 'D':
                while (aux.ini != NULL && aux.ini -> siguiente != NULL && paso < cabs -> pasos){
                    aux.ini = aux.ini -> siguiente;
                    paso++;
                }
                break;

            case 'I':
                while (aux.ini != NULL && aux.ini -> anterior != NULL && paso < cabs -> pasos){
                    aux.ini = aux.ini -> anterior;
                    paso++;
                }
                break;

            case 'S':
                aux.ini = cab -> ini;
                break;

            case 'F':
                aux.ini = cab -> fin;
                break;

            default:
                printf("\nEsa es una instruccion invalida no se tomara en cuenta\n");
                break;
        }

        if (aux.ini != NULL){
            printf("\nEstacion actual: %d", aux.ini -> estacion);
        }

        cabs = cabs -> siguiente;
    }
}

void crear_estaciones(TCabs *cab, int estaciones){
    int cont=1;

    while (cont-1 < estaciones){

        inserta_finalD(cab, cont);
        cont++;
    }
}

void elimina_estaciones(TCabs *cab){
    TNodoD *aux;

    if (cab == NULL) return;

    while (cab -> ini != NULL){
        aux = cab -> ini;
        cab -> ini = cab -> ini -> siguiente;
        free(aux);
    }

    cab -> fin = NULL;
}

void instrucciones(TNodoS **cabs){
    int parar=0;
    char letra;
    int numero;

    menu_instrucciones();

    while (parar == 0){
        printf("\nIngresa la letra: ");
        scanf(" %c", &letra);
        printf("Ingresa la cantidad de espacios a moverse: ");
        scanf("%d", &numero);
        inserta_finalL(cabs, letra, numero);
        printf("Ingresa 0 si quieres agregar mas instrucciones: ");
        scanf("%d", &parar);
    }

}

void menu_instrucciones(){
    printf("\nIngresa las instrucciones a continuacion");
    printf("\nD : n -> Derecha");
    printf("\nI : n -> Izquierda");
    printf("\nS : 0 -> Mover a la primera estacion");
    printf("\nF : 0 -> Mover a la ultima estacion");
}

void elimina_instrucciones(TNodoS **cabs){
    if (cabs == NULL) return;

    while (*cabs != NULL){
        elimina_inicio(cabs);
    }
}

int menu_principal(){
    int opcion;
    printf("\nBienvenido!, que deseas realizar?");
    printf("\n1.- Agregar instrucciones nuevas");
    printf("\n2.- Eliminar instrucciones");
    printf("\n3.- Generar las estaciones (8 por defecto)");
    printf("\n4.- Seleccionar la estacion principal");
    printf("\n5.- Ejecutar instrucciones en la ruta");
    printf("\n6.- Salir");
    printf("\n\tEleccion: ");
    scanf("%d", &opcion);
    return opcion;
}