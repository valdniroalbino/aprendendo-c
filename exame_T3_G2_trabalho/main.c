#include "sistema.h"

/*
    António Nangikola - 20240694
    Josemar da Silva - 20240610
    Valdniro Albino - 20241757
*/

void menuEleitores(Eleitor **lista){
    int opcao;
    do{
        printf("\n========== GESTAO DE ELEITORES ==========\n");
        printf("1 - Registar eleitor\n");
        printf("2 - Atualizar eleitor\n");
        printf("3 - Listar eleitores\n");
        printf("4 - Carregar eleitores de ficheiro\n");
        printf("0 - Voltar\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        if(opcao == 1){
            int id;
            char nome[100];

            printf("ID do eleitor: ");
            scanf("%d", &id);
            printf("Nome do eleitor: ");
            scanf("%99s", nome);

            if(idExiste(*lista, id)){
                printf("Eleitor ja existe.\n");
            }else{
                inserirEleitor(lista, criarEleitor(id, nome));
                printf("Eleitor registado com sucesso.\n");
            }
        }
        else if(opcao == 2){
            int id;
            char nome[100];

            printf("ID do eleitor: ");
            scanf("%d", &id);
            printf("Novo nome: ");
            scanf("%99s", nome);

            atualizarEleitor(*lista, id, nome);
            printf("Eleitor atualizado.\n");
        }
        else if(opcao == 3){
            imprimirEleitores(*lista);
        }
        else if(opcao == 4){
            char ficheiro[100];

            printf("Nome do ficheiro: ");
            scanf("%99s", ficheiro);

            carregarEleitoresFicheiro(lista, ficheiro);
        }

    }while(opcao != 0);
}

void menuCandidatos(Candidato **lista){
    int opcao;
    do{
        printf("\n========== GESTAO DE CANDIDATOS ==========\n");
        printf("1 - Registar candidato\n");
        printf("2 - Remover candidato\n");
        printf("3 - Listar candidatos\n");
        printf("4 - Carregar candidatos de ficheiro\n");
        printf("0 - Voltar\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        if(opcao == 1){
            int id;
            char nome[50];

            printf("ID do candidato: ");
            scanf("%d", &id);
            printf("Nome do candidato: ");
            scanf("%49s", nome);

            inserirCandidato(lista, id, nome);
        }
        else if(opcao == 2){
            int id;

            printf("ID do candidato: ");
            scanf("%d", &id);

            removerCandidato(lista, id);
        }
        else if(opcao == 3){
            imprimirCandidatos(*lista);
        }
        else if(opcao == 4){
            char ficheiro[100];

            printf("Nome do ficheiro: ");
            scanf("%99s", ficheiro);

            carregarCandidatosFicheiro(lista, ficheiro);
        }

    }while(opcao != 0);
}

int main(){
    Eleitor *listaEleitores = NULL;
    Candidato *listaCandidatos = NULL;
    Fila filas[NUM_URNAS];
    Pilha auditoria;
    Resultado resultado;

    for(int i = 0; i < NUM_URNAS; i++){
        iniciarFila(&filas[i]);
    }

    criarPilha(&auditoria);
    iniciarVotacao(&resultado);

    int opcao;

    do{
        printf("\n=========================================\n");
        printf("        SISTEMA DE VOTACAO ELETRONICA     \n");
        printf("=========================================\n");
        printf("1 - Gerir eleitores\n");
        printf("2 - Gerir candidatos\n");
        printf("3 - Inicializar votacao\n");
        printf("4 - Votar\n");
        printf("5 - Resultados parciais\n");
        printf("6 - Resultado final\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        if(opcao == 1){
            menuEleitores(&listaEleitores);
        }
        else if(opcao == 2){
            menuCandidatos(&listaCandidatos);
        }
        else if(opcao == 3){
            Eleitor *aux = listaEleitores;
            int indice = 0;

            for(int i = 0; i < NUM_URNAS; i++){
                iniciarFila(&filas[i]);
            }

            while(aux){
                if(!aux->votou){
                    inserirFila(&filas[indice % NUM_URNAS], aux->id, aux->nome);
                    indice++;
                }
                aux = aux->prox;
            }

            printf("Votacao inicializada com sucesso.\n");
        }
        else if(opcao == 4){
            int urna, idCandidato;

            printf("Urna (0 a %d): ", NUM_URNAS - 1);
            scanf("%d", &urna);

            if(urna < 0 || urna >= NUM_URNAS){
                printf("Urna invalida.\n");
            }
            else if(!filas[urna].ini){
                printf("Fila vazia.\n");
            }
            else{
                printf("ID do candidato (0 branco / -1 nulo): ");
                scanf("%d", &idCandidato);

                Voto voto = {1, 1, 2026, 10, 0, urna, idCandidato};
                processarVoto(&resultado, &auditoria, voto, listaCandidatos);

                if(idCandidato > 0){
                    Candidato *c = procurarCandidato(listaCandidatos, idCandidato);
                    if(c) c->votos++;
                }

                Eleitor *e = procurarEleitor(listaEleitores, filas[urna].ini->idEle);
                jaVotou(e);
                removerFila(&filas[urna]);

                printf("Voto registado com sucesso.\n");
            }
        }
        else if(opcao == 5){
            mostrarResultadosParciais(&resultado);
        }
        else if(opcao == 6){
            mostrarResultadoFinal(&resultado, listaCandidatos);

            int total = 0;
            Eleitor *aux = listaEleitores;

            while(aux){
                total++;
                aux = aux->prox;
            }

            gerarFicheiroFinal(&resultado, listaCandidatos, total);
            printf("Resultado final gravado em ficheiro.\n");
        }

    }while(opcao != 0);

    libertarEleitores(&listaEleitores);
    libertarCandidatos(&listaCandidatos);

    for(int i = 0; i < NUM_URNAS; i++){
        libertarFila(&filas[i]);
    }

    libertarPilha(&auditoria);

    printf("A sair do sistema...\n");
    return 0;
}