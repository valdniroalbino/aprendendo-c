/*Crie uma função que receba uma string como parâmetro e retorne uma
cópia da mesma. A assinatura da função deve ser: char *strcopia(char *str);*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *strcopia(char *str);

int main(){
    char palavra[100],*copia;

    printf("digite uma string qualquer: ");
    fgets(palavra,sizeof(palavra),stdin);

    copia = strcopia(palavra);

    printf("Cópia: %s\n", copia);

    free(copia); 

    return 0;
}

char *strcopia(char *str){

    int tamanho = strlen(str);

    char *copy = (char *)malloc((tamanho + 1) * sizeof(char));

    if(copy == NULL){
        printf("erro ao alocar memoria\n");
        return NULL;
    }

    strcpy(copy,str);

    return copy;

}

