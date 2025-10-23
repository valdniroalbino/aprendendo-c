/*Escreva uma função chamada troca, que troca os valores dos parâmetros
recebidos. Sua assinatura deve ser: troca(float *a, float *b);*/

#include <stdio.h>

void troca(float *a, float *b){
    float temp = *a;
    *a = *b ;
    *b = temp;
}

int main(){
    float a = 10.0 , b = 15.0 ;

    troca(&a,&b);

    printf("a: %.2f\nb: %.2f ",a,b);

    return 0;
}
