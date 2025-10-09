//pedir ao usuario dois numeros e apresentar a soma, multiplicação e a subtração.

#include <stdio.h>

int main(){

    int a,b,soma,sub,mult;

    printf("digite o primeiro numero: \n");
    scanf("%d",&a);
    printf("digite o segundo numero: \n");
    scanf("%d",&b);

    soma = a+b;
    sub = a-b;
    mult = a*b;

    printf("a soma é %d\na subtracao é %d\na multiplicacao é %d\n",soma,sub,mult);

    return 0;
}