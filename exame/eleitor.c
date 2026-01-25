#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "eleitor.h"

Eleitor *criarEleitor(int id, const char *nome){
    Eleitor *novo = malloc (sizeof(Eleitor));
    if(novo == NULL) return NULL;

    novo->id = id;
    strncpy(novo->nome,nome,99);
    novo->nome[99] = '\0';
    novo->votou = 0;
    novo->prox = NULL;

    return novo;
}

Eleitor *procurarEleitor(Eleitor *lista, int id){
    while(lista != NULL){
        if(lista->id == id){
            return lista;
        }
        lista = lista->prox;
    }
    return NULL;
}

int idExiste(Eleitor *lista, int id){
    Eleitor *e;

    e = procurarEleitor(lista, id);

    if(e != NULL){
        return 1;   // id existe
    } else {
        return 0;   // id não existe
    }
}

void inserirEleitor(Eleitor **lista, Eleitor *novo){
    if(novo == NULL) return;

    if(*lista == NULL){
        *lista = novo;
        return;
    }

    Eleitor *aux = *lista;
    while(aux->prox != NULL){
        aux = aux->prox;
    }

    aux->prox = novo;
}

void atualizarEleitor(Eleitor *lista, int id, const char *novoNome){
    Eleitor *e = procurarEleitor(lista, id);

    if(e != NULL){
        strncpy(e->nome, novoNome, 99);
        e->nome[99] = '\0';
    }
}

void jaVotou(Eleitor *e){
    if(e != NULL){
        e->votou = 1;
    }
}

void imprimirEleitores(Eleitor *lista){
    while(lista!=NULL){
        printf("ID:%d | Nome:%s | Votou:%s\n",
               lista->id,
               lista->nome,
               lista->votou?"Sim":"Nao");
        lista=lista->prox;
    }
}

void carregarEleitoresFicheiro(Eleitor **lista,const char *nomeFicheiro){
    FILE *f=fopen(nomeFicheiro,"r");
    if(f==NULL){
        printf("Erro ao abrir ficheiro\n");
        return;
    }

    char nome[100];
    int id;
    int votou;

    while(fscanf(f,"%99s %d %d",nome,&id,&votou)==3){
        Eleitor *novo=criarEleitor(id,nome);
        if(novo!=NULL){
            inserirEleitor(lista,novo);
        }
    }

    fclose(f);
}

void libertarEleitores(Eleitor **lista){
    Eleitor *aux;
    while(*lista!=NULL){
        aux=*lista;
        *lista=(*lista)->prox;
        free(aux);
    }
}





