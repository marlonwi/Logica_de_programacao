/*
Faça um programa que leia um vetor de 13 elementos inteiros, que é o Gabarito de um 
teste da loteria esportiva, contendo os valores 1(coluna 1), 2 (coluna 2) e 3 (coluna do 
meio). Leia, a seguir, para cada apostador, o número do seu cartão e um vetor de Respostas 
de 13 posições. Verificar para cada apostador o número de acertos, comparando o vetor de 
Gabarito com o vetor de Respostas. Escreva o número do apostador e o número de acertos.
*/
#include <stdio.h>
#define TO 13
#define NUMJ 10
int contAcertos(int n, int v[]){
    int i,ver;
    ver = 0;
    for(i = 0; i < TO; i++){
        if(v[i] == n)
        ver = 1;
    }
    return ver;
}
int main(){
    int i,j,vGabarito[TO],vPalpites[TO],vJogadores[NUMJ],acertos,vAcertos[NUMJ];
    for(i = 0; i < TO; i++){
        printf("Digite a %d resposta do Gabarito:", i + 1);
        scanf("%d", &vGabarito[i]);
    }
    for(j = 0; j < NUMJ; j++){
        printf("Digite o número do cartão do jogador:");
        scanf("%d", &vJogadores[j]);
        acertos = 0;
        for(i = 0; i < TO; i++){
            printf("Digite o %d palpite do jogador:", i + 1);
            scanf("%d", &vPalpites[i]);
            if(contAcertos(vPalpites[i], vGabarito) == 1)
                acertos++;
        }
        vAcertos[j] = acertos;
    }
    printf("\nJogador\t\tAcertos\n");
    for(i = 0; i < NUMJ; i++)
    printf("%d\t\t%d\n", vJogadores[i], vAcertos[i]);
    return 0;
}