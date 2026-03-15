#include "../include/listas_circ_dob_enl.h"

void inserta_inicio_finalDC(TNodoD **cab, tipo d, int band){

    TNodoD *aux;

    if(!*cab){
        *cab = crea_nodoD(d);
        (*cab) -> sig = (*cab) -> ant = *cab;
    }else{

        aux = crea_nodoD(d);
        aux -> sig = *cab;
        aux -> ant = (*cab) -> ant;
        (*cab) -> ant = aux;
        aux -> ant -> sig = aux;
        if(band=0){ //Si es 0 insertamos al inicio
            *cab = aux;
        }
    }
}

//Tarea martes funcion inserta ordenado, elimina inicio, elimina final
