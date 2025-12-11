#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sorteio.h"

void criarLista(LCD *l){
    *l = NULL;
}

void addCandidato(LCD *l, char nome[]){
    no *novo = malloc(sizeof(no));
    if (!novo) {
        puts("erro de alocação..");
        return;
    }

    if (strlen(nome) <= sizeof(novo->candidato)-1) {
        strcpy(novo->candidato, nome);
    } else {
        puts("nome demasiado grande.");
        free(novo);
        return;
    }

    if (*l == NULL) {
        novo->prox = novo;
        novo->ant  = novo;
        *l = novo;
    } else {
        no *aux = *l;        
        novo->prox = aux;   
        novo->ant  = aux->ant; 

        aux->ant->prox = novo; 
        aux->ant = novo;      

        *l = novo;            
    }

    puts("candidato adicionado com sucesso");
}

void imprimirLista(LCD *l){
    no *aux = *l;
    if( *l != NULL){
        do{
         printf(" %s  ",aux->candidato);
         if(aux->prox == *l) break;
         aux = aux->prox;
        }while( aux != *l );
    }else{
        puts("lista vazia!");
        return;
    }
}

void sortear(LCD *l,int x, int inicio){
    if( *l == NULL){
        puts("lista vazia.");
        return;
    }
    
    if(x <= 0) x = 1; //ou seja, se o valor aleatoriodado pelo usuario for
                      //negativo comecamos logo com 1.
    if((*l)->prox == *l){
        printf("Unico participante do sorteio,logo..\n%s é o vencedor! ",(*l)->candidato);
        return;
    }

    no *aux = *l;

    if(inicio > 0){
        for (int i = 0; i < inicio; ++i) {
            aux = aux->prox;
        }
    }

    while( (*l)->prox != *l){
        aux = aux->prox;

        for (int i = 1; i < x; ++i) {
            aux = aux->prox;
        }

        no *lixo = aux;
        no *PROX = lixo->prox;

        printf("%s foi eliminado \n",lixo->candidato);

        lixo->ant->prox = lixo->prox;
        lixo->prox->ant = lixo->ant;

        if(lixo == *l) *l = PROX;

        free(lixo);

        aux = PROX;

        if((*l)->prox == *l) break;
    }
    printf("Vencedor: %s\n", (*l)->candidato);
}   

void freeLCD(LCD *l){
    if(l == NULL) return;

    no *aux = *l;  
    no *PROX = aux->prox;

    if(PROX == aux){
        free(aux);
        *l = NULL;
        return;
    }

    while(PROX != aux){
        no *temporario = PROX->prox;
        free(PROX);
        PROX = temporario;
    }

    free(aux);
    *l = NULL;
}