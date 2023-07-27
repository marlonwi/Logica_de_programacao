/*
Escreva um programa que leia um valor n inteiro e positivo e que calcule a seguinte soma:
S = 1 + 1/2 + 1/3 + 1/4 + ... + 1/N
*/
#include <stdio.h>
int main (){
    int nr,i;
    float soma = 0;
    printf("Insira o número de termos que serão somados:");
    scanf("%d", &nr);
    for(i = 1; i<= nr; i++){
        soma = soma + (float)1 / i;
        if(i != nr)
        printf("A soma dos %d termos somados = %.2f\n", i, soma);
    }
    printf("\nA soma dos %d termos somados = %.2f", nr, soma);
    return 0;
}