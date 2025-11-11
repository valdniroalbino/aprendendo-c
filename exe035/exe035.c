/*Crie uma função que receba um vetor e retorne um novo vetor 
alocado dinamicamente contendo os mesmos valores.*/

#include <stdio.h>
#include <stdlib.h>

int *copiaVetor(int *v, int n){
    int *p = NULL;

    p = (int *)malloc(n * sizeof(int));

    if(p==NULL){
        puts("erro na alocacao");
        return NULL;
    }

    for(int i=0;i<n;i++){
       *(p+i) = *(v+i);
    }

    return p;
}