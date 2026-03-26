#include "../include/listas_de_listas.h"

void inserta_alumno(int clave, char *nombre, char *carrera, TNCarrera **Cab){

    TNCarrera *aux;
    aux = inserta_ordenado(Cab, carrera);
    inserta_ordenadoA(&aux -> lista, clave, nombre);


}

TNCarrera *inserta_ordenado(TNCarrera **c, char *carrera){

    TNCarrera *aux;

    if( !*c || strcmp(carrera, (*c)->carrera)<0){

        aux = crea_nodo(carrera);
        aux -> sig = *c;
        *c = aux;
    }
    else 
        if( strcmp(carrera, (*c)->carrera) == 0 ){
            aux = *c;
        }else{
            aux = inserta_ordenado(&(*c)->sig, carrera);
        }

    return aux;

}

void inserta_ordenadoA(TNAlumno **cab, int clave, char *nombre){

    if(!*cab || (*cab)->clave > clave){
        inserta_inicio(cab, clave, nombre);
    }else
        inserta_ordenadoA((&(*cab)->sig), clave, nombre);
}

void inserta_inicio(TNAlumno **c, int clave, char *nombre){
    
    TNAlumno *aux;
    aux = crea_nodoA(c, clave, nombre);

    if(aux){
        
        aux -> sig = *c;
        *c = aux;

    }
    
}

TNCarrera *crea_nodoC(char *carrera){
	TNCarrera *aux;
	aux = (TNCarrera *) malloc (sizeof(TNCarrera));
	if(aux != NULL){
		aux -> carrera;
		aux -> sig = NULL;
	}
	return aux;
}

TNAlumno *crea_nodoA(char *c, int clave, char *nombre){
	TNAlumno *aux=NULL;
	aux = (TNAlumno *) malloc (sizeof(TNAlumno));
	if(aux != NULL){
		aux -> clave = clave;
        aux -> nombre = nombre;
		aux -> sig = NULL;
	}
	return aux;
}

//Regresa el nodo anterior al que queremos
void buscar_clave(TNCarrera **cab, int clave, TNAlumno **aux){
    *aux = NULL;
    TNAlumno *anterior;
    //recorre la parte de la lista principal carreras
    for (TNCarrera *correC = *cab; correC != NULL; correC = correC -> sig){
        TNAlumno *correA = &(correC -> lista);
        anterior = correA;
        while ((correA = correA -> sig) != NULL){
            
            if (correA -> clave == clave){
                //Encontro la clave
                *aux = anterior;
                return;
            }
            anterior = correA;
        }
    }
    return;
}

void elimina_x_clave(TNCarrera **c, int clave){

    TNAlumno *aux = NULL;
    TNAlumno *aux2 = NULL;
    buscar_clave(c, clave, &aux);

    if(aux == NULL || aux -> sig == NULL){
        printf("No se encontro esa clave dentro de la lista.");
        return;
    }

    aux2 = aux -> sig;

    if(aux2 -> clave != clave){
        printf("No se encontro esa clave dentro de la lista.");
        return;
    }

    aux -> sig = aux2 -> sig;

    free(aux2);

}