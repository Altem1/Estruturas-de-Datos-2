#include "../include/grafo.h"

//se debe leer un archivo 

void crea_grafo(TGrafoMR *g, char *nom_arch){
    char *letras;

    if(!g){
        return;
    }

    //Analizamos el numero de vertices
    g -> nv = calcular_n_vertices(nom_arch);
    if(g -> nv <= 0){
        g -> vertices = NULL;
        g -> mR = NULL;
        return;
    }

    //Creamos la matriz 2D
    crea_arreglo2D(&g -> mR, g -> nv, g -> nv);
    if(!g -> mR){
        g -> vertices = NULL;
        return;
    }

    //Necesitamos uno 1D para los nombres de cada linea
    //Solo sirve para 26 letras
    letras = crea_arreglo1D(g -> nv);
    if(!letras){
        g -> vertices = NULL;
        return;
    }

    g -> vertices = (tipo *)malloc(sizeof(tipo) * g -> nv);
    if(!g -> vertices){
        printf("No se pudo crear el arreglo de vertices\n");
        free(letras);
        return;
    }

    for(int i = 0; i < g -> nv; i++){
        *(g -> vertices + i) = *(letras + i);
    }

    free(letras);

    //Rellenamos el Arreglo 2D con los datos del Archivo.
    ingresar_d(nom_arch, g);
}

void ingresar_d(char *nom_arch, TGrafoMR *g){

    FILE *f;
    char linea[1024];
    int r = 0;

    f = fopen(nom_arch, "r");
    if(!f){
        printf("Error no se pudo abrir tu archivo\n");
        return;
    }

    while(fgets(linea, sizeof(linea), f) && r < g -> nv){

        char *p = linea;
        char *fin;
        int c = 0;
        int tiene_num = 0;

        while(*p != '\0'){

            long valor = strtol(p, &fin, 10);

            if(p == fin){
                p++;
            }else{
                tiene_num = 1;
                if(c < g -> nv){
                    *(*(g -> mR + r) + c) = (int)valor;
                }
                c++;
                p = fin;
            }

        }

        if(tiene_num){
            while(c < g -> nv){
                *(*(g -> mR + r) + c) = 0;
                c++;
            }
            r++;
        }

    }

    while(r < g -> nv){
        for(int c = 0; c < g -> nv; c++){
            *(*(g -> mR + r) + c) = 0;
        }
        r++;
    }

    fclose(f);

}

void crea_arreglo2D(int ***ptr2D, int nr, int c){

    *ptr2D= (int **)malloc(sizeof(int *)*nr);//Arreglo de punteros
    if(!*ptr2D){
        printf("Error\n");
        return;
    }
    
    for(int i=0; i<nr; i++){
    
        *(*ptr2D+i) = (int *) malloc(sizeof(int)*c);
        if(!*(*ptr2D+i)){

            printf("Error no se pudo asignar el espacio de memoria\n");

            while(i>0){

                i--;
                free(*(*ptr2D+i));
            
            }

            free(*ptr2D);
            *ptr2D=NULL;
            return;
        }

        for(int j = 0; j < c; j++){
            *(*(*ptr2D+i)+j) = 0;
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
    int cont_filas = 0;
    int cont_columnas = -1;
    char linea[1024];

    f = fopen(nom_arch, "r");

    if(!f){
        printf("Error al abrir tu archivo\n");
        return -1;
    }

    while(fgets(linea, sizeof(linea), f)){

        char *p = linea;
        char *fin;
        int numeros_linea = 0;

        while(*p != '\0'){

            strtol(p, &fin, 10);

            if(p == fin){
                p++;
            }else{
                numeros_linea++;
                p = fin;
            }

        }

        if(numeros_linea > 0){
            if(cont_columnas == -1){
                cont_columnas = numeros_linea;
            }
            cont_filas++;
        }

    }

    if(cont_filas != cont_columnas){
        printf("Advertencia: la matriz no es cuadrada\n");
    }


    fclose(f);
    return cont_filas;
}

void imprime_grafoMR(TGrafoMR g){

    if(g.nv <= 0 || !g.vertices || !g.mR){
        printf("Grafo vacio\n");
        return;
    }

    printf("   ");
    for(int c = 0; c < g.nv; c++){
        printf("%c ", *(g.vertices + c));
    }
    printf("\n");

    for(int r = 0; r < g.nv; r++){
        printf("%c: ", *(g.vertices + r));
        for(int c = 0; c < g.nv; c++){
            printf("%d ", *(*(g.mR + r) + c));
        }
        printf("\n");
    }

}

void agrega_vertice(TGrafoMR *g, int v){

    int e = 0;

    for(int i=0; i < g->nv;  i++){
        if( *(g->vertices + i ) == v ){
            e=1;
        }
    }

    if (e == 0){
        g -> nv++;
        g -> vertices=(int*) realloc(g -> vertices, sizeof(int)*g -> nv);
        *(g -> vertices + g -> nv -1) = v;
        g -> mR = (int **) realloc(g -> mR, sizeof(int*)*g->nv);
        *(g -> mR + g -> nv -1)=NULL;
        for(int i = 0; i < g -> nv; i++){
            *(g -> mR + i) = (int*)realloc(g -> mR + i, sizeof(int)*g -> nv);
        }
        for(int i = 0; i < g -> nv; i++){
            *(*(g -> mR + i) + g -> nv -1) = 0;
            *(*(g -> mR + g -> nv -1) + i) = 0;
        }
    }

}

void agrega_relacion(TGrafoMR *g, int o, int d, int tip){
    
    int oi=-1, di=-1;

    for(int i = 0; i < g -> nv; i++){
        if(*(g -> vertices + 1) == o){
            oi = i;
        }
        if(*(g -> vertices + i) == d){
            di = i;
        }
    }

    if( oi > -1 && di > -1 ){
        *(*(g -> mR + oi ) + di) = 1;
        if(tip == 1){
            *(*(g -> mR + di ) + oi) = 1;
        }
    }

}

void busqueda_prof(TGrafoMR g, int vo){
    int i;
    int *visitados = (int*)calloc(g.nv, sizeof(int));
    if(visitados){
        for( i=0; i<g.nv && *(g.vertices+i)!=vo; i++);
        if(i < g.nv){
            bprof(g, i, visitados);
        }
    }
    free(visitados);

}

bprof(TGrafoMR g, int v, int *vis){
    int w;
    *(vis+v) = 1;
    printf("%d -> ", *(g.vertices+v));
    for(w = 0; w < g.nv ; w++){
        if( *(*(g.mR+v)+w) == 1 && *(vis+w) == 0 ){
            bprof(g, w, vis);
        }
    }
}

//para el jueves traer en la libreta el algoritmo para la presentacion vector relacion