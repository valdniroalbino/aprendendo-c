/*Faça um programa que imprima os N primeiros termos da série α, onde
α = 1/49 + 2²/48 + 2³/47 + … + 2⁵⁰/…*/


#include <stdio.h>
#include <math.h>  

int main() {

    double result,alpha=0;
    int numerador,n,denominador = 50;

    printf("digite o N: ");
    scanf("%d",&n);

    for(int i=1;i<=n;i++){
        numerador = pow(2,i);
        result =(double) numerador / denominador; //esse double serve para converter o result em double
        alpha += result;
        denominador --;
    }

    printf("\nresultado é: %.2f ",alpha);

    return 0;
}


