#include "jogador.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "jogador.h"

typedef struct Jogador {
    char name[50];
    int number;
    int game;
    int gol;
    int assist;
}Jogador;

Jogador *jogador_cria(char name[],int number,int game,int gol, int assist){
    Jogador *novo = (Jogador *)malloc(sizeof(Jogador));
    if(novo == NULL){
        printf("Erro de alocacao de memoria!");
        return NULL;
    }

    strcpy(novo->name,name);
    novo->number = number;
    novo->game = game;
    novo->gol = gol;
    novo->assist = assist;

    return novo;
}

void jogador_free(Jogador *j){
    free(j);
}

void jogador_gols(Jogador *j,int gol){
    j->gol += gol;
}

void jogador_assit(Jogador *j,int assist){
    j->assist += assist;
}

void jogador_game(Jogador *j,int game){
    j->game += game;
}

int jogadorGetAssist(Jogador *j){
    return j->assist;
}

int jogadorGetGol(Jogador *j){
    return j->gol;
}

int jogadorGetGame(Jogador *j){
    return j->game;
}

void jogador_compare(Jogador *j1,Jogador *j2){
    int aux1=0,aux2=0;
    if(jogadorGetGame(j1) > jogadorGetGame(j2))
        aux1++;
    else
        aux2++;

    if(jogadorGetGol(j1) > jogadorGetGol(j2))
        aux1++;
    else
        aux2++;
    
    if(jogadorGetAssist(j1) > jogadorGetAssist(j2))
        aux1++;
    else
        aux2++;

    if(aux1 > aux2)
        printf("jogador um é o melhor!");
    else if(aux1 == aux2)
        printf(" jogador estao taco-a-taco!");
    else
        printf("jogador dois é o melhor!");
}

int ehCraque(Jogador *j){
    float media_golo = (float) j->gol / j->game;
    float media_assist = (float) j->assist / j->game;

    if(j->game >=100 && media_golo >=0.5 && media_assist >=0.3)
        return 1;
    else    
        return 0;
}

void jogador_print(Jogador *j){
    printf("nome: %s\nnumero: %d\njogos: %d\ngolos: %d\nassistencias: %d\n",j->name,j->number,j->game,j->gol,j->assist);
}