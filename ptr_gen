#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int clave;
    char *nombre;
    float precio;
}STRC;

void *crea_dato_generico(int tipo);
void captura_dato(int tipo, void *pdato);
void imprime_dato(int tipo, void *pdato);
int menu();

int main(){

    int tipo;
    void *pd;

    do{
        tipo=menu();
        pd=crea_dato_generico(tipo);
        captura_dato(tipo, pd);
        imprime_dato(tipo, pd);
        free(pd);
    }while(tipo<6);

}

void *crea_dato_generico(int tipo){

    void *ptr;

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
            pd=malloc(sizeof(int));
            break;

        case STRUCT:
            pd=malloc(sizeof(STRC));

        default:
            break;
        }

    return pd;
}
void captura_dato(int tipo, void *pdato){}
void imprime_dato(int tipo, void *pdato){}
int menu(){}