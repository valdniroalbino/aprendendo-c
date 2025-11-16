#include "carro.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*TAD carro*/

int main(){
    carro *c1,*c2;
    char marca[50];
    char modelo[50];
    int potencia;
    char cor[20];
    int motor;
    int light;
    int i=0,opcao;
    carro *carCreate(char marca[],char modelo[],int potencia,char cor[],int motor,int light);

    while(opcao != 100){
        puts("dados do primeiro carro!");
        printf("marca: ");
        fgets(marca,sizeof(marca),stdin);
        printf("modelo: ");
        fgets(modelo,sizeof(modelo),stdin);
        printf("cor: ");
        fgets(cor,sizeof(cor),stdin);
        printf("potencia: ");
        scanf("%d",&potencia);
        getchar();
        motor = 0;
        light = 0;

        c1 = carCreate(marca,modelo,potencia,cor,motor,light);

        puts("dados do segundo carro!");
        printf("marca: ");
        fgets(marca,sizeof(marca),stdin);
        printf("modelo: ");
        fgets(modelo,sizeof(modelo),stdin);
        printf("cor: ");
        fgets(cor,sizeof(cor),stdin);
        printf("potencia: ");
        scanf("%d",&potencia);
        getchar();
        motor = 0;
        light = 0;

        c2 = carCreate(marca,modelo,potencia,cor,motor,light);

        printf("1 - carro 1;\n2 - carro 2;\n3 - comparar potencias\n4 - encerrar\n");
        printf("digite o numero: ");
        scanf("%d",&opcao);

        switch(opcao){
            case 1:
                int opcao1;
                printf("1 - ligar/desligar;\n2 - buzinar;\n3 - liga/desligar luzes;\n4 - trocar a potencia;\n5 - ver potencia;\n6 - ver cor;\n7 - alterar cor;\n8 - apagar carro;\n");
                printf("digite o numero: ");
                scanf("%d",&opcao1);
                

                switch(opcao1){
                    case 1:
                        int statusM = carOnOff(c1);
                        if(statusM == 1)
                            printf("carro ligado!");
                        else    
                            printf("carro desligado!");

                        break;
                    case 2:
                        carSound(c1);
                        break;
                    case 3: 
                        int statusL = carLights(c1);
                        break;
                    case 4:
                        int newPower;
                        printf("digite a potencia: ");
                        scanf("%d",&newPower);
                        carChangePower(c1,newPower);
                        break;
                    case 5:
                        carPower(c1);
                        break;
                    case 6: 
                        carColour(c1);
                        break;
                    case 7:
                        char newCor[20];
                        printf("nova cor: ");
                        fgets(newCor,sizeof(newCor),stdin);
                        getchar();
                        
                        carChangeColour(c1,newCor);
                        break;
                    case 8:
                        free(c1);
                        break;
                    default: 
                        puts("valor invalido!");
                }
                break;
            case 2:
                int opcao2;
                    printf("1 - ligar/desligar;\n2 - buzinar;\n3 - liga/desligar luzes;\n4 - trocar a potencia;\n5 - ver potencia;\n6 - ver cor;\n7 - alterar cor;\n8 - apagar carro;\n");
                    printf("digite o numero: ",&opcao2);

                    switch(opcao2){
                        case 1:
                            int statusM = carOnOff(c2);
                            if(statusM == 1)
                                printf("carro ligado!");
                            else    
                                printf("carro desligado!");

                            break;
                        case 2:
                            carSound(c2);
                            break;
                        case 3: 
                            int statusL = carLights(c2);
                            break;
                        case 4:
                            int newPower;
                            printf("digite a potencia: ");
                            scanf("%d",&newPower);
                            carChangePower(c2,newPower);
                            break;
                        case 5:
                            carPower(c2);
                            break;
                        case 6: 
                            carColour(c2);
                            break;
                        case 7:
                            char newCor[20];
                            printf("nova cor: ");
                            fgets(newCor,sizeof(newCor),stdin);
                            getchar();
                            
                            carChangeColour(c2,newCor);
                            break;
                        case 8:
                            free(c2);
                            break;
                        default: 
                            puts("valor invalido!");
                    }
                break;
            case 3:
                    carVScar(c1,c2);
                    break;
            case 4: 
                    puts("Encerrando...");
                    opcao = 100;
                    break;
            default:
                    puts("valor invalido!");
        }
        i++;
    }
    return 0;
}