/*Escreva uma função que receba uma string e retorne a quantidade de letras maiúsculas
 presentes nela, usando ponteiros para percorrer a string.*/

 #include <stdio.h>
 #include <ctype.h>
 #include <string.h>
 #define MAX 100

 int contaMaiuscula(char *str){
    int cont = 0;
    int size = strlen(str);

    for(int j=0 ; j < size ; j++){
        if(isupper( *(str+j) ))
            cont ++;
    }

    return cont;
 }

 int main(){
    int bigs;
    char str[MAX];

    printf("digite a string: ");
    scanf("%s",str);

    bigs = contaMaiuscula(str);

    if(bigs != 0)
        printf("maiusculas: %d",bigs);
    else
        printf("nao existem letras maiusculas!");

    return 0;
 }


 