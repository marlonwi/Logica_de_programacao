/*
    Uma empresa deseja aumentar seus preços em 20%. Faça um programa que leia o código e o 
preço atual de cada produto e calcule o preço novo. Calcule também, a média dos preços com e 
sem aumento. Mostre o código e o preço novo de cada produto e, no final, as médias. A entrada de 
dados deve terminar quando for lido um código de produto negativo       
*/
#include <stdio.h>
#include <math.h>
int main()
{
    int codigo,i,contProdutos=0;
    float precoAtual,precoNovo,somaPrecoAtual=0,somaPrecoNovo=0;
    do
    {
        printf("Forneça o código do produto ou um valor negativo para finalizar o programa:");
        scanf("%d", &codigo);
        if(codigo >= 0){
            contProdutos++;
            printf("Forneça o preço atual do produto:");
            scanf("%f", &precoAtual);
            somaPrecoAtual += precoAtual;
            precoNovo = precoAtual + precoAtual * 0.2;
            somaPrecoNovo += precoNovo;
            printf("Produto\t\tPreço Atual\t\tPreço Novo\n%d\t\t%.2f\t\t\t%.2f\n",codigo, precoAtual, precoNovo);
        }
    }while(codigo >= 0);
    printf("\nA média de preços sem aumento = R$%.2f", somaPrecoAtual/contProdutos);
    printf("\nA média de preços com aumento = R$%.2f", somaPrecoNovo/contProdutos);
    return 0;
}