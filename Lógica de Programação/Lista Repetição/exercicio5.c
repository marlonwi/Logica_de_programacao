//Faça um programa que receba quinze números inteiros positivos do usuário e imprima a soma da raiz quadrada de cada número.
#include <stdio.h>
#include <math.h>
int main()
{
    int i,x,soma = 0;
    for(i = 1;i <= 15; i++){
           printf("Forneça o %d numero:", i);
           scanf("%d", &x);
           while(x < 0){
               printf("Não existe raiz quadrada de número negativo!!!!\n");
               printf("Forneça outro numero:");
               scanf("%d", &x);
           }
           soma = soma + sqrt(x);
    }
    printf("A soma da raiz quadrada dos 15 números solicitados = %d", soma);
    return 0;
}