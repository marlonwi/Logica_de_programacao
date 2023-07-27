/*
Escrever um programa que leia um valor X e calcule e mostre os 20 primeiros termos da série:  
1 / X   -  1 / X^2   + 1 / X^3    - 1 / X^4 ... 
*/
#include <stdio.h>
#include <math.h>
int main(){
    int i,numerador,denominador,x;
    float resultado;
    printf("Forneça o valor de x:");
    scanf("%d", &x);
    for(i = 1; i <= 20; i++){
        if(i % 2 == 0)
        numerador = -1;
        else
        numerador = 1;
        denominador = pow(x,i);
        resultado = (float)numerador / denominador;
        printf("O %d termo da série é %d/%d que = %f\n", i, numerador, denominador, resultado);
    }
}