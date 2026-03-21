int n_entrenamiento(Dispositivos *arr, int nr){

    int cont = 0;
    for(int i = 0; i < nr; i++){
        if((arr+i)->tipo ==1 ){
            if((RitmoCardiaco *)((arr + i)-> dato)-> ritmos>160){
                cont ++;
            }
        }
    }
}