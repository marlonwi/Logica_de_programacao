/*
 Escrever um programa que leia um número n que indica quantos valores devem ser lidos. Para
cada número lido, mostre uma tabela contendo o valor lido e o fatorial deste valor.    
*/
#include <stdio.h>
#include <math.h>
int main()
{
    int numRep,n,i,d,fat=1;
    printf("Quantos valores serão lidos:");
    scanf("%d", &numRep);
    for(i=1; i <= numRep; i++){
        printf("Forneça o %d número inteiro positivo:", i);
        scanf("%d", &n);
        while(n < 0){
            printf("O valor fornecido deve ser inteiro positivo!!!!\n");
            printf("Forneça o %d número inteiro positivo:", i);
            scanf("%d", &n);
        }
        for(d=1; d <= n ; d++)
        fat = fat * d;
        printf("Número\t\tFatorial\n%d\t\t%d\n\n",n,fat);
        fat = 1;
    }
    return 0;
}