/*
 Escreva um programa que leia 50 valores e encontre o maior e o menor deles. Mostre o
resultado.  
*/
#include <stdio.h>
#include <math.h>
int main()
{
    int i;
    float numero, maior, menor;
    const int NR = 4;
    for(i=1;i <= NR;i++){
        printf("Forneça um numero:");
        scanf("%f", &numero);
           if(i == 1){
               maior = numero;
               menor = numero;
        }
           else{
               if(numero > maior)
               maior = numero;
               else if(numero < menor)
               menor = numero;
        }
    }
    printf("O maior número  = %.2f\nO menor número = %.2f", maior, menor);
    return 0;
}