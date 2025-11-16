#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "carro.h"

void limparBuffer(){
    int c;
    while((c = getchar()) != '\n' && c != -1);
}

struct carro lerCarro(){
    struct carro car;

    printf("Marca: ");
    scanf("%s", car.marca);
    limparBuffer();

    printf("Matricula: ");
    scanf("%s", car.matricula);
    limparBuffer();

    printf("Proprietario: ");
    scanf("%s", car.proprietario);
    limparBuffer();

    printf("VIN: ");
    scanf("%s", car.vin);
    limparBuffer();

    return car;
}

int main(){
    struct no *l1 = NULL; 
    struct no *l2 = NULL;
    struct no **ativa = &l1; // começa na lista 1

    int op;
    char vin[18];
    int n;

    criarLista(&l1);
    criarLista(&l2);

    do{
        printf("\n===== MENU =====\n");
        printf("Lista ativa: %s\n", (ativa == &l1 ? "Lista 1" : "Lista 2"));
        printf("1 - Inserir no inicio\n");
        printf("2 - Inserir no fim\n");
        printf("3 - Imprimir lista\n");
        printf("4 - Remover por VIN\n");
        printf("5 - Remover N primeiros\n");
        printf("6 - Comparar listas\n");
        printf("7 - Alternar lista\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &op);
        limparBuffer();

        if(op == 1){
            struct carro car = lerCarro();
            addInicio(ativa, car);
        }
        else if(op == 2){
            struct carro car = lerCarro();
            addFim(ativa, car);
        }
        else if(op == 3){
            imprimirLista(ativa);
        }
        else if(op == 4){
            printf("Digite o VIN: ");
            scanf("%s", vin);
            limparBuffer();
            tirarPorVin(ativa, vin);
        }
        else if(op == 5){
            printf("Quantos deseja remover? ");
            scanf("%d", &n);
            limparBuffer();
            tirarNPrimeiros(ativa, n);
        }
        else if(op == 6){
            int iguais = listasIguais(&l1, &l2);
            if(iguais)
                printf("As duas listas sao IGUAIS!\n");
            else
                printf("As duas listas sao DIFERENTES!\n");
        }
        else if(op == 7){
            if(ativa == &l1){
                ativa = &l2;
                printf("Agora a lista ativa e a Lista 2\n");
            } else {
                ativa = &l1;
                printf("Agora a lista ativa e a Lista 1\n");
            }
        }
        else if(op == 0){
            printf("A sair...\n");
        }
        else{
            printf("Opcao invalida!\n");
        }

    } while(op != 0);

    return 0;
}