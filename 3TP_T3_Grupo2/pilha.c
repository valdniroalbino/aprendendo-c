#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

void criarPilha(pilha *p){
    p->topo = NULL;
}

int pilhaVazia(pilha *p){
    return (p->topo == NULL);
}

void push(pilha *p,int v){
    no *novo = malloc(sizeof(no));
    if(novo == NULL){
        puts("erro de alocacao");
        return;
    }
    novo->valor = v;
    novo->prox = p->topo;
    p->topo = novo;
}

int pop(pilha *p){
    if(pilhaVazia(p)){
        puts("pilha vazia");
        return -1;
    }

    no *temp = p->topo;
    int valor = temp->valor;

    p->topo = temp->prox;
    free(temp);

    return valor;
}

int topo(pilha *p){
    if(pilhaVazia(p)){
        puts("Pilha vazia");
        return -1;
    }

    return p->topo->valor;
}

void freePilha(pilha *p){
    while(!pilhaVazia(p)){
        pop(p);
    }
}