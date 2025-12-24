#include <stdlib.h>
#include <stdio.h>


struct no{
    int valor;
    struct no *prox;
    struct no *ant;
};

typedef struct no LCD;

//cria LCD 

LCD * criarLCD(LCD *l){
    l = NULL;
    return l;
}

//imprimir 

void imprimirLCD(LCD *l){
    if(l){
        if(l->prox == l && l->ant == l){
            printf("%d ",l->valor);
            return;
        }

        LCD *aux = l;
        do{
            printf("%d ",aux->valor);
            aux = aux->prox;
        }while(aux != l);
    }else{
        return;
    }
}

// Inserir no início 

LCD *inserirI(LCD *l,int v){
    LCD *novo = malloc(sizeof(LCD));
    if(novo == NULL){
        puts("erro de alocacao");
        return l;
    }

    novo->valor = v;

    if(l == NULL){
        novo->prox = novo;
        novo->ant  = novo;
        return novo;
    }

    novo->prox = l;
    novo->ant  = l->ant;
    l->ant->prox = novo;
    l->ant = novo;

    return novo;
}

