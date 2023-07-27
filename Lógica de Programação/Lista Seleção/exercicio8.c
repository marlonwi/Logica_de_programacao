/*Uma empresa concederá um aumento de salário aos seus funcionários, variável de acordo com o
cargo, conforme a tabela abaixo. Faça um algoritmo que leia o salário e o cargo de um funcionário e
calcule o novo salário. Se o cargo do funcionário não estiver na tabela, ele deverá, então, receber
40% de aumento. Mostre o salário antigo, o novo salário e a diferença.
Código Cargo Percentual
101 Gerente 10%
102 Engenheiro 20%
103 Técnico 30%*/
#include <stdio.h>

int main()
{
    int opcao;
    float salarioAntigo,salarioNovo;
    printf("Código\tCargo\t\tPercentual\n101\tGerente\t\t10\n102\tEngenheiro\t20\n103\tTécnico\t\t30");
    printf("\nDigite o código do cargo:");
    scanf("%d", &opcao);
    printf("Digite o salário do funcionário:");
    scanf("%f", &salarioAntigo);
    switch(opcao)
    {
        case 101:
        salarioNovo = salarioAntigo * 1.1;
        break;
        case 102:
        salarioNovo = salarioAntigo * 1.2;
        break;
        case 103:
        salarioNovo = salarioAntigo * 1.3;
        break;
        default:
        salarioNovo = salarioAntigo * 1.4;
    }
    printf("Salário antigo = R$%.2f\nSalário Novo = R$%.2f\nDiferença = R$%.2f", salarioAntigo, salarioNovo, salarioNovo - salarioAntigo);
    return 0;
}
