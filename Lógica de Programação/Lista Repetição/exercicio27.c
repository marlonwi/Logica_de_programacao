/*
    Faça um programa que leia um conjunto de valores, um de cada vez, acompanhados de um 
código 1 ou 2. O valor representa o número de cobaias utilizadas em cada uma das experiências 
feitas e os códigos 1 e 2 representam respectivamente coelhos e ratos. Quer-se saber o total de 
cobaias utilizadas, o total de coelhos, o total de ratos, a percentagem de coelhos e a percentagem de 
ratos. Escrever estes valores.
Obs. Flag de saída código igual a 3.       
*/
#include <stdio.h>
#include <math.h>
int main()
{
    int n,codigo,coelhos=0,ratos=0;
    do
    {
        printf("Sendo:\n1-Coelhos\n2-Ratos\n3-Encerrar\nSelecione o animal que foi utilizado como cobaia:");
        scanf("%d", &codigo);
        while(codigo <= 0 || codigo > 3){
            printf("Código informado inválido!!!\n");
            printf("Sendo:\n1-Coelhos\n2-Ratos\n3-Encerrar\nSelecione o animal que foi utilizado como cobaia:");
            scanf("%d", &codigo);
        }
        if(codigo != 3){
        printf("Número de cobaias:");
        scanf("%d", &n);
        if(codigo == 1)
        coelhos += n;
        else
        ratos += n;
        }
    }while(codigo != 3);
    printf("\nA quantidade de coelhos utilizados como cobaia = %d", coelhos);
    printf("\nA quantidade de ratos utilizados como cobaia = %d", ratos);
    return 0;
}