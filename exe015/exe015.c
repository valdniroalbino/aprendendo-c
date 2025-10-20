/*Diz-se que um número inteiro N é um quadrado perfeito se existirem M
números ímpares consecutivos a partir de 1 cuja soma é igual a N. Ex: 16 =
1+3+5+7 (soma dos 4 ímpares a partir de 1). Faça um programa que
verifique se um inteiro positivo inserido pelo utilizador é um quadrado
perfeito ou não.*/

#include <stdio.h>

int main(){
    int m,soma=0;
    int teste = 0;

    printf("digite o M: ");
    scanf("%d",&m);

    for(int i=1 ; i <= m && teste == 0; i+=2){
        
        soma +=i;

        printf("%d -",i );

        if(soma == m)
            teste = 1;
    }
    
    printf(soma == m ? "quadrado perfeito" : "nao e perfeito") ;

    return 0; 
}