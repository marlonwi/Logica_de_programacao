//Faça um algoritmo que tenha como entrada 3 valores a,b,c e os imprima em ordem crescente.
#include <stdio.h>
int main(){
    float a, b ,c;
    printf("Forneça o primeiro número:");
    scanf("%f", &a);
    printf("Forneça o segundo número:");
    scanf("%f", &b);
    printf("Forneça o terceiro número:");
    scanf("%f", &c);
    if(a>b && a>c){
        if(b>c)
        printf("A ordem crescente será %.1f,%.1f,%.1f", c,b,a);
        else
        printf("A ordem crescente será %.1f,%.1f,%.1f", b,c,a);
    }
    else if(b>a && b>c){
        if(a>c)
        printf("A ordem crescente será %.1f,%.1f,%.1f", c,a,b);
        else
        printf("A ordem crescente será %.1f,%.1f,%.1f", a,c,b);
    }
    else{
        if(b>a)
        printf("A ordem crescente será %.1f,%.1f,%.1f", a,b,c);
        else
        printf("A ordem crescente será %.1f,%.1f,%.1f", b,a,c);
    }
    return 0;
}