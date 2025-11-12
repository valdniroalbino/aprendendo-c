#include "carro.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct carro{
    char marca[50];
    char modelo[50];
    int potencia;
    char cor[20];
    int motor;
    int light;
}carro;

carro *carCreate(char marca[],char modelo[],int potencia,char cor[],int motor,int light){
    carro *novo = (carro *)malloc(sizeof(carro));
    if(novo == NULL){
        puts("Erro na alocacao!");
        return NULL;
    }

    strcpy(novo->marca,marca);
    strcpy(novo->modelo,modelo);
    novo->potencia=potencia;
    strcpy(novo->cor,cor);
    novo->motor=motor;
    novo->light = light;

    return novo;

}

void carDelete(carro *c){
    free(c);
}

int carOnOff(carro *c){
    if(c->motor==0)
        return 1;
    if(c->motor==1)
        return 0;
}

int carLights(carro *c){
    if(c->light==0)
        return 1;
    if(c->light==1)
        return 0;

}

void carSound(carro *c){
    puts("PIMMMMMMMMMMM!!!");
}

void carChangeColour(carro *c,char cor[]){
    strcpy(cor,c->cor);
    printf("cor trocada com sucesso!\n");
}//trocar de cor

void carColour(carro *c){
    printf("a cor do carro é: %d\n",c->cor);
}//apresentar a cor

void carPower(carro *c){
    printf("a potencia do carro é: %d\n",c->potencia);
}
 
void carChangePower(carro *c,int power){
    c->potencia=power;
    printf("potencia do carro trocada com sucesso!\n");
}

void carVScar(carro *c1,carro *c2){
    if(c1->potencia > c2->potencia){
        puts("o primeiro carro do parametro é mais potente!\n");
    }else{
        puts("o segundo carro do parametro é mais potente!\n");
    }

}



