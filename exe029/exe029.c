/*Crie uma função chamada contaSinais que 
receba um vetor de inteiros e seu tamanho, 
e através de ponteiros passados como parâmetros, armazene:
	•	quantos números são positivos,
	•	quantos são negativos,
	•	e quantos são zeros.*/

    #include <stdio.h>

    void posiEnega(int *v,int tamanho){

        int positive = 0, negative = 0, zero = 0;

        for(int i = 0; i < tamanho; i++){
            if(*(v+i) > 0)
                positive++;
            else if(*(v+i) < 0)
                negative++;
            else
                zero++;
        }

        printf("positivos: %d\nnegativos: %d\nzero: %d",positive,negative,zero);
    }

    int main(){
        int n;

        printf("digite o tamanho do vetor: ");
        scanf("%d",&n);

        int vetor[n];

        for(int i = 0; i < n; i++){
            printf("digite o %d numero: ",i+1);
            scanf("%d",&vetor[i]);
        }

        posiEnega(vetor,n);

        return 0;
    }

