#include<stdio.h>
#define TAM 10

void captura(int *pa, int x);
void suma(int *pa1, int *pa2, int *pa3, int x);
void imprimir(int *pa,int x);

int main(){
    
    //Se crearon los 3 arreglos a usar
    int a1[TAM], a2[TAM], a3[TAM];
    int tam;
    int t;

    //Pedimos la cantidad de espacios
    printf("Cuantos numeros ingresaras: ");
    scanf("%d", &tam);
    if(tam>TAM){
        //Si el numero supera el limite marcamos un aviso y usa el tamaño de tam
        printf("El nunero ingresado supera el limite, se definira con el limite %d", TAM);
        t=TAM;
    }else{
        //En caso de que no lo supere se da el tamaño que el usuario ingreso
        t=tam;
    }
    printf("\nCaptura arreglo 1: \n");
    captura(a1, t);
    printf("\nCaptura arreglo 2: \n");
    captura(a2, t);
    suma(a1, a2, a3, t);

    printf("\nArreglo 1: \n");
    imprimir(a1, t);
    printf("\nArreglo 2: \n");
    imprimir(a2, t);
    printf("\nArreglo 3: \n");
    imprimir(a3, t);
}

//Se paso el arreglo como apuntador
void captura(int *pa, int x){


    for(int i=0; i<x; i++){
        printf("Ingresa el %d elemento del arreglo: ", i+1);
        scanf("%d", (pa+i));
        //El scanf en este caso lo usamos en su forma de apuntador no [i]
        //(pa+i) indica el lugar donde se debe guarda el i es el aumento de posicion 
    }

}

//Pasamos los 3 arreglos como apuntadores para la suma
void suma(int *pa1, int *pa2, int *pa3, int x){

    int i=0;
    int xt=x;
    //Use un while por un poco de simplicidad
    while(i<x){

        //Lo que hago aqui es acceder al valor que esta guardando la direccion
        //no la direccion, pa1 empieza en posicion 0 y pa2 en N-1
        *(pa3+i) = *(pa1+i) + *(pa2+(xt-1-i));
        //Se cambia de posicion
        i++;
        xt=x;

    }

}

//solo se pasa un apuntador ya que sera llamado varias veces
void imprimir(int *pa,int x){

    for(int i=0; i < x; i++){
        //Accedemos al valor no a la direccion para mostrar cada valor del arreglo.
        printf("[ %d ]", *(pa+i));

    }

}
