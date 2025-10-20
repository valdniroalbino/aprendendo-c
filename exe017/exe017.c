#include <stdio.h>
#define SIZE 100

int main(){
    int sequencia[SIZE];
    int numero;
    int i=0;

    while(numero!=-1){
        printf("\nDigite um numero: ");
        scanf("%d",&numero);
        if(numero == -1)
            break;
        else
            sequencia[i]=numero;
        i++;
    }


    for(int j=0; j<i ; j++){
        printf("%d",sequencia[j]);
    }
    
    return 0;
}