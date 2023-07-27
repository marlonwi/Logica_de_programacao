//Faça um algoritmo para calcular as raízes de uma esquação do segundo grau.
#include <stdio.h>
#include <math.h>
int main(){
    float a,b,c,r1,r2,delta;
    printf("Em uma equação ax^2+bx+c=0(onde a diferente de 0:)");
    printf("\nInforme o a da equação:");
    scanf("%f", &a);
    printf("Informe o b da equação:");
    scanf("%f", &b);
    printf("Informe o c da equação:");
    scanf("%f", &c);
    delta = (b * b) - 4*(a * c);
    if(a!=0){
        if(delta == 0){
            r1 = -b/(2*a);
            printf("A equação possui apenas uma raiz real =%.1f", r1);
        }
        else if(delta >0){
            r1 = (-b + sqrt(delta))/(2*a);
            r2 = (-b - sqrt(delta))/(2*a);
            printf("A equação possui duas raizes reais, uma =%.1f e outra =%.1f", r1, r2);
        }
        else
            printf("A equação não possui raízes reais!!!!");
    }
    else
    printf("O a tem que ser diferente de 0!!!!");
    return 0;
}