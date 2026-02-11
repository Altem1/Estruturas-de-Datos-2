

typedef struct{
    int humedad;
    char unidad;
    int tiposensor;
}humedad;

typedef struct{
    int ppm;
    char tipogas;
    int nivelRiesgo;
}

typedef struct{

    int id;
    char tipo;
    int zona;
    int turno;
    void* dato;

}Equipo;

void captura_equipos(int n, Equipo *ptr){

    for(int i=0; i<n; i++){

        printf("ID: ");
        scanf("%d", &(ptr+i)->id);
        printf("Tipo: ")
        scanf("%c", &(ptr+i)->tipo);
    }

}

int *crea_equipo(int n){

    int *ptra;
    ptra = (int*)malloc(sizeof(int)*n);
    if(!ptra){
        printf("No se puede crear el arreglo\n");
    }
    return ptra;

    switch((ptr+i)->tipo){
        case 'H':
            (ptr+i)->dato=(humedad*)malloc(sizeof(humedad));
            ph=(humedad*)((ptr+i)->dato);
            printf("Humedad: ");
            //por medio de cast para cada campo el otro es 1 cast unico
            //scanf("%d", &((humedad)(ptr+i))->dato);
            scanf("%d", &ph->humedad);
    }

}

int cuenta_humedad(Equipo *ptr, int n){

    for(int i=0; i<n, i++){

        if((ptr+i)->tipo=='H'){
            (((((humedad)(ptr+i)->dato))->humedad)>70);
        }

    }

}