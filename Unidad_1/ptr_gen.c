#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define INT 1
#define FLOAT 2
#define CHAR 3
#define STRING 4
#define STRUCT 5

typedef struct{
    int clave;
    char *nombre;
    float precio;
}TProducto;

void *crea_dato_generico(int tipo);
void captura_dato(int tipo, void *pdato);
void imprime_dato(int tipo, void *pdato);
int menu();

int main(){

    int tipo;
    void *pd;

    do{
        tipo=menu();
        if(tipo<6){
            pd=crea_dato_generico(tipo);
            captura_dato(tipo, pd);
            imprime_dato(tipo, pd);
            free(pd);
        }
    }while(tipo<6);

    return 0;

}

void *crea_dato_generico(int tipo){

    void *ptr;
    int tam;

    switch (tipo){
        case INT:
            ptr=malloc(sizeof(int));
            break;
        
        case FLOAT:
            ptr=malloc(sizeof(float));
            break;

        case CHAR:
            ptr=malloc(sizeof(int));
            break;
        
        case STRING:
            printf("Ingresa el tamaño de la cadena: ");
            scanf("%d", &tam);
            ptr=malloc(sizeof(int));
            break;

        case STRUCT:
            ptr=malloc(sizeof(TProducto));

        default:
            break;
        }

    return ptr;
}

void captura_dato(int tipo, void *pdato){
    char nom[100];
    switch (tipo)
    {
    case INT:
        printf("Dame el int: ");
        scanf("%d", (int*)pdato);
        break;

    case FLOAT:
        printf("Dame el float: ");
        scanf("%f", (int*)pdato);
        break;

    case CHAR:
        printf("Dame el char: ");
        scanf("%c", (int*)pdato);
        break;

    case STRING:
        printf("Dame el string: ");
        scanf("%s", (int*)pdato);
        break;

    case STRUCT:
        printf("Dame la clave: ");
        scanf("%d",&((((TProducto*)pdato)->clave)));
        printf("Dame el nombre: ");
        scanf("%s", nom);
        ((TProducto*)pdato)->nombre=(char*)malloc(strlen(nom)*sizeof(char));
        strcpy(((TProducto*)pdato)->nombre, nom);
        printf("Dame el precio");
        scanf("%f", ((TProducto*)pdato)->precio);
        break;

    default:
        break;
    }

}
void imprime_dato(int tipo, void *pdato){

    char nom[100];
    switch (tipo)
    {
    case INT:
        printf("El entero es: %d", *((int*)pdato));
        break;

    case FLOAT:
        printf("El flotante es: %f", *((int*)pdato));
        break;

    case CHAR:
        printf("El char es: %c", *((int*)pdato));
        break;

    case STRING:
        printf("La cadena es: %s", (int*)pdato);
        break;

    case STRUCT:
        printf("Clave: %d\n",(((TProducto*)pdato)->clave));
        printf("Nombre %s\n", ((TProducto*)pdato)->nombre);
        printf("Precio: %f", ((TProducto*)pdato)->precio);
        break;

    default:
        break;
    }

}

int menu(){
    int op;
    printf("Elige una opción: \n");
    printf("Opcion 1: int \n");
    printf("Opcion 2: float \n");
    printf("Opcion 3: char \n");
    printf("Opcion 4: string \n");
    printf("Opcion 5: struct \n");
    printf("Opcion 6: Salir \n");
    printf("Elige: ");
    scanf("%d", &op);

    return op;
}

//Crear un arreglo de n elementos para cada tipo de datos

void *crea_datos_genericos(int tipo, int n){

    void *ptr;
    int tam;

    switch (tipo){
        case INT:
            ptr=malloc(sizeof(int)*n);
            break;
        
        case FLOAT:
            ptr=malloc(sizeof(float)*n);
            break;

        case CHAR:
            ptr=malloc(sizeof(int)*n);
            break;
        
        case STRING:
            printf("Ingresa el tamaño de la cadena: ");
            scanf("%d", &tam);
            ptr=malloc(sizeof(int)*n);
            break;

        case STRUCT:
            ptr=malloc(sizeof(TProducto)*n);

        default:
            break;
        }

    return ptr;
}

void captura_datos_genericos(void *pds, int tipo, int n){

    int desp;

    switch (tipo){
        case INT:
            desp=sizeof(int);
            break;
        case FLOAT:
            desp=sizeof(float);
            break;
        case CHAR:
            desp=sizeof(char);
            break;
        case STRING:
            desp=sizeof(char)*n;
            break;
    
    default:
        break;
    }

    for (int i = 0; i < n; i++){
        
        captura_dato(tipo, pds+(i*desp));

    }
    

}