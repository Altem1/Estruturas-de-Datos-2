#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void altas(TAlumno *arr, int na);
void bajas(TAlumno *arr, int *na, int clave1);

typedef struct{
    
    int clave;
    char *nombre;
    char *carrera;
    int generacion;

}TAlumno;

int menu(){

    int opcion;
    printf("1. Altas de alumnos\n");
    printf("2. Bajas de alumnos\n");
    printf("3. Modificaciones de alumnos\n");
    printf("4. Consulta de alumnos\n");
    printf("5. Impresion de alumnos\n");
    printf("6. Salir\n");
    printf("Selecciona una opcion: ");
    scanf("%d", &opcion);
    return opcion;

}

void altas(TAlumno *arr, int na){

    *arr=(TAlumno*)realloc(TAlumno*)*arr,sizeof(TAlumno)*na);
    if(*arr==NULL){
        printf("Error al asignar memoria");
        return;
    }
    captura_alumno(arr);

}

void consulta(){


}

//necesito buscar al alumno
TAlumno *busqueda(TAlumno *arr, int clave, int na){

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
    buscar=busqueda(arr, clave1, *na);
    if(buscar){
        //Se encontro el alumno
        *buscar = *(arr + (*na - 1));
        (*na)--1;
    }

}

void captura_alumnoS(TAlumno *ptrA){

    char cadena[100];

        printf("Clave: ");
        scanf("%d", &(ptrA)->clave);

        printf("Nombre: ");
        scanf("%[^\n], cadena");
        (ptrA+i)->nombre=(char*)malloc(sizeof(char)*(strlen(cadena)+1));
        strcp((ptrA+i)->nombre, cadena);

        printf("Carrera: ");
        scanf("%[^\n], cadena");
        (ptrA+i)->carrera=(char*)malloc(sizeof(char)*strlen(cadena+1));
        strcp((ptrA+i)->carrera, cadena);

        printf("Generacion: ");
        scanf("%d", &(ptrA+i)->generacion);

}

void imprimir(TAlumnos *arr, int *na){

}