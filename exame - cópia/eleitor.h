#ifndef ELEITOR_H
#define ELEITOR_H

typedef struct eleitor{
    int id;
    char nome[100];
    int votou; //1 se sim e 0 se nao 
    struct eleitor *prox;
}Eleitor;

Eleitor *criarEleitor(int id,const char *nome);

void inserirEleitor(Eleitor **lista, Eleitor *novo);

Eleitor *procurarEleitor(Eleitor *lista, int id);

int idExiste(Eleitor *lista, int id);

void atualizarEleitor(Eleitor *lista, int id, const char *novoNome);

void jaVotou(Eleitor *e);

void imprimirEleitores(Eleitor *lista);

void carregarEleitoresFicheiro(Eleitor **lista, const char *nomeFicheiro);

void libertarEleitores(Eleitor **lista);

#endif