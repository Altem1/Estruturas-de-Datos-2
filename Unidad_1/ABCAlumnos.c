#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    
    int clave;
    char *nombre;
    char *carrera;
    int generacion;

}TAlumno;

int menu();
void altas(TAlumno **arr, int *na);
void bajas(TAlumno *arr, int *na, int clave1);
void captura_alumno(TAlumno *ptrA);
void mostrar_alumnos(TAlumno *arr);
TAlumno *busquedas(TAlumno *arr, int clave, int na);
void liberar_todo(TAlumno *arr, int na);

int main(){

    int op, clavee;
    TAlumno *arr=NULL, *busco;
    int na=0;

    do{
        op=menu();
        switch(op){
            case 1:
                printf("\nAgrega los datos: \n");
                altas(&arr, &na);
                break;
            case 2:
                printf("\nIndica la clave del alumno: \n");
                scanf("%d", &clavee);
                bajas(arr, &na, clavee);
                break;
            case 3:
                printf("\nIndica la clave del alumno: ");
                scanf("%d", &clavee);
                busco=busquedas(arr, clavee, na);
                if(busco==NULL){
                    printf("Error NULL");
                    break;
                }
                mostrar_alumnos(busco);
                break;
            case 4:
                printf("\nLista de alumnos registrados.. \n");
                for(int i=0; i<na; i++){
                    printf("\nDatos del alumno %d: \n", i+1);
                    mostrar_alumnos(arr+i);
                }
                break;
            
            default:
                printf("\nSaliendo...\n");
                liberar_todo(arr, na);
                break;

            
        }
    }while(op<5);


}

int menu(){

    int opcion;
    printf("\n1. Altas de alumnos\n");
    printf("2. Bajas de alumnos\n");
    printf("3. Consulta de alumno\n");
    printf("4. Impresion de alumnos\n");
    printf("5. Salir\n");
    printf("Selecciona una opcion: ");
    scanf("%d", &opcion);
    return opcion;

}

void altas(TAlumno **arr, int *na){

    *arr=(TAlumno*)realloc(*arr,sizeof(TAlumno)*(*na + 1));
    if(*arr==NULL){
        printf("Error al asignar memoria");
        return;
    }
    captura_alumno(*arr + *na);
    (*na)++;
}

//necesito buscar al alumno
TAlumno *busquedas(TAlumno *arr, int clave, int na){

    TAlumno *encontrado=NULL;

    for(int i=0; i<na; i++){

        if ((*(arr+i)).clave==clave){
            encontrado=arr+i;
            break;
        }
        
    }
    return encontrado;
}

void bajas(TAlumno *arr, int *na, int clave1){

    TAlumno *buscar=NULL;
    buscar=busquedas(arr, clave1, *na);
    if(buscar){
        //Se encontro el alumno
        *buscar = *(arr + (*na - 1));
        (*na)--;
    }

}

void captura_alumno(TAlumno *ptrA){

    char cadena[100];

        printf("Clave: ");
        scanf("%d", &ptrA->clave);
        getchar();

        printf("Nombre: ");
        scanf(" %[^\n]", cadena);
        (ptrA)->nombre=(char*)malloc(sizeof(char)*(strlen(cadena)+1));
        strcpy((ptrA)->nombre, cadena);
        getchar();

        printf("Carrera: ");
        scanf(" %[^\n]", cadena);
        (ptrA)->carrera=(char*)malloc(sizeof(char)*strlen(cadena+1));
        strcpy((ptrA)->carrera, cadena);

        printf("Generacion: ");
        scanf("%d", &ptrA->generacion);

}

void mostrar_alumnos(TAlumno *arr){
    
        printf("\nClave: %d", ((arr)->clave));
        printf("\nNombre:  %s", ((arr)->nombre));
        printf("\nCarrera:  %s", ((arr)->carrera));
        printf("\nGeneracion: %d", ((arr)->generacion));
    
}

void liberar_todo(TAlumno *arr, int na){

    for(int i=0; i<na; i++){

        free((arr+i)->nombre);
        free((arr+i)->carrera);

    }

    free(arr);

}