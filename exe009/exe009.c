/*Uma empresa de aluguer de automóveis precisa cobrar pelos seus serviços.
O aluguer de um automóvel popular custa 25.000 Kz/dia e 45.000 kz/dia
para automóveis de luxo. Além disso, o cliente paga por Km percorrido.
Faça um programa que leia o tipo de carro alugado (popular ou luxo),quantos dias de aluguer e quantos Km foram percorridos. No final mostre o
preço a pagar de acordo com a tabela a seguir:
Popular Até 100km -> 500 kz/km
        Acima de 100km -> 250 kz/km
Luxo Até 200km -> 850 kz/km
     Acima de 200km -> 550 kz/km 
*/

#include <stdio.h>

int main(){
    int opcao,dia,km,total;

    printf("1 - popular;\n2 - luxo");
    printf("\ndigite o respectivo numero: ");
    scanf("%d",&opcao);

    switch(opcao){
        case 1: 
            printf("\nquantos dias?\nR: ");
            scanf("%d",&dia);

            dia *= 25000;

            printf("\nquantos km?\nR: ");
            scanf("%d",&km);

            if(km>100)
                km *= 250;
            else
                km *= 500;

            total = dia + km;

            printf("o toal a pagar é: %d ",total);
            break;
        case 2:
             printf("\nquantos dias?\nR: ");
            scanf("%d",&dia);

            dia *= 45000;

            printf("\nquantos km?\nR: ");
            scanf("%d",&km);

            if(km>200)
                km *= 850;
            else
                km *= 550;

            total = dia + km;

            printf("o toal a pagar é: %d ",total);
            break;
        default: 
            printf("resposta invalida!");
    }

    return 0;
}