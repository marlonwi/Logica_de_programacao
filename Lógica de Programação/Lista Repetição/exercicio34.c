/*
Faça um programa que calcule a soma dos  N (>0) primeiros termos da série Fibonacci  
S = 0   1   1   2   3   5   8   13   ... 
*/
#include <stdio.h>
int main (){
    int n, soma=0,i,primeiro = 0,segundo =1, proximo;
    printf("Número de séries que serão somadas:");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        if (i == 0) 
           proximo = 0;
        else if (i == 1) {
           proximo = 1;
    } 
        else {
           proximo = primeiro + segundo;
           primeiro = segundo;
           segundo = proximo;
}
        soma += proximo;
    }
    printf("A soma dos %d termos da série Fibonacci = %d", n,soma);
    return 0;
}