/*Implemente uma função que retorna o número de vezes que um
determinado número aparece num vector. A assinatura da função é: int
contaRepeticoes(int *v, int n); sabendo que a função recebe o vector e o seu
tamanho.*/
#include <stdio.h>

int contaRepeticoes(int *v, int tamanho, int valor){

    int contador = 0;

    for(int i = 0; i <= tamanho; i++){
        if(v[i] == valor)
            contador++;
    }
    
    return contador;
}

int main(){
    int tamanho,valor;

    printf("digite o tamanho do vetor: ");
    scanf("%d",&tamanho);

    int vetor[tamanho];

    for(int i = 0; i <= tamanho ; i++ ){
        printf("digite %d numero: ",i+1);
        scanf("%d",&vetor[i]);
    }

    printf("valor a se procurar no vetor: ");
    scanf("%d",&valor);

    contaRepeticoes(vetor,tamanho,valor);

    if(contaRepeticoes(vetor,tamanho,valor) == 0 || contaRepeticoes(vetor,tamanho,valor) > 1)
        printf("o valor aparece %d vezes.",contaRepeticoes(vetor,tamanho,valor));
    if( contaRepeticoes(vetor,tamanho,valor) == 1)
        printf("o valor aparece %d vez",contaRepeticoes(vetor,tamanho,valor));
    
    return 0;

}
