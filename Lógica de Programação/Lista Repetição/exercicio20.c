/*
 Escrever um programa que leia uma quantidade desconhecida de números e conte quantos deles
estão nos seguintes intervalos: [0.25], [26,50], [51,75] e [76,100]. A entrada de dados deve terminar
quando for lido um número negativo.    
*/
#include <stdio.h>
#include <math.h>
int main()
{
    int num,intervalo1 = 0,intervalo2 = 0,intervalo3 = 0,intervalo4 = 0;
    do{
        printf("Forneça um numero inteiro positivo(0 a 100)\n");
        printf("ou um numero negativo para finalizar a execução:");
        scanf("%d", &num);
        while(num>100){
            printf("Números maiores que 100 não são válidos!!!\n");
            printf("Forneça um numero inteiro positivo(0 a 100)\n");
            printf("ou um numero negativo para finalizar a execução:");
            scanf("%d", &num);
        }
        if(num >= 0){
            if(num <= 25)
            intervalo1++;
            else if(num <=50)
            intervalo2++;
            else if(num <= 75)
            intervalo3++;
            else
            intervalo4++;
        }
    }while(num >= 0);
    printf("\nA quantidade de valores no intervalo de 0 a 25 = %d", intervalo1);
    printf("\nA quantidade de valores no intervalo de 26 a 50 = %d", intervalo2);
    printf("\nA quantidade de valores no intervalo de 51 a 75 = %d", intervalo3);
    printf("\nA quantidade de valores no intervalo de 76 a 100 = %d", intervalo4);
    return 0;
}