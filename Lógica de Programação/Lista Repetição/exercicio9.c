/*
 A prefeitura de uma cidade fez uma pesquisa entre seus habitantes, coletando dados sobre o
salário e número de filhos. A prefeitura deseja saber:
a) média do salário da população;
b) média do número de filhos;
c) maior salário;
d) percentual de pessoas com salário até R$2000,00.
O final da leitura de dados se dará com a entrada de um salário negativo.
*/
#include <stdio.h>
#include <math.h>
int main()
{
    int somaHabitantes=1, numFilhos,somaFilhos = 0;
    float salario = 0, maior,somaSalarios = 0,somaPessoasDoisMil = 0;
    while(salario >= 0){
        printf("Qual o salario da %d pessoa:", somaHabitantes);
        scanf("%f", &salario);
        if(salario < 0)
        break;
        printf("Quantos filhos a %d pessoa tem:", somaHabitantes);
        scanf("%d", &numFilhos);
        while(numFilhos < 0){
            printf("Não existe quantidade de filhos negativa!!!!\n");
            printf("Quantos filhos a %d pessoa tem:", somaHabitantes);
            scanf("%d", &numFilhos);
        }
        somaSalarios += salario;
        somaFilhos += numFilhos;
        if(somaHabitantes == 1)
            maior = salario;
        else{
            if(salario > maior)
            maior = salario;
        }
        if(salario >= 2000)
        somaPessoasDoisMil++;
        somaHabitantes++;
    }
    printf("\nA média de salario da população = %.2f", somaSalarios/(somaHabitantes - 1));
    printf("\nA média do número de filhos da população = %.2f", (float)numFilhos/(somaHabitantes - 1));
    printf("\nO maior salário entre os habitantes = R$%.2f", maior);
    printf("\nO percentual de pessoas com salario maior ou igual a R$2000 =%.2f", (somaPessoasDoisMil*100)/(somaHabitantes - 1));
    return 0;
}