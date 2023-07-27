/*
   Escrever um programa que tenha como entrada um número não determinado de valores para m,
todos inteiros e positivos, um de cada vez. Se m for par, verificar quantos divisores possui e
escrever esta informação. Se m for impar e menor do que 10 calcular e escrever o fatorial de m. Se
m for ímpar e maior ou igual a 10 calcular e escrever a soma dos inteiros de 1 até m.      
*/
#include <stdio.h>
#include <math.h>
int main()
{
    int m,soma=0,i,cont=0,fat=1;
    do{
        printf("Forneça um número inteiro positivo\n");
        printf("ou 0 para finalizar o programa:");
        scanf("%d", &m);
        while(m < 0){
            printf("O número não pode ser menor que 0!!!\n");
            printf("Forneça um número inteiro positivo\n");
            printf("ou 0 para finalizar o programa:");
            scanf("%d", &m);
        }
        if(m != 0){
            if(m % 2 == 0){
                for(i=1; i<=m ; i++){
                    if(m % i == 0)
                    cont++;
                }
                printf("O número é par!!!");
                printf("O numero %d possui %d divosores\n", m,cont);
                cont=0;
            }
        else if(m % 2 != 0 && m < 10){
            for(i=1 ; i <= m; i++){
                fat=fat * i;
            }
            printf("O m é ímpar menor que 10!!!\n");
            printf("O fatorial de %d = %d\n", m, fat);
            fat=1;
        }
        else{
            for(i=1; i <= m; i++){
                soma += i;
            }
            printf("O número é ímpar maior ou igual a 10!!!\n");
            printf("A soma de todos os número de 1 até %d é %d\n", m,soma);
            soma = 0;
        }
      }
    }while(m != 0);
    return 0;
}