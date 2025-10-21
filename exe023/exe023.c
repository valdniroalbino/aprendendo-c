/*Faça uma função que verifique a validade de uma hora. A função deve
receber dois valores correspondentes a hora (0-23) e aos minutos(0-59)
e retornar 1 para verdadeiro e 0 para falso. Por exemplo: validaHora (3,
45) return 1; validaHora(40, 12) return 0.*/

#include <stdio.h>

int validaHora(int hora, int minuto){
    if(hora >= 0 && hora <= 23 && minuto >= 0 && minuto <= 59)
        return 1;
    else    
        return 0;
}

int main(){
    int hora,minuto,verificacao;

    printf("digite a hora: ");
    scanf("%d",&hora);

    printf("\ndigite o minuto: ");
    scanf("%d",&minuto);

    verificacao = validaHora(hora,minuto);

    if(verificacao == 1)
        printf("\nhora valida!");
    else
        printf("\n hora invalida!");

    return 0;
}