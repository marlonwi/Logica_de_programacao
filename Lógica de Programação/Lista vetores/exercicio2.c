/*
Faça um programa que tenha como entrada 30 valores e   colocá-los em 2 vetores 
conforme forem pares ou ímpares. Cada vetor possui 5 posições. Se algum vetor estiver 
cheio, imprimir o seu conteúdo. Terminada a leitura escrever o conteúdo dos dois vetores. 
Cada vetor pode ser preenchido tantas vezes quantas forem necessárias.
*/
#include <stdio.h>
#define TAM 30
int verificandoParImpar(int n){
    if(n % 2 == 0)
    return 1;
    else
    return 0;
}
int main(){
    int v[TAM], vI[5] = {0}, vP[5] = {0}, i, posI=0,posP=0,j;
    for(i = 0; i < TAM; i++){
        printf("Preencha o %do número inteiro(maior que 0)", i + 1);
        scanf("%d", &v[i]);
        while(v[i] <= 0){
            printf("Valor informado menor ou igual a 0!!!\n");
            printf("Preencha o %do número inteiro(maior que 0)", i + 1);
            scanf("%d", &v[i]);
        }
        if(verificandoParImpar(v[i]) == 1){
            vP[posP] = v[i];
            posP++;
            if(posP >= 5){
                for(j = 0; j < 5; j++)
                printf("%d\t", vP[j]);
                printf("\n");
                posP = 0;
            }
        }
        else{
            vI[posI] = v[i];
            posI++;
            if(posI >= 5){
                for(j = 0; j < 5; j++)
                printf("%d\t", vI[j]);
                printf("\n");
                posI = 0;
            }
        }
    }
    if(vP[1] == 0)
        printf("Não foi inserido nenhum número par!!!");
    else{
        printf("Vetor dos pares:\n");
        if(posP == 0){
            for(i = 0; i < 5; i++)
                printf("%d\t", vP[i]);
        }
        else{
            for(i = 0; i < posP; i++)
                printf("%d\t", vP[i]);
        }
    }
    if(vI[1] == 0)
        printf("\nNão foi inserido nenhum número ímpar!!!");
    else{
        printf("\nVetor dos ímpares:\n");
        if(posI == 0){
            for(i = 0; i < 5; i++)
                printf("%d\t", vI[i]);
        }
        else{
            for(i = 0; i < posI; i++)
                printf("%d\t", vI[i]);
        }
    }
    return 0;
}