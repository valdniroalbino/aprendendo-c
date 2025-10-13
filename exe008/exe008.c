/*Faça um programa usando a instrução switch, que leia um valor
representando um mês e indique quantos dias tem o mês lido. Para
simplificar vamos assumir que Fevereiro tem sempre 28 dias.*/

#include <stdio.h>

int main(){
    int opcao;

    printf("1-janeiro\n2-fevereiro\n3-março\n4-abril\n5-maio\n6-junho\n7-julho\n8-agosto\n9-setembro\n10-outubro\n11-novembro\n12-dezembro");
    printf("\ndigite um numero para saber quantos dias tem nesse mes: ");
    scanf("%d",&opcao);

    switch(opcao){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            printf("o mês solicitado tem 31 dias!");
            break;
        case 2:
            printf("o mês solicitado tem 28 dias!");
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            printf("o mês solicitado tem 30 dias!");
            break;
        default:
            printf("invalido");
        
        return 0;
    }
}