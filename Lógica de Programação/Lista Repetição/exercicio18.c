/*
 Escrever um programa que leia um número não determinado de valores e calcule a média
aritmética dos valores lidos, a quantidade de valores positivos, a quantidade de valores negativos e
o percentual de valores negativos e positivos. Mostre os resultados. Adote um falg de saída..    
*/
#include <stdio.h>
#include <math.h>
int main()
{
    int neg=0,pos=0,cont = 0;
    float num;
    do{
        printf("Forneça um numero diferente de 0 para continuar\n");
        printf("ou 0 para finalizar a execução:");
        scanf("%f", &num);
        if(num != 0){
            cont++;
            if(num > 0)
            pos++;
            else
            neg++;
        }
    }while(num != 0);
    printf("\nA quantidade de valores positivos lidos = %d", pos);
    printf("\nA quantidade de valores negativos lidos = %d", neg);
    printf("\nO percentual de valores positivos lidos = %.2f", (float)pos*100/cont);
    printf("\nO percentual de valores negativos lidos = %.2f", (float)neg*100/cont);
    return 0;
}