/*
    Foi realizada uma pesquisa de algumas características físicas da população de uma certa região, 
a qual coletou os seguintes dados referentes a cada habitante para serem analisados: 
- sexo (masculino e feminino);
- cor dos olhos (azuis, verdes ou castanhos);
- cor dos cabelos (louros, castanhos, pretos);
- idade.
Faça um programa que determine e escreva: 
- a maior idade dos habitantes 
- a quantidade de indivíduos do sexo feminino cuja idade está entre 18 e 35 anos inclusive e que 
tenham olhos verdes e cabelos louros. 
O final do conjunto de habitantes é identificado pelo valor -1 fornecido para idade       
*/
#include <stdio.h>
#include <math.h>
int main()
{
    int sexo,idade,corOlhos,corCabelos,maior=0,contPadrao=0;
    do
    {
        printf("Forneça a idade do integrante do grupo ou -1 pra encerrar o programa:");
        scanf("%d", &idade);
        if (idade != -1){
            if(idade > maior)
            maior = idade;
            printf("Sendo:\n1 - Azuis\n2 - Verdes\n3 - Castanhos\nForneça a cor dos olhos do integrante do grupo:");
            scanf("%d", &corOlhos);
            printf("Sendo:\n1 - Louros\n2 - Castanhos\n3 - Pretos\nForneça a cor dos cabelos do integrante do grupo:");
            scanf("%d", &corCabelos);
            printf("Sendo:\n1 - Masculino\n2 - Feminino\nForneça o sexo do integrante do grupo:");
            scanf("%d", &sexo);
            if(sexo == 2 && 18 <= idade <= 35 && corOlhos == 2 && corCabelos == 1)
            contPadrao++;
        }
    }while(idade != -1);
    printf("\nA maior idade dos habitantes = %d", maior);
    printf("\nA quantidade de mulheres do grupo que estão entre os 18 e 35 anos\n");
    printf("possui olhos verdes e cabelos Louros = %d", contPadrao);
    return 0;
}