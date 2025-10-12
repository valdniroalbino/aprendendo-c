//Peça um número e diga se ele é positivo, negativo ou zero.

#include <stdio.h>

int main(){

    int numero;
    
    printf("digite um numero: ");
    scanf("%d",&numero);

    if(numero>0){
        printf("\npositivo");
    }else if(numero<0){
        printf("\nnegativo");
    }else{
        printf("\nigual a zero");
    }
    return 0;
}