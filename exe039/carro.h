#ifndef CARRO_H
#define CARRO_H

typedef struct carro carro;

carro *carCreate(char marca[],char modelo[],int potencia,char cor[],int motor,int light);

void carDelete(carro *c);

int carOnOff(carro *c);

int carLights(carro *c);

void carSound(carro *c);

void carChangeColour(carro *c,char cor[]);//trocar de cor

void carColour(carro *c);//apresentar a cor

void carPower(carro *c); 
 
void carChangePower(carro *c,int power);

void carVScar(carro *c1,carro *c2);

#endif