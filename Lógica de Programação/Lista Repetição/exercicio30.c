//Faça um programa que calcule o sub-factorial de n.
#include <stdio.h>
int main (){
    int n,fat = 1,i;
    float sinal, subfat = 1;
    printf("Forneça um número inteiro não negativo:");
    scanf("%d", &n);
    while(n < 0){
       printf("O número não pode ser negativo!!!!\n");
       printf("Forneça um número inteiro não negativo:");
       scanf("%d", &n);
}
    for(i = 1 ; i <= n; i++){
       if(i % 2 == 0)
       sinal = 1;
       else
       sinal = -1;
       fat = fat * i;
       subfat += sinal/fat;
       printf("%.2f\n", subfat);
}
    printf("O subfatorial de %d = %.2f", n,fat * subfat);
return 0;
} 