/*O cardápio de uma lanchonete é o seguinte:
Código Especificação Preço unitário
100 Pastel 2,5
101 Bauru simples 3,20
102 Bauru c/ovo 3,5
103 Hamburger 4,10
104 Cheeseburger 6,0
105 Refrigerante 2,0
Escrever um algoritmo que leia o código do item pedido, a quantidade e calcule o valor a ser pago
por aquele lanche. Considere que a cada execução somente será calculado um item.*/
#include <stdio.h>

int main()
{
    int opcao,quantidade;
    float preco;
    printf("Código\tLanche\t\tPreço\n100\tPastel\t\t2,50\n101\tBauru simples\t3,20\n102\tBauru c/ovo\t3,50\n103\tHamburger\t4,10\n104\tCheeseburger\t6,00\n105\tRefrigerante\t2,00");
    printf("\nDigite o código do seu pedido:");
    scanf("%d", &opcao);
    switch(opcao)
    {
        case 100:
        preco=2.50;
        break;
        case 101:
        preco=3.20;
        break;
        case 102:
        preco=3.50;
        break;
        case 103:
        preco=4.10;
        break;
        case 104:
        preco=6.00;
        break;
        case 105:
        preco=2.00;
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
