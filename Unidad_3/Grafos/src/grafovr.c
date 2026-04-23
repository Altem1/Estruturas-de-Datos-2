#include "../include/grafovr.h"

void crea_grafo(TGrafo *g){

    g -> num_vertices = 0;
    g -> capacidad = 0;
    g -> conexiones = (TArreglo*)calloc(1, sizeof(TArreglo));

}

void insertar_conexion(TGrafo *g, Tipo origen, Tipo destino){

    int Ori = existe_vertice(g, origen);
    int Des = existe_vertice(g, destino);

    //ver si existe el origen y el destino
    if( Ori == 1 && Des == 1 && existe_conexion(g, origen, destino) != 1 ){
        //hacer la conexion de origen y destino
        for(int i = 0; i < g -> num_vertices; i++){
            if( (g -> conexiones + i) -> dato == origen ){
                inserta_inicio(&((g -> conexiones + i ) -> conexion), destino);
            }
        }
        //en caso de que no exista
    }else if (Ori == 0 || Des == 0  ){
        if (Ori == 0) inserta_vertice(&g , origen);
        if (Des == 0) inserta_vertice(&g , destino);
        insertar_conexion(g, origen, destino);
    }

}

void inserta_inicio(TLista **c, Tipo destino){
    TLista *aux;
    aux = crea_nodoA(destino);
    if(aux){
        aux -> siguiente = *c;
        *c = aux;
    }
}

TLista *crea_nodoA(Tipo destino){
	TLista *aux=NULL;
	aux = (TLista *) malloc (sizeof(TLista));
	if(aux != NULL){
		aux -> destino = destino;
		aux -> siguiente = NULL;
	}
	return aux;
}

int existe_vertice(TGrafo *g,Tipo dato){

    int existe=0;

    for(int i = 0; i < g -> num_vertices; i++ ){
        if( (g -> conexiones + i) -> dato == dato ){
            existe = 1;
            break;
        }
    }

    return existe;
}

void inserta_vertice(TGrafo *g, Tipo dato) {
    if (g->num_vertices == g->capacidad) {
        int nueva_capacidad = (g->capacidad == 0) ? 1 : g->capacidad * 2;
        
        TArreglo *nuevo = (TArreglo*)realloc(g->conexiones, nueva_capacidad * sizeof(TArreglo));
        
        if (nuevo != NULL) {
            g->conexiones = nuevo;
            g->capacidad = nueva_capacidad;
        }
    }

    (g->conexiones + g->num_vertices)->dato = dato;
    (g->conexiones + g->num_vertices)->conexion = NULL;

    g->num_vertices++;
}

int existe_conexion(TGrafo *g, Tipo origen, Tipo destino) {
    for (int i = 0; i < g->num_vertices; i++) {
        if ((g->conexiones + i)->dato == origen) {
            
            TLista *aux = (g->conexiones + i)->conexion;
            
            while (aux != NULL) {
                if (aux->destino == destino) {
                    return 1;
                }
                aux = aux->siguiente;
            }
        }
    }
    return 0;
}

int buscar_indice(TGrafo *g, Tipo dato) {
    for (int i = 0; i < g->num_vertices; i++) {
        if ((g->conexiones + i)->dato == dato) return i;
    }
    return -1;
}

void busqueda_prof_VR(TGrafo *g, Tipo vo) {
    int *visitados = (int*)calloc(g->num_vertices, sizeof(int));
    int i;

    if (visitados) {
        for (i = 0; i < g->num_vertices && (g->conexiones + i)->dato != vo; i++);

        if (i < g->num_vertices) {
            bprof_VR(g, i, visitados);
        }
        
        free(visitados);
    }
}

void bprof_VR(TGrafo *g, int v, int *vis) {
    *(vis + v) = 1;
    printf("%d -> ", (g->conexiones + v)->dato);

    TLista *aux = (g->conexiones + v)->conexion;

    while (aux != NULL) {
        int indice_vecino = buscar_indice(g, aux->destino);

        if (indice_vecino != -1 && *(vis + indice_vecino) == 0) {
            bprof_VR(g, indice_vecino, vis);
        }
    
        aux = aux->siguiente;
    }
}

void imprime_grafo(TGrafo *g){

}

void destruye_grafo(TGrafo *g){

}