#include <stdio.h>
#include <stdlib.h>

struct no{
    int valor;
    struct no *prox;
};

typedef struct no LCS;

//Faça uma função que verifica se uma lista é circular. Devolve 1 ou 0.

int testeLCS(LCS * l){
    LCS *aux =NULL;

    if(l == NULL) return 0;

    aux = l->prox;

    while(aux != l && aux != NULL){
        aux = aux->prox;
    }
    if(aux == l)
        return 1;
    else 
        return 0;
}

//Implemente a função que insere no início de uma lista circular simples.

LCS* inseI(LCS *l,int v){
    LCS * novo = malloc (sizeof(LCS));
    if(novo){
        novo->valor = v;

        if(l == NULL){
            novo->prox = novo; 
            return novo;
        }else{
            LCS * aux = l;
            while(aux->prox != l){
                aux = aux->prox;
            }
            novo->prox = l;
            aux->prox = novo;
            return novo;
        }
    }else{
        puts("erro de alocacao");
        return NULL;
    }
}

//Faça uma função que conta o número de nós de uma lista circular simples.

int contarNos(LCS *l){
    int ctd = 0;
    if(l){
        LCS *aux = l;
        if(l->prox == l){
            return 1;
        }else{
            do{
                ctd++;
                aux = aux->prox;
            }while(aux != l);

            return ctd;
        }
    }else{
        return 0;
    }
}

//Implemente uma função que verifique se a lista circular tem apenas um nó.

int umNo(LCS *l){
    if(l){
        if(l->prox == l) return 1;
        else return 0;
    }else{
        return 0;
    }
}

//verificar as consoantes com recursividade

/*int consoantes(LCS *l){
    int ctd = 0;
    LCS *aux = l;
    if(l){
        while(aux->prox != aux){
            if (isalpha(aux->valor) && !strchr("aeiou", aux->valor)) {
              ctd++;
            }
            aux = aux->prox;
        }
        return ctd;
    }else{
        return 0;
    }
    
}*/

int consoantesAux(LCS *atual, LCS *inicio){
    char c = atual->valor;
    int ctd = 0;

    if(isalpha(c) && !strchr("aeiouAEIOU", c))
        ctd = 1;

    if(atual->prox == inicio)
        return ctd;

    return ctd + consoantesAux(atual->prox, inicio);
}

int consoantes(LCS *l){
    if (l == NULL)
        return 0;

    return consoantesAux(l, l);
}

//Faça uma função que receba uma lista circular e divide a lista ao meio.

void imprimirL(LCS *l){
    LCS *aux = l;
    if(l){
        do{
          printf("%d",aux->valor);
          aux = aux->prox;
        }while(aux != l);
    }
}

void divisao(LCS *l){
    int n = contarNos(l);
    int divi = n/2;
    LCS *l1 = NULL;
    LCS *l2 = NULL; 

    for( int i=0; i < n; i++){
        if(i < divi){
            l1 = inseI(l1,l->valor);
        }else{
            l2 = inseI(l2,l->valor);
        }
        l = l->prox;
    }
    printf("lista 1: \n");
    imprimirL(l1);
    printf("lista 2: \n");
    imprimirL(l2);
}



