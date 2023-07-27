/*
Faça um programa que implemente o jogo "hi-lo". A finalidade do jogo é que o usuário acerte 
um  número  entre  1  e  100,  escolhido  aleatoriamente  pelo  programa.  A  cada  palpite  do  usuário,  o 
programa deve responder indicando se este  é inferior ou superior  ao número escondido. Quando o 
usuário acertar, o programa deve dar-lhe os parabéns e indicar em quantas jogadas acertou. 
Obs.: 
rand (x) = um número aleatório, menor que x e maior ou igual a zero. 
*/
#include <stdio.h>
#include <stdlib.h>
int main (){
    int palpite,x;
    x = rand() % 100;
    do
    {
        printf("Escolha um número de 0 a 100:");
        scanf("%d", &palpite);
        while(palpite < 0 || palpite > 100){
            printf("Seu palpite deve ser um número de 0 a 100!!!\n");
            printf("Escolha um número de 0 a 100:");
            scanf("%d", &palpite);
        }
        if(palpite > x)
        printf("O número eh menor que %d\n", palpite);
        else if (palpite < x)
        printf("O número é maior que %d\n", palpite);
    } while (palpite != x);
    printf("\nParabénss, vc acertou o número!!!!");
    return 0;
}