/*crie um TAD jogadr(futebol)*/

#include <stdio.h>
#include "jogador.h"
#include <string.h>
#include <stdlib.h>

int main(){
    Jogador *j1, *j2;
    int number,game,gol,assist;
    char name[50];
    int opcao;
    int add_golos,add_assist,add_game;

    puts("seja bem-vindo!");
    puts("=======PRIMEIRO JOGADOR=======\n");
    printf("nome: ");
    fgets(name,sizeof(name),stdin);
    printf("numero: ");
    scanf("%d",&number);
    printf("game: ");
    scanf("%d",&game);
    printf("assist: ");
    scanf("%d",&assist);
    printf("gol: ");
    scanf("%d",&gol);
    getchar();

    j1 = jogador_cria(name,number,game,gol,assist); 

    puts("=======SEGUNDO JOGADOR=======\n");
    printf("nome: ");
    fgets(name,sizeof(name),stdin);
    printf("numero: ");
    scanf("%d",&number);
    printf("game: ");
    scanf("%d",&game);
    printf("assist: ");
    scanf("%d",&assist);
    printf("gol: ");
    scanf("%d",&gol);
    getchar();

    j2 = jogador_cria(name,number,game,gol,assist);

    printf("1 - jogador 1;\n2 - jogador 2\n3 - comparar jogadores\n");
    printf("escolhe a opcao que deseja: ");
    scanf("%d",&opcao);

    if(opcao == 1){
        printf("escolha: \n");
        printf("1 - ver numero de golos\n");
        printf("2 - atualizar golos\n");
        printf("3 - ver numero de assistencias\n");
        printf("4 - atualizar assist\n");
        printf("5 - ver numero de jogos\n");
        printf("6 - atualizar jogos\n");
        printf("7 - ver se é craque\n");
        printf("8 - imprimir dados\n");
        printf("9 - apagar jogador\n");

        switch(opcao){
            case 1:
                jogadorGetGol(j1);
                break;
            case 2:
                printf("golos a adicionar: ");
                scanf("%d",&add_golos);
                jogador_gols(j1,add_golos);
                break;
            case 3:
                jogadorGetAssist(j1);
                break;
            case 4:
                printf("assistencias a adicionar: ");
                scanf("%d",&add_assist);
                jogador_assit(j1,add_assist);
                break;
            case 5:
                jogadorGetGol(j1);
                break;
            case 6:
                printf("jogos a adicionar: ");
                scanf("%d",&add_game);
                jogador_game(j1,add_game);
                break;
            case 7:
                ehCraque(j1);
                break;
            case 8:
                jogador_print(j1);
                break;
            case 9:
                jogador_free(j1);
                break;
            default:
                printf("invalido!");

        }

    }
    if(opcao == 2){
        printf("escolha: \n");
        printf("1 - ver numero de golos\n");
        printf("2 - atualizar golos\n");
        printf("3 - ver numero de assistencias\n");
        printf("4 - atualizar assist\n");
        printf("5 - ver numero de jogos\n");
        printf("6 - atualizar jogos\n");
        printf("7 - ver se é craque\n");
        printf("8 - imprimir dados\n");
        printf("9 - apagar jogador\n");

        switch(opcao){
            case 1:
                jogadorGetGol(j2);
                break;
            case 2:
                printf("golos a adicionar: ");
                scanf("%d",&add_golos);
                jogador_gols(j2,add_golos);
                break;
            case 3:
                jogadorGetAssist(j2);
                break;
            case 4:
                printf("assistencias a adicionar: ");
                scanf("%d",&add_assist);
                jogador_assit(j2,add_assist);
                break;
            case 5:
                jogadorGetGol(j2);
                break;
            case 6:
                printf("jogos a adicionar: ");
                scanf("%d",&add_game);
                jogador_game(j2,add_game);
                break;
            case 7:
                ehCraque(j2);
                break;
            case 8:
                jogador_print(j2);
                break;
            case 9:
                jogador_free(j2);
                break;
            default:
                printf("invalido!");

        }
    }
    if(opcao == 3)
        jogador_compare(j1,j2);

    return 0;
}