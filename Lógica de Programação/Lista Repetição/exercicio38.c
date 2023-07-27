/*
Escrever um programa para calcular e escrever o produto dos números primos entre M e N. 
M e N são inteiros positivos e M é menor que N.
*/
#include <stdio.h>
int main(){
    int i,m,n,produto=1,divisor=0;
    printf("Forneça dois números para ser calculado o produto dos primos entre eles\n");
    printf("Sendo que o primeiro número deve ser menor q o segundo:\n");
    scanf("%d\n%d", &m, &n);
    while (m > n){
        printf("O primeiro número deve ser menor que o segundo!!!!\n");
        printf("Forneça dois números para ser calculado o produto dos primos entre eles\n");
        printf("Sendo que o primeiro número deve ser menor q o segundo:\n");
        scanf("%d\n%d", &m, &n);
    }
    for(m; m <= n; m++){
        for(i=1; i<=m; i++){
            if(m % i == 0)
            divisor++;
        }
        if(divisor == 2){
            produto = produto * m;
        }
        divisor = 0;
    }
    printf("O produto dos primos entre %d e %d = %d", m - n, n, produto);
    
    return 0;
}