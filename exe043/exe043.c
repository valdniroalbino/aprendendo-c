#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void imprimir_n_1(int n){
    if(n == 0) return;
    printf("%d -",n);
    imprimir_n_1(n-1);
}

void imprimir_1_n(int n){
    if(n == 0) return;

    imprimir_1_n(n-1);
    printf("%d ",&n);
}

void ola(int n){
    if(n == 4) return;

    puts("olá ");
    ola(n+1);
}

int soma(int n){
    if(n == 0) return 0;

    return n + soma(n-1);
}

int digitos(int n){
    if(n < 10) return 1;
    
    return 1 + digitos(n/10);
}

int potencia(int n, int v){
    if(v == 0) return 1;
  
    return n * potencia(n,v-1);
}


int main(){
    printf("%d",potencia(2,3));
    return 0;
}


/*
void removerN(struct no **l,int v){
    struct no *aux =*l;
    if(aux == NULL){
        puts("lista vazia");
        return;
    }
    while(aux != NULL){
        if(aux->valor == v){
            aux->ant->prox = aux -> prox;
            aux->prox->ant = aux -> ant;
            free(aux);
            return;
        }
            aux = aux -> prox;
    }
    puts("valor nao encontrado!");
    return;
}
*/