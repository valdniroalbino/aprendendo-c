#include <stdlib.h>
#include <stdio.h>

typedef struct no{
    int valor;
    struct no *prox;
}Lista;

typedef struct {
    Lista *top;
}Pilha;

//criar pilha 

Pilha *criarPilha(){
    Pilha *p=malloc(sizeof(Pilha));
    if(p == NULL){
        printf("ERRO de alocacao\n");
        return NULL;
    }
    p->top = NULL; 
    return p;
}

//add na Pilha (push)

Pilha *push(Pilha *p,int v){
    if(p){
        Lista *novo = malloc(sizeof(Lista));
        if(novo){
            novo->valor = v;
            novo->prox = p->top;
            p->top = novo;

            return p;
        }else{
            puts("erro de alocacao.");
            return p;
        }
    }else{
        puts("lista nao foi criada.");
        return NULL;
    }
}

//remover da pilha (pop)

int pop(Pilha *p){
    if(p){
        if(p->top == NULL){
            return 0;
        }else{
            Lista *aux = p->top;
            int i = aux->valor;
            p->top = aux->prox;
            free(aux);
            return i;
        }
    }else{
        return 0;
    }
}

//valor top

int top(Pilha *p){
    if(p){
        if(p->top == NULL){
            return 0;
        }else{
            return p->top->valor;
        }
    }else{
        return 0;
    }
}

//verificar pilha vazia 

int pilhaVazia(Pilha *p){
    if(p){
        if(p->top == NULL ) return 1;

        return 0;
    }else{
        return 0;
    }
}

//destruir pilha

int destruirPilha(Pilha *p){
    if(p){
       Lista *aux;
       while ( aux != NULL){
            aux = p->top;
            p->top = aux->prox;
            free(aux);
       }
        return 1;
    }else{
        return 0;
    }
}


//caso 7 da lista 

int verificarParenteses(char *expr){
    Pilha *p = criarPilha();
    int i;

    if(p == NULL) return 0;

    for(i = 0; expr[i] != '\0'; i++){

        if(expr[i] == '('){
            push(p,'(');
        }
        else if(expr[i] == ')'){
            if(pilhaVazia(p)){
                destruirPilha(p);
                return 0;
            }
            pop(p);
        }
    }

    if(pilhaVazia(p)){
        destruirPilha(p);
        return 1;
    }

    destruirPilha(p);
    return 0;
}

//exercio 8

int xCy(char *expre){
    Pilha *p =criarPilha();
    int i = 0;
    int encontrouC = 0;

    if(p == NULL) return 0;

    while(expre[i] != '\0'){
        if(expre[i] != 'C' && !encontrouC){
            push(p,expre[i]);
        }
        else if(expre[i] == 'C'){
            encontrouC = 1;
        }
        else{
            if(pilhaVazia(p)){
                destruirPilha(p);
                return 0;
            }
            if(pop(p) != expre[i]){
                destruirPilha(p);
                return 0;
            }
        }
        i++;
    }
    if(!pilhaVazia(p)){
        destruirPilha(p);
        return 0;
    }
    destruirPilha(p);
    return 1;
}

//maior e menor da pilha

void menorMaior(Pilha *p){
    Pilha *aux = criarPilha();
    int v;
    
    if(p == NULL || pilhaVazia(p)) return 0;

    v = pop(p);
    int maior = v;
    int menor = v;
    push(aux,v);

    while(!PilhaVazia(p)){
        v = pop(p);

        if(v > maior) maior = v;
        if(v < maior) menor = v;

        push(aux,v);
    }

    while(!pilhaVazia(aux)){
        push(p,pop(aux));
    }

    destruirPilha(aux); 

    printf("maior numero da pilha: %d\n",maior);
    printf("menor numero da pilha: %d",menor);
}

int destruirPilha(Pilha *p){
    if(p){
       Lista *aux;
       while ( aux != NULL){
            aux = p->top;
            p->top = aux->prox;
            free(aux);
       }
        return 1;
    }else{
        return 0;
    }
}
