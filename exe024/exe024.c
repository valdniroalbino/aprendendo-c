/*Escreva uma função que receb um número e verifica se o mesmo é
capicua. Um número é dito ser capicua quando lido da esquerda para a
direita é o mesmo que quando lido da direita para a esquerda. O
número 2002, por exemplo, é capicua.*/

#include <stdio.h>

void capicua(int numero){
    int invertido = 0,resto ;
    int original = numero ;
    while(numero >0){
        resto = numero %10;
        invertido = invertido * 10 + resto;
        numero /= 10;

    }

    if( original == invertido)
        printf("é capicua!");
    else
        printf("nao é capicua");
}

int main(){
    int numero;

    printf("digite um numero: ");
    scanf("%d",&numero);

    capicua(numero);

    return 0;
}

