/*
  Escrever um programa que tenha como entrada um número não determinado de pares de valores
m,n, todos inteiros e positivos, um par de cada vez, e calcula e escreve a soma dos n inteiros
consecutivos a partir de m inclusive.     
*/
#include <stdio.h>
#include <math.h>
int main()
{
    int m,n,soma=0;
    do{
        printf("Forneça um par de numeros onde o segundo deve ser maior que o primeiro\n");
        printf("Formato:(m n):");
        scanf("%d %d", &m, &n);
        while(m>n){
            printf("O primeiro número não pode ser maior que o segundo!!!\n");
            printf("Forneça um par de numeros onde o segundo deve ser maior que o primeiro\n");
            printf("Formato:(m n) ou Forneça ambos como 0 para finalizar:");
            scanf("%d %d", &m, &n);
        }
        if(m != 0 || n != 0){
            for(m;m<=n;m++)
            soma+=m;
              printf("A soma de todos números no intervalo = %d", soma);
              soma = 0;
        }
    }while(m != 0 && n != 0);
    return 0;
}