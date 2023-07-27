/*
Implementar uma função para  calcular o cos(X).  O valor do cosseno de X será calculado pela 
soma dos 15 primeiros termos da série a seguir:  
cos( X ) =  1  -    X2 / 2!  +    X4 / 4!   -     X6 / 6!  +   X8 / 8!  ....                                                  
*/
#include <stdio.h>
#include <math.h>
int main (){
    int x,fat,i,j,sinal,numerador;
    float soma=0,rad;
    const float PI = 3.14159;
    printf("Qual angulo sera calculado o cosseno:");
    scanf("%d", &x);
    rad = (float)x * (PI/180);
    for(i = 2; i < 15; i++){
        if(i == 1)
            soma = 1;
        else{
        if(i % 2 == 0)
            sinal = -1;
        else
            sinal = 1;
        numerador = pow(rad,i * 2);
        for(j = 1; j <= i * 2; j++)
        fat = fat*j;
        soma = (sinal * soma)/fat;
        }
    }
    printf("O cosseno de %d = %f", x,soma);
    return 0;
}