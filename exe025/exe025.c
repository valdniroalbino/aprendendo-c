#define TAMANHO 100


void maior(int vetor[],int v){
    int maior=0;
    for(int i=0; i<TAMANHO; i++){
        if(vetor[i]>maior)
            maior = vetor [i];
    }
    
}