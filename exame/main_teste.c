#include <stdio.h>
#include <stdlib.h>
#include "eleitor.h"

int main(){
    Eleitor *lista=NULL;

    printf("=== TESTE 1: Insercao manual ===\n");
    inserirEleitor(&lista,criarEleitor(1,"Dino"));
    inserirEleitor(&lista,criarEleitor(2,"Antonio"));
    inserirEleitor(&lista,criarEleitor(3,"Josemar"));

    imprimirEleitores(lista);

    printf("\n=== TESTE 2: Atualizar eleitor ===\n");
    atualizarEleitor(lista,2,"Antonio-Silva");
    imprimirEleitores(lista);

    printf("\n=== TESTE 3: Marcar eleitor como votou ===\n");
    Eleitor *e=procurarEleitor(lista,1);
    jaVotou(e);
    imprimirEleitores(lista);

    printf("\n=== TESTE 4: Carregar eleitores de ficheiro ===\n");
    carregarEleitoresFicheiro(&lista,"eleitores.txt");
    imprimirEleitores(lista);

    printf("\n=== TESTE 5: Libertar memoria ===\n");
    libertarEleitores(&lista);

    if(lista==NULL){
        printf("Lista libertada com sucesso.\n");
    }

    return 0;
}