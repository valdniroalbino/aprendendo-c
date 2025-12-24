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

LCD *imprimirLCD(LCD *l){
    if(l){
        LCD *aux = l;
        do{
            printf("%d ",aux->valor);
        }while(aux->prox != l)
        
    }
}

// Inserir no início 

