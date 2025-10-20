/*Um determinado material radioactivo perde metade de sua massa a cada
110 segundos. Faça um programa que leia a massa inicial em gramas e
determine o tempo necessário para que essa massa se torne menor que 0,8
g.*/

#include <stdio.h>

int main(){

    int i=1;
    int massa,massa_inicial;
    int segundos = 110;

    printf("digite a massa inicial: ");
    scanf("%d",&massa);

    massa_inicial = massa;

    while(massa>0.8){
        massa /= 2;
        i++;
    }

    segundos = segundos * i;

    printf("\né necessario %d segundos para que a massa de %dg se torne menor que 0.8 ",segundos,massa_inicial);

    return 0;
}