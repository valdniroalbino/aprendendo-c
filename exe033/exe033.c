/*Implemente uma função que receba um vetor de inteiros,
 seu tamanho e dois ponteiros para inteiros. A função deve armazenar
  o máximo no primeiro ponteiro e o mínimo no segundo.
*/

#include <stdio.h>

void maxMin(int *v, int n, int *max, int *min){
    int i=0,j=0;

    *min = *(v+i);
    *max = *(v+j);

    for(i=1 ; i<n ; i++){
        if(*min > *(v+i))
            *min = *(v+i);
    }
    for(j=1; j<n ; j++){
        if(*max < *(v+j))
            *max = *(v+j);
    }

    printf("maximo: %d\nminimo: %d",*max,*min);
    
}

int main(){
    int n,max,min;

    printf("tamanho: ");
    scanf("%d",&n);

    int v[n];

    for(int x = 0 ; x < n; x++){
        printf("digite o %d valor: ",x+1);
        scanf("%d",&v[x]);
    }

    maxMin(v,n,&max,&min);

    //printf("maximo: %d\nminimo: %d",max,min);

    return 0;
}