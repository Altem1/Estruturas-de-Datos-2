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