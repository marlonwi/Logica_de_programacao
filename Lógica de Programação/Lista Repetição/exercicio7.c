/*
Faça um programa que tenha como entrada um conjunto de numeros inteiros. Calcular e
imprimir:
a) A media dos numeros lidos;
b) O maior número;
c) O menor número.
Obs. Flag de saida= numero zero (não deve ser considerado)
*/
#include <stdio.h>
#include <math.h>
int main()
{
    int i, x, soma = 0, qntd, maior, menor;
    printf("Quantos números vão possuir no conjunto:");
    scanf("%d", &qntd);
    for(i = 1;i <= qntd; i++){
           printf("Forneça o %d numero:", i);
           scanf("%d", &x);
           soma = soma + x;
              if(i == 1){
                  maior = x;
                  menor = x;
              }
              else{
                  if(x > maior)
                  maior = x;
                  else if (x < menor)
                  menor = x;
              }
    }
    printf("A média dos números fornecidos = %d", soma/qntd);
    printf("\nO maior número fornecido = %d", maior);
    printf("\nO menor número fornecido = %d", menor);
    return 0;
}