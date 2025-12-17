#ifndef PILHA_H
#define PILHA_H

typedef struct no{
    int valor;
    struct no *prox;
}no;

typedef struct{
    no *topo;
}pilha;

void criarPilha(pilha *p);
int pilhaVazia(pilha *p);
void push(pilha *p,int v);
int pop(pilha *p);
int topo(pilha *p);
void freePilha(pilha *p);

#endif