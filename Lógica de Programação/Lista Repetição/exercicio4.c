//Faça um programa que imprima todos os números inteiros de 200 a 100 (em ordem decrescente).

#include <stdio.h>
int main()
{
    int i,par=1;
    for(i = 1;i <= 500; i++){
        if(i % 5 == 0)
           printf("%d\n", i);
    }
    return 0;
}