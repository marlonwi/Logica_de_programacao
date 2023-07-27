//Faça um programa que imprima os 100 primeiros inteiros positvos pares.
#include <stdio.h>
int main()
{
    int i,par=1;
    for(i = 1;par <= 100; i++){
    if(i % 2 == 0){
    printf("%d\n", i);
    par++;
    }
    }
    return 0;
}