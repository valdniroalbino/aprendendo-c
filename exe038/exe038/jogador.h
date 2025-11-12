#ifndef JOGADOR_H
#define JOGADOR_H

typedef struct Jogador Jogador;

//funções do meu TAD 

Jogador *jogador_cria(char name[],int number,int game,int gol, int assist);

void jogador_free(Jogador *j);

void jogador_gols(Jogador *j,int gol);

void jogador_assit(Jogador *j,int assist);

void jogador_game(Jogador *j,int game);

void jogador_compare(Jogador *j1,Jogador *j2);

int jogadorGetAssist(Jogador *j);

int jogadorGetGol(Jogador *j);

int jogadorGetGame(Jogador *j);

int ehCraque(Jogador *j);

void jogador_print(Jogador *j);

#endif