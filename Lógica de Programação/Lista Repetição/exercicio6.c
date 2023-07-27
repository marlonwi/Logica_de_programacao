//Faça um programa que leia 20 números e imprima a soma dos positivos e o total de números negativos.
#include <stdio.h>
#include <math.h>
int main()
{
    int i,x,soma = 0,negativos=0;
    for(i = 1;i <= 20; i++){
           printf("Forneça o %d numero:", i);
           scanf("%d", &x);
              if(x >= 0)
                soma = soma + x;
              else
                negativos++;
    }
    printf("A soma dos números positivos fornecidos = %d", soma);
    printf("\nO total de números negativos fornecidos = %d", negativos);
    return 0;
}