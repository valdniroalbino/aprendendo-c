#include <stdlib.h>
#include <stdio.h>


struct no{
    int valor;
    struct no *prox;
    struct no *ant;
};

typedef struct no LCD;

//cria LCD 

LCD * criarLCD(LCD *l){
    l = NULL;
    return l;
}

//imprimir 

void imprimirLCD(LCD *l){
    if(l){
        if(l->prox == l && l->ant == l){
            printf("%d ",l->valor);
            return;
        }

        LCD *aux = l;
        do{
            printf("%d ",aux->valor);
            aux = aux->prox;
        }while(aux != l);
    }else{
        return;
    }
}

// Inserir no início 

LCD *inserirI(LCD *l,int v){
    LCD *novo = malloc(sizeof(LCD));
    if(novo == NULL){
        puts("erro de alocacao");
        return l;
    }

    novo->valor = v;

    if(l == NULL){
        novo->prox = novo;
        novo->ant  = novo;
        return novo;
    }

    novo->prox = l;
    novo->ant  = l->ant;
    l->ant->prox = novo;
    l->ant = novo;

    return novo;
}


//inserir no fim

LCD *inserirF(LCD *l,int v){
    LCD *novo = malloc(sizeof(LCD));
    if(novo == NULL){
        puts("erro de alocacao");
        return l;
    }

    novo->valor = v;

    if(l == NULL){
        novo->prox = novo;
        novo->ant  = novo;
        return novo;
    }

    novo->prox = l;
    novo->ant = l->ant;
    l->ant->prox = novo;
    l->ant = novo;

    return l;
}

//remover um elemento

LCD *removerElemento(LCD *l,int v){
    LCD *aux = NULL;
    if(l){
        aux = l;
        if(l->prox == l && l->ant == l){
            if(l->valor == v){
                free(l);
                return NULL;
            }else{
                puts("elemento nao encontrado");
                return l;
            }
        }
        do{
            if(aux->valor == v){
                aux->ant->prox = aux->prox;
                aux->prox->ant = aux->ant;

                if(aux == l) l = aux->prox;

                free(aux);
                return l;
            }
            aux = aux->prox;
        }while(aux != l );
        
        puts("elemento nao encontrado");
        return l;
    }else{
        return NULL;
    }
}

//Implemente a função que remove todos os elementos de uma LCD 

int removerLCD(LCD * l){
    LCD *aux, *next;

    if( l == NULL) return NULL;

    aux = l->prox;

    while(aux != l ){
        next = aux->prox;
        free(aux);
        aux = next;
    }

    free(l);

    return NULL;
}

//Dada uma lista circular duplamente ligada, 
//implemente a função que insere um elemento numa posição específica.

LCD *inserirPosicao(LCD *l,int v,int p){
     LCD *novo;
    LCD *aux;
    int i;

    if(p < 1) return l;

    novo = malloc(sizeof(LCD));
    if(novo == NULL){
        puts("erro..");
        return l;
    }

    novo->valor = v;

    if(l == NULL){
        if(p == 1){
            novo->prox = novo;
            novo->ant = novo;
            return novo;
        }else{
            free(novo);
            return l;
        }
    }

    if(p == 1){
        novo->prox = l;
        novo->ant = l->ant;
        l->ant->prox = novo;
        l->ant = novo;
        return novo;
    }

    aux = l;
    for(i = 1; i < p - 1; i++){
        aux = aux->prox;
        if(aux == l) break;
    }

    novo->prox = aux->prox;
    novo->ant = aux;
    aux->prox->ant = novo;
    aux->prox = novo;

    return l;
}

//Implemente uma função para comparar duas listas circulares duplamente ligadas
//Se as listas forem iguais, a função deve retornar 1; caso contrário, deve retornar 0.

int lcdVSlcd(LCD *l1,LCD *l2){
    LCD *aux1,*aux2;

    if(l1 == NULL && l2 == NULL) return 1;

    if(l1 == NULL || l2 == NULL) return 0;

    aux1 = l1;
    aux2 = l2;

    do{
        if(aux1->valor != aux2->valor)
            return 0;

        aux1 = aux1->prox;
        aux2 = aux2->prox;
    }while(aux1 != l1 && aux2 != l2);

    if(aux1 == l1 && aux2 == l2)
        return 1;

    return 0;
}

//remover valores repetidos

LCD *removerRepetidos(LCD *l){
    LCD *aux1,*aux2,*lixo;

    if(l == NULL) return NULL;

    aux1 = l;

    do{
        aux2 = aux1->prox;

        while(aux2 != l){
            if(aux2->valor == aux1->valor){
                lixo = aux2;
                aux2 = aux2->prox;

                lixo->ant->prox = lixo->prox;
                lixo->prox->ant = lixo->ant;

                if(lixo == l)
                    l = lixo->prox;

                free(lixo);
            }else{
                aux2 = aux2->prox;
            }
        }

        aux1 = aux1->prox;
    }while(aux1 != l);

    return l;
}

//colocar duas listas em uma só ordenada.

LCD *juntarOrdenadas(LCD *l1,LCD *l2){
    LCD *res = NULL;
    LCD *a1,*a2;
    int fim1 = 0, fim2 = 0;

    if(l1 == NULL && l2 == NULL) return NULL;
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;

    a1 = l1;
    a2 = l2;

    while(!fim1 || !fim2){
        if(!fim1 && (fim2 || a1->valor <= a2->valor)){
            res = inserirF(res,a1->valor);
            a1 = a1->prox;
            if(a1 == l1) fim1 = 1;
        }else{
            res = inserirF(res,a2->valor);
            a2 = a2->prox;
            if(a2 == l2) fim2 = 1;
        }
    }

    return res;
}




