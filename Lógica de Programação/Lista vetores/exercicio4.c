/*
Faça um programa que leia um vetor de 80 elementos inteiros. Encontre e mostre o 
menor elemento e sua(s) posição(ões) no vetor.
*/
#include <stdio.h>
#define TAM 80
void menorElemento(int v[]){
    int i,menor;
    menor = v[0];
    for(i = 1; i < TAM; i++){
        if(v[i] < menor)
        menor = v[i];
    }
    printf("\nMenor elemento\t\t%d\n", menor);
    printf("Posição(ões)");
    for(i = 0; i < TAM; i++){
        if(v[i] == menor){
            printf("\t\t%d", i);
        }
    }
}
int main (){
    int vElementos[TAM], i;
    for(i = 0; i < TAM; i++){
        printf("Digite o %d elemento do vetor:", i + 1);
        scanf("%d", &vElementos[i]);
    }
    menorElemento(vElementos);
    return 0;
}