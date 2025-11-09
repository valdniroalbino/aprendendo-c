/*Escreva uma função que receba um vetor de inteiros 
e troque o primeiro elemento com o último,
utilizando apenas ponteiros 
(sem usar [] dentro da função).*/

#include <stdio.h>

void trocaExtremos(int *v, int size){
    int i = 0;
    int temp;

    temp = *(v + i); 
    size -= 1;
    *(v + i) = *(v+size);
    *(v + size) = temp;

    //printf("\n%d ",temp);
}

int main(){
    int size;

    printf("digite o tamanho do vetor: ");
    scanf("%d",&size);

    int v[size];

    for(int i = 0; i < size; i++){
        printf("digite o %d elemento do vetor: ",i+1);
        scanf("%d",&v[i]);
    }
    trocaExtremos(v,size);

    for(int i = 0; i < size; i++){
       printf("%d ",v[i]);
    }

    return 0;
}
