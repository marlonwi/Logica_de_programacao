/*
 Construir um programa que calcule a média aritmética de vários valores inteiros positivos. O
final da leitura acontecerá quando for lido um valor negativo. 
*/
#include <stdio.h>
#include <math.h>
int main()
{
    int valor, cont = 0, soma = 0;
    do
    {
        printf("Forneça um valor inteiro positivo para media aritmética ser incrementada \n");
        printf("ou um valor negativo para obter o resultado da media:");
        scanf("%d", &valor);
           if(valor >= 0)
           soma += valor;
        cont++;
    }while(valor >= 0);
    printf("\nA média aritmética dos valores fornecidos = %.1f", (float)soma/(cont - 1));
    return 0;
}