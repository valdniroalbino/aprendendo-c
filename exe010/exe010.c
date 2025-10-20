/*Escreva um programa que solicite 10 números entre positivos e negativos
ao utilizador, através de um laço while, e no final mostre qual destes
números é o maior.*/

#include <stdio.h>

int main(){
    int i=1,maior = 0,numero;

    while(i <= 5){
        printf("digite um numero: ");
        scanf("%d",&numero);

        //maior = numero; 

        if(numero > maior)
            maior = numero;
        i++;
    }

    printf("o maior numero é: %d",maior);

    return 0;
}