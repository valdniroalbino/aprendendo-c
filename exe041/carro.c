#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "carro.h"

void criarLista(struct no **l){
    *l = NULL;
}

void addInicio(struct no **l, struct carro car){
    struct no *novo = (struct no*) malloc(sizeof(struct no));
    novo->car = car;
    novo->prox = *l;
    *l = novo;
}

void addFim(struct no **l, struct carro car){
    struct no *novo = (struct no*) malloc(sizeof(struct no));
    novo->car = car;
    novo->prox = NULL;

    if(*l == NULL){
        *l = novo;
    } else {
        struct no *aux = *l;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = novo;
    }
}

void imprimirLista(struct no **l){
    struct no *aux = *l;
    while(aux != NULL){
        printf("Marca: %s\n", aux->car.marca);
        printf("Matricula: %s\n", aux->car.matricula);
        printf("Proprietario: %s\n", aux->car.proprietario);
        printf("VIN: %s\n", aux->car.vin);
        printf("-----------------\n");
        aux = aux->prox;
    }
}

void tirarPorVin(struct no **l, char vin[]){
    struct no *aux = *l;
    struct no *ant = NULL;

    while(aux != NULL){
        if(strcmp(aux->car.vin, vin) == 0){
            if(ant == NULL){
                *l = aux->prox;
            } else {
                ant->prox = aux->prox;
            }
            free(aux);
            return;
        }
        ant = aux;
        aux = aux->prox;
    }
}

void tirarNPrimeiros(struct no **l, int n){
    struct no *aux;
    while(n > 0 && *l != NULL){
        aux = *l;
        *l = (*l)->prox;
        free(aux);
        n--;
    }
}

void liberarLista(struct no **l){
    struct no *aux;
    while(*l != NULL){
        aux = *l;
        *l = (*l)->prox;
        free(aux);
    }
}

int listasIguais(struct no **l1, struct no **l2){
    struct no *aux1 = *l1;
    struct no *aux2 = *l2;

    while(aux1 != NULL && aux2 != NULL){

        if(strcmp(aux1->car.vin, aux2->car.vin) != 0){
            return 0;
        }

        aux1 = aux1->prox;
        aux2 = aux2->prox;
    }

    if(aux1 == NULL && aux2 == NULL){
        return 1;
    }

    return 0;
}



