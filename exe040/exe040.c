#include <stdio.h>
#include <stdlib.h>

struct no{
    int valor;
    struct no * prox;
};

struct no *l = NULL;

void inserirNoInicio(struct no **l,int x){
    struct no *novo = malloc(sizeof(struct no));
    
    if(novo == NULL){
        puts("erro de alocacao");
        return;
    }
    else{
    novo->valor=x;
    novo->prox=*l;
    *l=novo;
    }
    
}

void inserirNoFinal(struct no **l,int x){
    struct no *novo = malloc(sizeof(struct no));
    if(novo == NULL){
        puts("erro de alocacao");
        return;
    }
    novo->valor = x;
    novo->prox = NULL;

    if(*l==NULL){
        puts("lista vazia");
        return;
    }
    else{
        struct no *aux = *l;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = novo;

    }

}

int procurar(struct no *l,int x){
    if(l == NULL){
        puts("lista vazia");
        return;
    }
    else{
        struct no *aux=l;
        while(aux->prox != NULL){
            
            if(aux->prox == x)
                return 1;

            aux = aux->prox;
        }
        return 0;
    }
}

void removerInicio(struct no **l){
    if(*l == NULL){
        puts("lista vazia");
        return;
    }
    else{
        struct no *lixo = *l; // pq assim pegamos logo a priemiro posicao, logo pegamos o primeiro no
        *l = (*l)->prox;
        free(lixo);
    }
    /*OBS: quando o argumento é um ponteiro de ponteiro, na resolucao devemos utilizar
    *l para conseguirmos mexer no valor original ou na lista original*/
}

void removerValor(struct no **l,int x){
    if(*l == NULL){
        puts("lista vazia");
        return;
    }
    struct no *ant = NULL;

    if((*l)->prox == x){
        struct no *lixo = *l;
        *l = (*l)->prox;
        free(lixo);
        return;
    }

    struct no *ant = *l;
    struct no *atual = (*l)->prox;

    while (atual != NULL) {
        if (atual->valor == x) {
            ant->prox = atual->prox;
            free(atual);
            return; 
        }
        ant = atual;
        atual = atual->prox;
    }

}

void imprimir(struct no *l){

    struct no *aux = l;
    if(aux == NULL){
        puts("lista vazia");
        return;
    }
    else{
        while(aux != NULL){
        printf("%d ->",aux->valor);
        printf("NULL");
        aux = aux -> prox;
        }
    }
}

int tamanho(struct no *l){
    struct no *aux =l;
    if(aux == NULL ){
        puts("lista vazia");
        return;
    }
    int x=0;
    while(aux != NULL){
        x++;
        aux = aux -> prox;
    }
    return x;
}

void inserirPosicao(struct no **l,int x,int pos){

    struct no *novo = malloc(sizeof(struct no));
    if(novo == NULL ){
        puts("erro na alocacao!");
        return;
    }
    novo->valor = x;
    novo->prox = NULL;

    if (pos <= 0 || *l == NULL) {
        novo->prox = *l;
        *l = novo;
        return;
    }

    struct no *ant = *l;
    int i = 0;
    while (i < pos - 1 && ant->prox != NULL) {
        ant = ant->prox;
        i++;
    }

    novo->prox = ant->prox;
    ant->prox = novo;

}

void removerFinal(struct no** l){
    struct no *aux = *l;
    if(aux ==NULL){
        puts("lista vazia");
        return;
    }
    struct no *aux = *l;
    
    if (aux->prox == NULL) {
        free(aux);
        *l = NULL;
        return;
    }
    struct no *ant = NULL;
    while (aux->prox != NULL) {    
        ant = aux;
        aux = aux->prox;
    }

    ant->prox = NULL;
    free(aux);
}

void limparLista(struct no **l) {
    struct no *aux = *l;    
    struct no *lixo;        

    while (aux != NULL) {
        lixo = aux;         
        aux = aux->prox;    
        free(lixo);         
    }

    *l = NULL;             
}

void numeroDEnos(struct no *l);