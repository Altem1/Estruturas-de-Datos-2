#include "include/arbol.h"
#include <stdio.h>

int main() {
  TNodoB *arbol = NULL;
  int opcion, numero, esta, hojas, alto, nodos;
  tipo clave;
  do {
    opcion = menu();
    switch (opcion) {
    case 1:
      printf("\nValor a insertar: ");
      scanf("%d", &clave);
      inserta(&arbol, clave);
      break;
    case 2:
      preorden(arbol);
      break;
    case 3:
      postorden(arbol);
      break;
    case 4:
      inorden(arbol);
      break;
    case 5:
      nodos = contarNodos(arbol);
      printf("%d\n", nodos);
      break;
    case 6:
      printf("\nQue valor deseas buscar: ");
      scanf("%d", &numero);
      esta = busqueda(arbol, numero);
      if (esta == 1) {
        printf("Si se encuentra en el arbol\n");
      } else {
        printf("No se encuentra en el arbol\n");
      }
      break;
    case 7:
      hojas = contar_hojas(arbol);
      printf("%d\n", hojas);
      break;
    case 8:
      alto = altura(arbol);
      printf("%d\n", alto);
      break;
    case 9:
      elimina_nodo(&arbol, clave);
      break;
    }

    printf("\nPresiona Enter para continuar...");

    while (getchar() != '\n')
      ;
    getchar();
    system("clear");

  } while (opcion < 10);
}

int menu() {
  int opcion;
  printf("\n1.- Insertar nodo");
  printf("\n2.- Imprimir preorden");
  printf("\n3.- Imprimir postorden");
  printf("\n4.- Imprimir inorden");
  printf("\n5.- Contar nodos");
  printf("\n6.- Busqueda");
  printf("\n7.- Contar hojas");
  printf("\n8.- Altura");
  printf("\n9.- Eliminar nodo");
  printf("\n10.- Salir");
  printf("\nSeleccion: ");
  scanf("%d", &opcion);

  return opcion;
}
