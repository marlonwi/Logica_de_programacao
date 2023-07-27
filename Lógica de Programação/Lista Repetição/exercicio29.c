/*
Faça  um  programa  que  leia  2  valores  inteiros  e  positivos:  X  e  Y.  O  programa  deve  calcular  e 
escrever a função potência X^Y.  
*/
#include <stdio.h>
#include <math.h>
int main (){
    int x, y, resultado;
    printf("Forneça dois valores inteiros positivos:\n");
    scanf("%d\n%d", &x, &y);
    while(x < 0 || y < 0){
        printf("Os números fornecidos devem ser inteiros e positivos!!!!\n");
        printf("Forneça dois valores inteiros positivos:\n");
        scanf("%d\n%d", &x, &y);
    }
    resultado = pow(x, y);
    printf("A função potência de %d elevado a %d = %d", x, y, resultado);
    return 0;
}