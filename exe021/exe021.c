/*Elabore um programa que leia 9 números inteiros aleatórios, calcule e
mostre a quantidade de números perfeitos. Um número N é perfeito, se N
for igual a soma dos seus divisores próprios.*/

#include <stdio.h>

int main(){
    int perfeito = 0, numero;

    for(int i=0; i<=3; i++){
        printf("\ndigite o %d numero: ",i+1);
        scanf("%d",&numero);

        int contador=1, divisor = 0;

        while(contador <= numero){
            if(numero % contador == 0 ){
                divisor++;
            }
            contador++;
        }
        if(divisor == 2)
            perfeito++;
    }
    if(perfeito == 0)
        printf("sem numeros primos");
    else if(perfeito == 1)
        printf("1 numero perfeito");
    else
        printf("%d numeros pares",perfeito);
        
    return 0;
}