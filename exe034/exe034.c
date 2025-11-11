/*. Escreva um programa que aloque dinamicamente 
um vector de inteiros com um tamanho inicial de 5. 
O programa deve permitir que o utilizador insira
valores no vector. Caso o vector fique cheio, use realloc para
redimensioná-lo, dobrando seu tamanho. No final imprima os números
lidos e libere a memória.*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n=4;
    int *v = (int *)malloc(n * sizeof(int));

    if(v==NULL)
    {
        puts("erro na alocacao");
    }
    else
    {
    for(int i=0;i<n;i++){
        printf("digite o %d valor: ",i+1);
        scanf("%d",(v+i));
    }

    n *= n;
    v = (int*)realloc(v,n * sizeof(int));

    for(int i=4;i<n;i++){

        printf("digite o %d valor: ",i+1);
        scanf("%d",(v+i));
    }

    for(int i=0;i<n;i++){
        printf("%d - ",*(v+i));
    }

    free(v);
    }   

    return 0;
}
