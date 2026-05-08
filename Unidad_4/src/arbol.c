#include "../include/arbol.h"

void preorden(TNodoB *r){
	if(r != NULL){
		printf("%d ", r -> info);
		preorden(r -> izq);
		preorden(r -> der);
	}
}

void postorden(TNodoB *r){
	if(r != NULL){
		postorden(r -> izq);
		postorden(r -> der);
		printf("%d ", r -> info);
	}
}

void inorden(TNodoB *r){
	if(r != NULL){
		inorden(r -> izq);
		printf("%d ", r -> info);
		inorden(r -> der);
	}
}

int contarNodos(TNodoB *r){
	if(!r){
		return 0;
	}else{
		return(1 + contarNodos(r -> izq) + contarNodos(r -> der));
	}
}

//encontrado llega con 0
void busqueda(TNodoB *r, int numero, int *esta){
	if(r != NULL){
		if(r -> info == numero){
			*esta = 1;
	return;
		}
		busqueda(r -> izq, numero, esta);
		if(*esta != 1){
			busqueda(r -> der, numero, esta);
		}
	}
}

int contar_hojas(TNodoB *r){
	if(*r != NULL){
		if(r -> izq == NULL && r -> der == NULL){
			return 1;
		}else{
			return contar_hojas(r -> izq) + contar_hojas(r -> der);
		}
	}else{
		return 0;
	}
}

int altura(TNodoB *r){
	int izq=0, der=0;
	if( *r != NULL){
		izq = altura(r -> izq);
		der = altura(r -> der);
		if(izq > der){
			return izq + 1;
		}else{
			return der + 1;
		}
	}else{
		return 0;
	}
}

void elimina_nodo(TNodoB **r, tipo clave){
	TNodoB *aux;
	if(	*r != NULL){
		if( clave < (*r) -> info){
			elimina_nodo(&(*r) -> izq, clave);
		}else{
			if(clave > (*r) -> info){
				elimina_nodo(&(*r) -> der, clave);
			}else{
				//se encontro
				aux = *r;
				if(!(*r) -> izq && !(*r) -> der){
					*r = NULL;
					free(aux);
				}else{
					if(!(*r) -> izq){
						*r = aux -> der;
						free(aux);
					}else{
						if(!(*r) -> der){
							*r = aux -> izq;
						}else{
							TNodoB *dato = izq_mas_der(&(*r)->izq);
							(*r) -> info = dato -> info;
							free(dato);
						}
					}
				}
			}
		}
	}	
}

TNodoB *izq_mas_der(TNodoB **r){
	TNodoB *ant = NULL;
	TNodoB *act = *r;
	while( act -> der != NULL ){
		ant = act;
		act = act -> der;
	}
	if(ant != NULL){
		ant -> der = act -> izq;
	}else{
		*r = act -> izq;
	}
	return act;
}