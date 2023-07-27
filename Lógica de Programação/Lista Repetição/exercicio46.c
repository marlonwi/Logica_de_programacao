/*
Escrever  um  programa  que  tenha  como  entrada  um  valor  N  inteiro  e  positivo.  Calcular  e 
escrever o valor de E. 
 
E = 1 + 1 / 1! + 1 / 2! + 1 / 3! + 1 / N!
*/
#include <stdio.h>
int main (){
    int fat = 1,i,n;
    float soma = 1;
    printf("Informe um valor inteiro e positivo N:");
    scanf("%d", &n);
    while(n <= 0){
        printf("O valor de n deve ser inteiro e positivo!!!!\n");
        printf("Informe um valor inteiro e positivo N:");
        scanf("%d", &n);
    }
    for(i=1; i < n; i++){
        fat = fat * i;
        soma += (float)1/fat;
    }
    printf("A soma dos %d termos da serie = %f", n, soma);
    return 0;
}