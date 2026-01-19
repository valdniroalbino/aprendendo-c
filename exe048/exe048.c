#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *prox;
}Lista;

typedef struct{
    Lista *ini;
    Lista *fim;
}Fila;

//criar fila

Fila *criarFila(){
    Fila *f=malloc(sizeof(Fila));
    if(f == NULL) return NULL;
    f->ini = NULL;
    f->fim = NULL;

    return f;
}

//inserir

void inserirFila(Fila *f,int v){
    Lista *novo = malloc(sizeof(Lista));
    if(!novo) return;

    novo->valor =v;
    novo->prox =NULL;

    if(f->ini == NULL && f->fim == NULL){
        f->ini = novo;
        f->fim = novo;
    }else{
        f->fim->prox = novo;
        f->fim = novo;
    }
}

//remover

int removerFila(Fila *f){
    if(!f || f->ini == NULL) return 0;

    Lista *aux = f->ini;
    int v = aux->valor;

    f->ini = aux->prox;
    free(aux);

    if(f->ini == NULL){
        f->fim = NULL;
    }

    return v;
}

//fila vazia

int filaVazia(Fila *f){
    return (f->ini == NULL); 
}

//imprir (destruindo)

void imprimirFIla(Fila *f){
    if(!f) return;
    
    while(!filaVazia(f)){
        printf("%d ", removerFila(f));
    }

}

//imprimir 

void imprimirFila(Fila *f){
    if(!f || f->ini == NULL) return;

    Lista *aux = f->ini;
    while(aux != NULL){
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
}

//fila w/prioridade

typedef struct no{
    int senha;
    int prioridade; // 1(com), 0(sem)
    struct no *prox;
}No;

typedef struct{
    No *ini;
    No *fim;
}Fila;

void inserirFilaPrioridade(Fila *f,int senha, int prioridade){
    No *novo = mallloc (sizeof(No));
    if(!novo) return;

    novo->senha = senha;
    novo->prioridade = prioridade;
    novo->prox = NULL;

    if(f->ini == NULL){
        f->ini = novo;
        f->fim = novo;
        return;
    }
    
    if(prioridade == 0){
        f->fim->prox = novo;
        f->fim = novo;
        return;
    }

    if(f->ini->prioridade == 0){
        novo->prox = f->ini;
        f->ini = novo;
        return;
    }

    No *aux = f->ini;
    if(aux->prox != NULL && aux->prox->prioridade == 1){
        aux = aux->prox;
    }
    novo->prox = aux->prox;
    aux->prox = novo;

    if(novo->prox == NULL)
        f->fim = novo;
}
