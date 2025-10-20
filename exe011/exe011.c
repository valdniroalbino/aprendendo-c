/*Faça um programa que leia o nome completo de um utilizador para uma
única variável e imprima a quantidade de vogais do nome.*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

 int main(){
    char nome[100];
    int qnt_v=0;

    printf("digite o seu nome completo: ");
    fgets(nome, sizeof(nome), stdin);

    for(int i = 0; nome[i] != '\0'; i++){
        char letra  = tolower(nome[i]);

        if( letra == 'a' || letra == 'e' || letra == 'i' ||  letra == 'o' ||  letra == 'u')
            qnt_v++;
    }

    printf("o nome tem ", qnt_v > 1 ? "%d vogais" : "%d vogal" ,qnt_v);

    /*if(qnt_v > 1)
        printf("o nome tem %d vogais ",qnt_v);
    else
        printf("o nome tem %d vogal ",qnt_v);*/

    return 0;
}