#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    
    int clave;
    char *nombre;
    char *carrera;
    int generacion;

}TAlumno;

void crea_arregloAlumnos1D(TAlumno **ptrA, int na){

    *ptrA=(TAlumno*) malloc (sizeof(TAlumno)*na);
    if (*ptrA==NULL){
        printf("No");
    }

}

void captura_alumnoS(TAlumno *ptrA, int na){

    char cadena[100];

    for (int i = 0; i < na; i++){
        printf("Clave: ");
        scanf("%d", &(ptrA+i)->clave);

        printf("Nombre: ");
        scanf("%[^\n], cadena");
        (ptrA+i)->nombre=(char*)malloc(sizeof(char)*(strlen(cadena)+1));
        strcmp((ptrA+i)->nombre, cadena);

        printf("Carrera: ");
        scanf("%[^\n], cadena");
        (ptrA+i)->carrera=(char*)malloc(sizeof(char)*strlen(cadena+1));
        strcmp((ptrA+i)->carrera, cadena);

        printf("Generacion: ");
        scanf("%d", &(ptrA+i)->generacion);
    }

}

void imprime(TAlumno *ptrA, int na){
	//Aqui va la impresion de los datos
}
