#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int maiorAreaHistograma(int v[], int n){
    pilha p;
    criarPilha(&p);

    int areaMax = 0;

    for(int i = 0; i <= n; i++){
        int alturaAtual;

        if(i == n)
            alturaAtual = 0; // estou a utlizar isso para parar tds as barras no final.
        else
            alturaAtual = v[i];

        while(!pilhaVazia(&p) && alturaAtual < v[topo(&p)]){
            int indiceRemovido = pop(&p);
            int altura = v[indiceRemovido];

            int largura;
            if(pilhaVazia(&p))
                largura = i;
            else
                largura = i - topo(&p) - 1;

            int area = altura * largura;
            if(area > areaMax)
                areaMax = area;
        }
        push(&p, i);
    }
    freePilha(&p);
    return areaMax;
}

/*nao coloquei tambem essa funcao nos outros arquivos pq essa funcao
é algo exclusivo desse problema de histograma. nao faz parte do TAD pilha */

int main(){
    int n;

    printf("Digite a quantidade de barras: ");
    scanf("%d", &n);

    int v[n];

    printf("Digite a altura das barras:\n");
    for(int i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }

    int resultado = maiorAreaHistograma(v, n);
    printf("Maior area do retangulo: %d\n", resultado);

    return 0;
}