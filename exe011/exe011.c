/*Faça um programa que leia o nome completo de um utilizador para uma
única variável e imprima a quantidade de vogais do nome.*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    char nome[100];
    int vogais=0;

    printf("digite o seu nome completo: ");
    fgets(nome, sizeof(nome), stdin);

    for(int i = 0; nome[i] != '\0'; i++){
        char c = tolower(nome[i]);

        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            vogais++;
    }

    printf("o nome tem %d vogais ",vogais);

    return 0;
}