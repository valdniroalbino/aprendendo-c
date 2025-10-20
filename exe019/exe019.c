/*Faça um programa que lê um número inteiro e mostra a soma dos seus
dígitos. Por exemplo: Entrada = 234, Saída : 9*/

#include <stdio.h>

int main(){
    int result=0,n;

    printf("digite o numero: ");
    scanf("%d",&n);

    while(n>0){
        result += n%10;
        n /= 10;
    }

    printf("a soma dos digitos é: %d ",result);

    return 0;
}