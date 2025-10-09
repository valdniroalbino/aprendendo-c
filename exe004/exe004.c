/*Crie um programa que leia o preço de um produto e a quantidade comprada, 
e mostre o total a pagar com 10% de desconto se o total for maior que 1000.*/

#include <stdio.h>

int main(){

    int price,quant,total;

    printf("digite o preço do produto: ");
    scanf("%d",&price);

    printf("\ndigite a quantidade: ");
    scanf("%d",&quant);

    total = price*quant;

    if(total>=1000){

        total = total-(total*0.1);

        printf("total a pagar: %d",total);

    }else{
        printf(" o toal a pagar é %d",total);
    }

    return 0;
}