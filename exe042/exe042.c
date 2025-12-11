/*Faça um programa em C que leia vários números inseridos pelo
utilizador e cria uma lista ligada simples com os elementos lidos. De
seguida, imprima de forma inversa a lista criada.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct no{
    int valor;
    struct no *prox;
};
struct no *l=NULL;

void addLista(struct no **l,int n){
    struct no *novo = malloc(sizeof(struct no));
    if(l == NULL){
        puts("erro de alocacao");
    }
    novo->valor = n;
    novo->prox = *l;
    *l = novo;

    printf("add com sucesso!\n");

}

void printLista(struct no *l){
    while(l == NULL){
        puts("lista vazia!");
        return;
    }
    /*printLista(l->prox);
    printf("%d ",l->valor);*/
    struct no *aux =l;
    while(aux != NULL ){
    printf("%d -",aux->valor);
    aux = aux -> prox;
    }

}



int main(){
    int n,rep;
    struct no *l=NULL;

    printf("repeticoes:  ");
    scanf("%d",&rep);
    
    for(int i=0;i<rep;i++){
        printf("%dº numero: ",i+1);
        scanf("%d",&n);

        addLista(&l,n);
    }

    printLista(l);

    return 0;
}
