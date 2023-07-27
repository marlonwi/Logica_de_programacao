/*Um vendedor necessita de um algoritmo que calcule o preço total devido por um cliente. O
algoritmo deve receber o código de um produto e a quantidade comprada e calcular o preço total,
usando a tabela abaixo:
Código do produto Preço unitário
1001 5,40
1324 7,00
6548 2,37
3987 5,32
7623 6,45*/
#include <stdio.h>

int main()
{
    int opcao,quantidade;
    float preco;
    printf("1001\t5,40\n1324\t7,00\n6548\t2,37\n3987\t5,32\n7623\t6,45");
    printf("\nDigite o código do seu pedido:");
    scanf("%d", &opcao);
    switch(opcao)
    {
        case 1001:
        preco=5.40;
        break;
        case 1324:
        preco=7.00;
        break;
        case 6548:
        preco=2.37;
        break;
        case 3987:
        preco=5.32;
        break;
        case 7623:
        preco=6.45;
        break;
        default:
        printf("Código invalido!!!!\nRefazer pedido");
        return 0;
    }
    printf("Quantidade de itens do seu pedido:");
    scanf("%d", &quantidade);
    printf("O valor final = R$%.2f", preco*quantidade);
    return 0;
}
