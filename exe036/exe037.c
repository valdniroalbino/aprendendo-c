/*Implemente uma função que recebe uma string e um caracter especial e
substitua todas as vogais da string pelo caracter recebido. Retorne a string
modificada.*/
#include <stdio.h>
#include <string.h>

char * encriptacao(char * s, char c){
    int size = strlen(s);

    for(int i=0; i<size; i++){
        if( *(s+i) == 'a' || *(s+i)=='e' || *(s+i)=='i' || *(s+i)=='o' || *(s+i)=='u')
            *(s+i) = c;
    }

    return s;
}



