/*
Considere uma estrutura de dados para representar uma venda:
• Número da Nota Fiscal
• Série da Nota fiscal
• Valor total da Nota Fiscal
• Data da emissão da Nota Fiscal
• Data da recepção das mercadorias pelo cliente
O programa deverá fornecer as seguintes funcionalidades:
a) Lançar os dados de, no máximo, 100 vendas. 
b) Pesquisar por uma venda a partir do número da nota fiscal.
c) Listar as vendas realizadas em uma determinada data.
d) Total das vendas realizadas em um determinado mês.
e) Valor médio das vendas.
*/
#include <stdio.h>
#include <string.h>
#define MAX 100
typedef struct{
    float valor;
    int serie, numNotaFiscal, dataEmissao[3], dataRecepcao[3];
}TVendas;
int validaSerie(TVendas vV[], int tamanho, int ultimaPos, int serieNF){
    int i;
    for(i = 0; i <= ultimaPos; i++){
        if(serieNF == vV[i].serie)
            return i;
    }
    return -1;
}
int validaData(int dia, int mes, int ano){
    if(ano > 1900){
        if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12){
            if(dia > 0 && dia <= 31)
                return 1;
        }
        else if(mes == 4 || mes == 6 || mes == 9 || mes == 11){
            if(dia > 0 && dia <= 30)
                return 1;
        }
        else if(mes == 2){
            if(dia > 0 && dia <= 28)
                return 1;
        }
    }
    return -1;
}
void registrarVenda(TVendas vV[], int tamanho, int *ultimaPos){
    int sair,serieNF,data[3],valData;
    do{
        if(*ultimaPos == tamanho-1){
            printf("\nLimite máximo de vendas atingido!!!\n");
            sair = 1;
        }
        else{
            printf("Informe o número de série da nota fiscal:");
            scanf("%d", &serieNF);
            if(validaSerie(vV, tamanho, *ultimaPos, serieNF) != -1)
                printf("\nNota fiscal já cadastrada!!!!\n");
            else{
                (*ultimaPos)++;
                vV[*ultimaPos].serie = serieNF;
                vV[*ultimaPos].numNotaFiscal = *ultimaPos + 1;
                do{
                printf("Informe valor da venda:");
                scanf("%f", &vV[*ultimaPos].valor);
                if(vV[*ultimaPos].valor <= 0)
                    printf("\nNão existe uma venda negativa!!!\n");
                }while(vV[*ultimaPos].valor <= 0);
                do{
                printf("Informe a data da emissão da Nota Fiscal(dd/mm/aaaa):");
                scanf("%d/%d/%d", &data[0], &data[1], &data[2]);
                valData = validaData(data[0], data[1], data[2]);
                if(valData == -1)
                    printf("\nData incorreta!!!!\n");
                }while(valData == -1);
                vV[*ultimaPos].dataEmissao[0] = data[0];
                vV[*ultimaPos].dataEmissao[1] = data[1];
                vV[*ultimaPos].dataEmissao[2] = data[2];
                do{
                printf("Informe a data da recepção das mercadorias pelo cliente(dd/mm/aaaa):");
                scanf("%d/%d/%d", &data[0], &data[1], &data[2]);
                valData = validaData(data[0], data[1], data[2]);
                if(valData == -1)
                    printf("\nData incorreta!!!!\n");
                }while(valData == -1);
                vV[*ultimaPos].dataRecepcao[0] = data[0];
                vV[*ultimaPos].dataRecepcao[1] = data[1];
                vV[*ultimaPos].dataRecepcao[2] = data[2];
            }
            printf("Deseja sair do registro de venda:");
            printf("\n1- Sim\n2- Não\n");
            printf("Selecione sua opção:");
            scanf("%d", &sair);
        }
    }while(sair != 1);
}
void pesquisarVenda(TVendas vV[], int tamanho, int ultimaPos){
    int serie,venda;
    printf("Informe a serie da nota fiscal a ser pesquisada:");
    scanf("%d", &serie);
    venda = validaSerie(vV, tamanho, ultimaPos, serie);
    if(venda == -1)
        printf("\nSerie da nota fiscal não encontrada!!!!\n");
    else{
        printf("Dados nota fiscal:\n");
        printf("Número\t\t\tSérie\t\t\tValor\t\t\tData emissão\t\t\tData recepção\n");
        printf("%d\t\t\t%d\t\t\t%.2f\t\t\t%d/%d/%d\t\t\t%d/%d/%d\n", vV[venda].numNotaFiscal, vV[venda].serie, vV[venda].valor, vV[venda].dataEmissao[0], vV[venda].dataEmissao[1], vV[venda].dataEmissao[2], vV[venda].dataRecepcao[0], vV[venda].dataRecepcao[1], vV[venda].dataRecepcao[2]);
    }
}
void listagemVenda(TVendas vV[], int tamanho, int ultimaPos){
    int data[3],valData,i;
    do{
        printf("Informe a data a ser listada(dd/mm/aaaa):");
        scanf("%d/%d/%d", &data[0], &data[1], &data[2]);
        valData = validaData(data[0], data[1], data[2]);
        if(valData == -1)
            printf("\nData incorreta!!!!\n");
    }while(valData == -1);
    printf("Lista vendas %d/%d/%d\nNota fiscal:\n", data[0], data[1], data[2]);
    printf("Número\t\t\tSérie\t\t\tValor\t\t\tData emissão\t\t\tData recepção\n");
    for(i = 0; i <= ultimaPos; i++){
        if(data[0] == vV[i].dataEmissao[0] && data[1] == vV[i].dataEmissao[1] && data[2] == vV[i].dataEmissao[2])
            printf("%d\t\t\t%d\t\t\t%.2f\t\t\t%d/%d/%d\t\t\t%d/%d/%d\n", vV[i].numNotaFiscal, vV[i].serie, vV[i].valor, vV[i].dataEmissao[0], vV[i].dataEmissao[1], vV[i].dataEmissao[2], vV[i].dataRecepcao[0], vV[i].dataRecepcao[1], vV[i].dataRecepcao[2]);

    }
}
void totalVendas(TVendas vV[], int tamanho, int ultimaPos){
    int mes,i;
    float vendas = 0;
    printf("Informe o mes para saber o total de vendas:");
    scanf("%d", &mes);
    while(mes > 12 && mes <= 0){
        printf("Mês inexistente!!!!\n");
        printf("Informe o mes para saber o total de vendas:");
        scanf("%d", &mes);
    }
    for(i = 0; i <= ultimaPos; i++){
        if(vV[i].dataEmissao[1] == mes)
        vendas += vV[i].valor;
    }
    printf("O valor total de vendas = %.2f\n", vendas);
}
void valorMedio(TVendas vV[], int tamanho, int ultimaPos){
    int i;
    float valor = 0;
    for(i = 0; i <= ultimaPos; i++)
        valor += vV[i].valor;
    printf("O valor médio das vendas = %.2f\n", valor/(ultimaPos + 1));
}
int main (){
    TVendas vVendas[MAX];
    int ultimaPos = -1, opcao, sair;
    do{
        printf("Sendo:\n1- Registrar venda\n2- Pesquisar venda\n3- Listagem venda data\n4- Total vendas mês\n5- Valor médio vendas\n");
        printf("Selecione sua opção:");
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
                registrarVenda(vVendas,MAX,&ultimaPos);
                break;
            case 2:
                pesquisarVenda(vVendas,MAX,ultimaPos);
                break;
            case 3:
                listagemVenda(vVendas,MAX,ultimaPos);
                break;
            case 4:
                totalVendas(vVendas,MAX,ultimaPos);
                break;
            case 5:
                valorMedio(vVendas,MAX,ultimaPos);
                break;
        }
        printf("Deseja encerrar o programa:\n1- Sim\n2- Não");
        printf("\nSelecione sua opção");
        scanf("%d", &sair);
    }while(sair != 1);
    return 0;
}