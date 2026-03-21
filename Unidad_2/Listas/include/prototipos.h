#ifndef PROTOTIPOS_H
#define PROTOTIPOS_H

/*
 * prototipos.h — Archivo de referencia
 *
 * Reúne todos los prototipos de las funciones que existen en
 * Unidad_2/Listas (excepto listas_de_listas).
 *
 * NOTA: Este archivo es solo de consulta. Dado que cada tipo de
 * lista tiene su propio archivo .h, los nombres de funciones se
 * repiten intencionalmente entre secciones (ej. crea_nodo,
 * inserta_inicio, etc.). Para compilar, incluye únicamente el
 * header del tipo de lista que necesites.
 */

/* =====================================================
   Listas Simples  (listas_simples.h)
   ===================================================== */

typedef int tipo;

typedef struct nodo{
    tipo info;
    struct nodo *sig;
}TNodo;

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

/* =====================================================
   Listas Doblemente Enlazadas  (listas_doblemente_enlazadas.h)
   ===================================================== */

typedef struct nodD{
    tipo info;
    struct nodD *sig, *ant;
}TNodoD;

typedef struct {
    TNodoD *ini, *fin;
}TCabs;

TNodoD *crea_nodo(tipo d);
void inicializa(TCabs *cabs);
void inserta_inicio(TCabs *cabs, tipo d);
void inserta_final(TCabs *cabs, tipo d);
void inserta_ordenada(TCabs *cabs, tipo d);
tipo elimina_inicio(TCabs *cabs);
tipo elimina_final(TCabs *cabs);
int elimina_x(TCabs *cabs, tipo x);

/* =====================================================
   Listas Circulares  (listas_circulares.h)
   ===================================================== */

void imprime_lista_cir(TNodo *cab);
void inserta_inicio_cir_ini_fin(TNodo **cab, tipo d, int band);
void inserta_ord_cir(TNodo **cab, tipo d);
void elimina_inicio_final_cir(TNodo **cab, int band);
void elimina_x_cir(TNodo **cab, tipo d);

/* =====================================================
   Listas Circulares Doblemente Enlazadas  (listas_circ_dob_enl.h)
   ===================================================== */

void inserta_inicio_finalDC(TNodoD **cab, tipo d, int band);

#endif
