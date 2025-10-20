#include <stdio.h>

int main(){
    int temperatura;

    printf("digite o valor da temperatura: ");
    scanf("%d",&temperatura);

    if(temperatura < 10)
        printf("MUITO FRIO");
    else if(temperatura >= 10 && temperatura <17)
        printf("FRIO");
    else if(temperatura >= 17 && temperatura <23)
        printf("BOM TEMPO");
    else if(temperatura >= 23 && temperatura <27)
        printf("CALOR");
    else
        printf("PERIGO DE EXPOSICAO SOLAR");
    
    return 0;
    
}
