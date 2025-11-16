#ifndef CARRO_H
#define CARRO_H

struct carro {
    char marca[30];
    char matricula[15];
    char proprietario[50];
    char vin[18]; 
};


struct no {
    struct carro car;
    struct no *prox;
};

void criarLista(struct no **l);
void addInicio(struct no **l, struct carro car);
void addFim(struct no **l, struct carro car);
void imprimirLista(struct no **l);
void tirarPorVin(struct no **l, char vin[]);
void tirarNPrimeiros(struct no **l, int n);
void liberarLista(struct no **l);
int listasIguais(struct no **l1, struct no **l2);


#endif 