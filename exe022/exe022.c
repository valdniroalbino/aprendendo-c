/*Faça uma função que recebe uma string e um caracter. Retorna o índice
da primeira ocorrência do caracter na string. Se não ocorrer retorna –1.*/

#define TAMANHO 50
#include <stdio.h>

int indice(char palavra[], char letra){
    int i=0;
    while(palavra[i] != '\0'){
        if(palavra[i] == letra)
            return i;
        i++;
    }
    return -1;
}

int main(){
    char palavra[TAMANHO],letra;
    int posicao;

    printf("digite uma palavra: ");
    scanf("%s",palavra);

    printf("\ndigite a letra: ");
    scanf(" %c",&letra);

    posicao = indice(palavra,letra);

    if(posicao != -1)
        printf("a letra aparece na posicao %d ",posicao);
    else
        printf("nao aparece");

    return 0;

}

