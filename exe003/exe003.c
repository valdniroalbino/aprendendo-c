//Leia o nome, idade e altura de uma pessoa e depois mostre uma frase

#include <stdio.h>

int main(){

    int idade;
    float altura;
    char nome[20];

    printf("digite o seu nome: ");
    scanf("%s",nome);
    
    printf("\ndigite a sua idade: ");
    scanf("%d",&idade);

    printf("\ndigite a sua altura: ");
    scanf("%f",&altura);

    printf("Olá %s, sua idade é %d e sua altura é %.2f ",nome,idade,altura);

    return 0;
}