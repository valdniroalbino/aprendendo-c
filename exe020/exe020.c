/*. Seja a seguinte série: 1, 4, 4, 2, 5, 5, 3, 6, 6, 4, 7, 7, ... Elabore um
programa que seja capaz de gerar os N termos desta série, sendo que N
deve ser informado pelo utilizador.*/

#include <stdio.h>

int main(){
    int cont = 0, numeros, i=1;

    printf("digite o valor de N: ");
    scanf("%d",&numeros);

    while (cont < numeros ){
        printf("%d ",i);

        if(cont < numeros){
            printf("%d ",i+3);
            cont++;
        }
        if(cont < numeros){
            printf("%d ",i+3);
            cont++;
        }
        i++;
    }
    return 0;
}
