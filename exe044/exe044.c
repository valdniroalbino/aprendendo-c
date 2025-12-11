#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *prox;
}no;
typedef no *lista;

//libertar todos os nós da lista, um por um, sem perder o controlo do head.

void freeLista(lista *l){
    no *aux;
    while(*l != NULL){
        aux = *l;
        *l = aux->prox;
        free(aux);
    }
}

/*Escreve uma função que imprima os valores de uma lista simplesmente ligada na ordem inversa.
A função NÃO deve alterar a estrutura da lista.
Deves usar recursão.
*/

void inverso(lista l){
    if(l == NULL) return;
    inverso(l->prox);
    printf("%d - ",l->valor);
}

/*Implemente uma função recursiva que conte o número de nós de uma lista simplesmente ligada.
A função deve retornar um inteiro.*/

int numeroNos(lista l){
    if(l == NULL) return 0;
    return 1 + numeroNos(l->prox);
}


/*Implemente uma função retiraPrefixo que recebe uma lista simplesmente 
ligada e um inteiro n, e remove os n primeiros nós da lista (libertando a 
memória corretamente). A função deve atualizar o head da lista.*/

void retiraPrefixo(lista *l,int n){
    no *aux;
    
    if(n <= 0 || *l == NULL )
        return;

    while(*l != NULL && n > 0){
        aux = *l;
        *l = aux->prox;
        free(aux);
        n--;
    }
}
/*Implemente uma função que recebe uma lista 
simplesmente ligada, um valor chave e um valor novoValor.
A função deve inserir um novo nó contendo 
novoValor imediatamente depois do nó cujo 
valor seja igual à chave.
Se a chave não existir na lista, o novo nó 
deve ser inserido no fim da lista.*/

void idduv(lista *l,int chave, int n){
    no *novo = malloc (sizeof(no));
    if(novo == NULL) return ;

    novo->valor = n;
    novo->prox = NULL;

    no *aux = *l;
    if(aux == NULL ){
        *l = novo;
        return;
    }else{
        while(aux->prox != NULL){
            if(aux->valor == chave){
                novo->prox = aux->prox;
                aux->prox = novo;
                return;
            }
            aux = aux->prox;
        }
        if(aux->valor == chave){
            novo->prox = aux->prox;
            aux->prox = novo;
        }else{
            aux->prox = novo;
        }
    }
}

/* */