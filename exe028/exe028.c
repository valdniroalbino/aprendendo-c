/*Crie uma função chamada dobrarDois que receba 
dois ponteiros para float e dobre o valor de ambos.*/
#include <stdio.h>

void dobrarDois(float *a, float *b);

int main(){
    float x = 5.0,y = 3.0;
    
    dobrarDois(&x,&y);
    printf("x: %.1f\ny: %.1f",x,y);

    return 0;
}

void dobrarDois(float *a, float *b){
    *a = *a * *a;
    *b = *b * *b;
}

