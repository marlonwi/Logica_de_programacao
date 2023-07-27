/*
 Escreva um programa que calcule a média dos números digitados pelo usuário, se eles forem
pares. Termine a leitura se o usuário digitar zero (0). 
*/
#include <stdio.h>
#include <math.h>
int main()
{
    int numero,cont=0,soma=0;
    do
    {
        printf("Forneça um numero\n");
        printf("ou 0 para encerrar o programa:");
        scanf("%d", &numero);
           if(numero != 0 && numero % 2 == 0){
               cont++;
               soma += numero;
           }
    }while(numero != 0);
    printf("A média dos números pares digitados = %.2f", (float)soma/cont);
    return 0;
}