#include "../include/arbol.h"

void preorden(TNodoB *r) {
  if (r != NULL) {
    printf("%d ", r->info);
    preorden(r->izq);
    preorden(r->der);
  }
}

void postorden(TNodoB *r) {
  if (r != NULL) {
    postorden(r->izq);
    postorden(r->der);
    printf("%d ", r->info);
  }
}

void inorden(TNodoB *r) {
  if (r != NULL) {
    inorden(r->izq);
    printf("%d ", r->info);
    inorden(r->der);
  }
}

int contarNodos(TNodoB *r) {
  if (!r) {
    return 0;
  } else {
    return (1 + contarNodos(r->izq) + contarNodos(r->der));
  }
}

// encontrado llega con 0
int busqueda(TNodoB *r, int numero) {
  if (r == NULL) {
    return 0;
  }

  if (r->info == numero) {
    return 1;
  }

  if (busqueda(r->izq, numero) == 1) {
    return 1;
  }

  return busqueda(r->der, numero);
}

int contar_hojas(TNodoB *r) {
  if (r != NULL) {
    if (r->izq == NULL && r->der == NULL) {
      return 1;
    } else {
      return contar_hojas(r->izq) + contar_hojas(r->der);
    }
  } else {
    return 0;
  }
}

int altura(TNodoB *r) {
  int izq = 0, der = 0;
  if (r != NULL) {
    izq = altura(r->izq);
    der = altura(r->der);
    if (izq > der) {
      return izq + 1;
    } else {
      return der + 1;
    }
  } else {
    return 0;
  }
}

void elimina_nodo(TNodoB **r, tipo clave) {
  TNodoB *aux;
  if (*r != NULL) {
    if (clave < (*r)->info) {
      elimina_nodo(&(*r)->izq, clave);
    } else {
      if (clave > (*r)->info) {
        elimina_nodo(&(*r)->der, clave);
      } else {
        // se encontro
        aux = *r;
        if (!(*r)->izq && !(*r)->der) {
          *r = NULL;
        } else {
          if (!(*r)->izq) {
            *r = aux->der;
          } else {
            if (!(*r)->der) {
              *r = aux->izq;
            } else {
              aux = izq_mas_der(&(*r)->izq);
              (*r)->info = aux->info;
            }
          }
        }
      }
    }
  }
  free(aux);
}

TNodoB *izq_mas_der(TNodoB **r) {
  TNodoB *ant = NULL;
  TNodoB *act = *r;
  while (act->der != NULL) {
    ant = act;
    act = act->der;
  }
  if (ant != NULL) {
    ant->der = act->izq;
  } else {
    *r = act->izq;
  }
  return act;
}

TNodoB *izq_mas_der_rec(TNodoB **r) {
  TNodoB *aux;
  if ((*r)->der == NULL) {
    aux = *r;
    *r = (*r)->izq;
  } else {
    aux = izq_mas_der_rec(&((*r)->der));
  }

  return aux;
}

void inserta(TNodoB **r, tipo clave) {
  if (*r == NULL) {
    *r = (TNodoB *)malloc(sizeof(TNodoB));
    (*r)->info = clave;
    (*r)->izq = NULL;
    (*r)->der = NULL;
  } else {
    if (clave < (*r)->info) {
      inserta(&((*r)->izq), clave);
    } else if (clave > (*r)->info) {
      inserta(&((*r)->der), clave);
    }
  }
}
