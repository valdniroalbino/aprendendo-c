#ifndef SISTEMA_H
#define SISTEMA_H

#include <stdio.h>
#include <stdlib.h>

#define NUM_URNAS 3

/* ELEITORES */

typedef struct Eleitor{
    int id;
    char nome[100];
    int votou;
    struct Eleitor *prox;
}Eleitor;

Eleitor *criarEleitor(int id,const char *nome);
void inserirEleitor(Eleitor **lista,Eleitor *novo);
Eleitor *procurarEleitor(Eleitor *lista,int id);
int idExiste(Eleitor *lista,int id);
void atualizarEleitor(Eleitor *lista,int id,const char *novoNome);
void jaVotou(Eleitor *e);
void imprimirEleitores(Eleitor *lista);
void carregarEleitoresFicheiro(Eleitor **lista,const char *nomeFicheiro);
void libertarEleitores(Eleitor **lista);

/* CANDIDATOS */

typedef struct Candidato{
    int id;
    char nome[50];
    int votos;
    struct Candidato *prox;
}Candidato;

int inserirCandidato(Candidato **lista,int id,char nome[]);
int removerCandidato(Candidato **lista,int id);
Candidato *procurarCandidato(Candidato *lista,int id);
void imprimirCandidatos(Candidato *lista);
void carregarCandidatosFicheiro(Candidato **lista,const char *nomeFicheiro);
void libertarCandidatos(Candidato **lista);

/* FILAS */

typedef struct NoFila{
    int idEle;
    char nome[50];
    struct NoFila *prox;
}NoFila;

typedef struct{
    NoFila *ini;
    NoFila *fim;
    int tam;
}Fila;

void iniciarFila(Fila *fila);
int inserirFila(Fila *fila,int id,char nome[]);
int removerFila(Fila *fila);
int desistirFila(Fila *fila,int id);
void imprimirFila(Fila *fila);
int tamanhoFila(Fila *fila);
void libertarFila(Fila *fila);

/* VOTO / PILHA */

typedef struct{
    int dia,mes,ano;
    int hora,minuto;
    int urna;
    int idCandidato;
}Voto;

typedef struct NoPilha{
    Voto voto;
    struct NoPilha *prox;
}NoPilha;

typedef struct{
    NoPilha *topo;
}Pilha;

void criarPilha(Pilha *pilha);
int pilhaVazia(Pilha *pilha);
void empilhar(Pilha *pilha,Voto voto);
Voto desempilhar(Pilha *pilha);
void libertarPilha(Pilha *pilha);

/*  RESULTADOS */

typedef struct{
    int validos;
    int brancos;
    int nulos;
}Resultado;

void iniciarVotacao(Resultado *resultado);
void processarVoto(Resultado *r,Pilha *auditoria,Voto voto,Candidato *listaCandidatos);
void mostrarResultadosParciais(Resultado *resultado);
void mostrarResultadoFinal(Resultado *resultado,Candidato *candidatos);
void gerarFicheiroFinal(Resultado *resultado,Candidato *candidatos,int totalEleitores);

#endif

