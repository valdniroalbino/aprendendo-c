/*Escreva um programa para aprovar ou não o empréstimo bancário para a
compra de uma casa. O programa vai perguntar o valor da casa, o salário
do comprador e em quantos anos ele vai pagar. Calcule o valor da
prestação mensal, sabendo que ela não pode exceder 30% do salário ou
então o empréstimo será negado.*/

#include <stdio.h>

int main(){
    
    int valor_da_casa,salario,anos,pagar,salario30;

    printf("digite o valor da casa: ");
    scanf("%d",&valor_da_casa);

    printf("digite o salario: ");
    scanf("%d",&salario);

    printf("digite em quantos anos irá pagar: ");
    scanf("%d",&anos);

    anos = anos * 12;
    salario30 = salario * 0.3;
    pagar = valor_da_casa / anos;

    if(pagar>=salario30)
        printf("emprestimo negado");
    else
        printf("emprestimo autorizado");

    return 0;
}

