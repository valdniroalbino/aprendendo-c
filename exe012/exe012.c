/*Escreva um programa que leia quatro valores inteiros. Assumindo que os
números são diferentes, mostre-os em ordem decrescente.*/

#include <stdio.h>

void insertionSort(int aux[],int n){
    for(int i=1; i<n ; i++){
        int chave = aux[i];
        int j = i - 1;

        while( j >= 0 && aux[j] < chave){
            aux[j+1]= aux[j];
            j--;
        }

        aux[j+1]= chave;
    }
}

int main(){
    int numeros[4];
    int n = sizeof(numeros) /sizeof(numeros[0]);

    for(int j=0;j<4;j++){
        printf("digite um numero: \n");
        scanf("%d",&numeros[j]);
    }

    insertionSort(numeros,n);

    printf("ordem: ");
    for(int i=0; i<n; i++){
        printf("%d",numeros[i]);
    }


    return 0;
}