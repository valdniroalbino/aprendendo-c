#ifndef SORTEIO_H
#define SORTEIO_H

typedef struct no{
    char candidato[50];
    struct no *prox;
    struct no *ant;
}no;

typedef struct no *LCD;

void criarLista(LCD *l);
void addCandidato(LCD *l,char nome[]);
void imprimirLista(LCD *l);
void sortear(LCD *l,int x, int inicio);
void free(LCD *l);

#endif 