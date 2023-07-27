/*
    Faça um programa que leia dois vetores de 10 posições e faça a multiplicação dos 
elementos de mesmo índice, colocando o resultado em um terceiro vetor. Imprimir o vetor 
resultante. 
*/
#include <stdio.h>
#define TAM 10
void multiplicandoMesmosIndices(int v1[], int v2[]){
    int i, vR[TAM];
    for(i = 0; i < TAM; i++)
        vR[i] = v1[i] * v2[i];
    printf("O vetor resultante será:\n");
    for(i = 0; i < TAM; i++)
        printf("%d\t", vR[i]);
}
int main(){
    int v1[TAM], v2[TAM],i;
    for(i = 0; i < TAM; i++){
    printf("Preencha o %d espaço do primeiro vetor:", i + 1);
    scanf("%d", &v1[i]);
    }
    for(i = 0; i < TAM; i++){
    printf("Preencha o %d espaço do segundo vetor:", i + 1);
    scanf("%d", &v2[i]);
    }
multiplicandoMesmosIndices(v1,v2);
return 0;
}