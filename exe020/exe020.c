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