/*
   Foi feita uma pesquisa entre os habitantes de uma região. Foram coletados os dados de idade, 
sexo (M/F) e salário. Faça um programa que informe: 
a) a média de salário do grupo; 
b) maior e menor idade do grupo; 
c) quantidade de mulheres com salário até R$5000,00.
Encerre a entrada de dados quando for digitada uma idade negativa        
*/
#include <stdio.h>
#include <math.h>
int main()
{
    int sexo,idade,salarioCincoMil=0,maior,menor,cont=0;
    float salario, somaSalario = 0;
    do
    {
        cont++;
        printf("Forneça a idade do %d integrante do grupo ou um número negativo pra encerrar o programa:", cont);
        scanf("%d", &idade);
        if (idade > 0){
            if(cont == 1){
                maior = idade;
                menor = idade;
            }
            else if(idade > maior)
            maior = idade;
            else if(idade < menor)
            menor = idade;
            printf("Forneça o salário do %d integrante do grupo:", cont);
            scanf("%f", &salario);
            somaSalario += salario;
            printf("Sendo:\n1 - Masculino\n2 - Feminino\nForneça o sexo do %d integrante do grupo:", cont);
            scanf("%d", &sexo);
            if(sexo == 2 && salario >= 5000)
            salarioCincoMil++;
        }
    }while(idade >= 0);
    printf("\nA média salarial do grupo = %.2f", somaSalario/(cont - 1));
    printf("\nA maior idade do grupo = %d\nA menor idade do grupo = %d", maior,menor);
    printf("\nA quantidade de mulheres do grupo que recebem R$5000 ou mais = %d", salarioCincoMil);
    return 0;
}