#include "../include/grafo.h"

//se debe leer un archivo 

void crea_grafo(TGrafoMR *g, char *nom_arch){
    char *letras;
    //Analizamos el numero de vertices
    g -> nv = calcular_n_vertices(nom_arch);
    //Creamos la matriz 2D
    crea_arreglo2D(&g -> mR, g -> nv, g -> nv);
    //Necesitamos uno 1D para los nombres de cada linea
    //Solo sirve para 26 letras
    letras = crea_arreglo1D(g -> nv);
    //Rellenamos el Arreglo 2D con los datos del Archivo.
}

void ingresar_d(char *nom_arch, TGrafoMR **g){

    FILE *f;

    f = fopen(nom_arch, "r");
    if(!f){
        printf("Error no se pudo abrir tu archivo");
        return -1;
    }



}

void *crea_arreglo2D(int ***ptr2D, int nr, int c){

    *ptr2D= (int **)malloc(sizeof(int *)*nr);//Arreglo de punteros
    if(!ptr2D){
        printf("Error");
    }
    
    for(int i=0; i<nr; i++){
    
        *(*ptr2D+i) = (int *) malloc(sizeof(int)*c);
        if(!*(*ptr2D+i)){

            printf("Error no se pudo asignar el espacio de memoria");

            while(i>=0){

                i--;
                free(*(*ptr2D+i));
            
            }

            free(*ptr2D);
            *ptr2D=NULL;
            break;
        }
    }
}

char *crea_arreglo1D(int n){

    char *ptra;
    ptra = (char*)malloc(sizeof(char)*n);
    if(!ptra){
        printf("No se puede crear el arreglo\n");
        return NULL;
    }

    for(int i = 0; i < n; i++){
        *(ptra + i) = 'A' + i ;
    }

    return ptra;

}

int calcular_n_vertices(char *nom_arch){
    
    FILE *f;
    int numero, cont=0;

    f = fopen(nom_arch, "r");

    if(!f){
        printf("Error al abrir tu archivo");
        return -1;
    }

    char linea[1024];
    fgets(linea, 1024, f);

    while (fscanf(f, "%d", &numero) == 1) {
        printf("%d\n", numero);
        cont++;
    }

    fclose(f);
    return cont;
}   