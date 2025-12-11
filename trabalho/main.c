#include <stdio.h>
#include "sorteio.h"

//Grupo 2
//António Nangikola - 20240694
//Josemar da Silva - 20240610
//Valdniro Albino - 20241757

int main(){
    LCD l;
    criarLista(&l);

    int n_aleatorio;
    int x_saltos;
    int candidatos;
    char nome[50];
    int i;

    printf("Quantos candidatos? ");
    if(scanf("%d", &candidatos) != 1 || candidatos <= 0){
        printf("valor invalido.Vamos usar 10!\n");
        candidatos = 10;
        while(getchar() != '\n'); /* limpar buffer */
    }

    for(i = 0; i < candidatos; ++i){
        printf("Nome %d: ", i + 1);
        if(scanf("%49s", nome) != 1){

            snprintf(nome, sizeof(nome), "Candidato_%d", i + 1);
            while (getchar() != '\n');
        }
        addCandidato(&l, nome);
    }

    printf("\nLista atual:\n");
    imprimirLista(&l);

    printf("Insere um número para escolher a posição inicial (1..%d): ", candidatos);
    if(scanf("%d", &n_aleatorio) != 1){
        printf("Entrada inválida. Usando 1 como padrão.\n");
        n_aleatorio = 1;
        while (getchar() != '\n');
    }

    printf("Insere o passo (x_saltos >= 1): ");
    if(scanf("%d", &x_saltos) != 1 || x_saltos <= 0){
        printf("Entrada inválida. Usando passo = 1.\n");
        x_saltos = 1;
        while (getchar() != '\n');
    }

    if(n_aleatorio > candidatos || n_aleatorio <= 0){
        n_aleatorio = 1;
    }

    int inicio = n_aleatorio - 1;

    printf("\nInício = %d, passo = %d\n\n", inicio, x_saltos);

    sortear(&l, x_saltos, inicio);

    free(&l);

    return 0;
}