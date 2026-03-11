#ifndef ALGORITMOS_H
#define ALGORITMOS_H

typedef int tipo;

typedef struct nodo{
	tipo info;
	struct nodo *sig;
}TNodo;

//Listas Simples
TNodo *crea_nodo(tipo d);
void imprime_lista(TNodo *cab);
void inserta_inicio(TNodo **cab, tipo d);
void inserta_final(TNodo **c, tipo d);
void inserta_finalR(TNodo **c, tipo d);
void inserta_ordenado(TNodo **C, tipo d);
void inserta_ordenadoR(TNodo **C, tipo d);
void elimina_inicio(TNodo **c);
tipo elimina_final(TNodo **c);
tipo elimina_finalR(TNodo **c);
int elimina_x(TNodo **cab, tipo x);   
int elimina_xR(TNodo **cab, tipo x);
int menu();

#endif