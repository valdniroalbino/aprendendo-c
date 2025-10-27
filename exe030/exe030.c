/*Crie uma função que receba uma string como parâmetro e retorne uma
cópia da mesma. A assinatura da função deve ser: char *strcopia(char *str);*/

#include <stdio.h>

void *strcopia(char *str);

int main(){
    char palavra[100];

    printf("digite uma string qualquer: ");
    fgets(palavra,sizeof(palavra),stdin);

    strcopia(palavra);

    return 0;

}

void *strcopia(char *str){
    char copy[100] = *str;

    printf("copida: %s ",copy);
}