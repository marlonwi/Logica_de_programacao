/*
Foram levantados os seguintes dados de uma população: sexo, altura (em centímetros) e peso. 
Construa um programa que permita ler os dados de, no máximo, 1000 pessoas. O programa
 deverá fornecer as seguintes consultas:
• Peso médio
• Altura média
• Sexo da pessoa mais alta
• Altura do homem mais pesado
• Altura da mulher mais pesada
As operações devem ser disponibilizadas ao usuário do programa através de um menu de opções.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 1000
typedef struct{
    int sexo, codPessoa;
    float altura, peso;
}TDados;
void leituraDados(FILE *arqD, int limite){
    TDados rD;
    int sair;
    fseek(arqD, 0, SEEK_END);
    rD.codPessoa = ftell(arqD)/sizeof(TDados);
    do{
        if(rD.codPessoa == limite){
            printf("\nLimite de pessoas cadastradas atingido!!!\n");
            sair = 1;
        }
        else{
            rD.codPessoa++;
            printf("Informe o sexo da pessoa:\n1- Masculino\n2- Feminino\nSelecione sua opção:");
            scanf("%d", &rD.sexo);
            while(rD.sexo < 1 || rD.sexo > 2){
                printf("\nSexo inválido!!!\n");
                printf("Informe o sexo da pessoa:\n1- Masculino\n2- Feminino\nSelecione sua opção:");
                scanf("%d", &rD.sexo);
            }
            printf("Informe a altura da pessoa:");
            scanf("%f", &rD.altura);
            while(rD.altura <= 0){
                printf("\nAltura inválida!!!\n");
                printf("Informe a altura da pessoa:");
                scanf("%f", &rD.altura);
            }
            printf("Informe o peso da pessoa:");
            scanf("%f", &rD.peso);
            while(rD.peso <= 0){
                printf("\nPeso inválido!!!!\n");
                printf("Informe o peso da pessoa:");
                scanf("%f", &rD.peso);
            }
            fseek(arqD, 0, SEEK_END);
            fwrite(&rD, sizeof(TDados), 1, arqD);
        }
        printf("Deseja sair do cadastro de dados:\n1- Sim\n2- Não\n");
        printf("Selecione sua opção:");
        scanf("%d", &sair);
    }while(sair != 1);
}
void pesoMedio(FILE *arqD){
    TDados rD;
    float somaPeso = 0;
    fseek(arqD, 0, SEEK_END);
    if(ftell(arqD)/sizeof(TDados) == 0)
        printf("\nNenhum dado inserido ainda!!!\n");
    else{
        rewind(arqD);
        while(fread(&rD, sizeof(TDados), 1, arqD) == 1)
            somaPeso += rD.peso;
        printf("A média de peso = %.2f\n", somaPeso/rD.codPessoa);
    }
}
void alturaMedia(FILE *arqD){
    TDados rD;
    float somaAltura = 0;
    fseek(arqD, 0, SEEK_END);
    if(ftell(arqD)/sizeof(TDados) == 0)
        printf("\nNenhum dado inserido ainda!!!\n");
    else{
        rewind(arqD);
        while(fread(&rD, sizeof(TDados), 1, arqD) == 1)
            somaAltura += rD.altura;
        printf("A média de altura = %.2f\n", somaAltura/rD.codPessoa);
    }
}
void sexoMaisAlta(FILE *arqD){
    TDados rD;
    float maisAlta = 0;
    int sexo,empate = 0;
    fseek(arqD, 0, SEEK_END);
    if(ftell(arqD)/sizeof(TDados) == 0)
        printf("\nNenhum dado inserido ainda!!!\n");
    else{
        rewind(arqD);
        while(fread(&rD, sizeof(TDados), 1, arqD) == 1){
            if(rD.altura > maisAlta){
                maisAlta = rD.altura;
                sexo = rD.sexo;
                empate = 0;
            }
            else if(rD.altura == maisAlta){
                if(rD.sexo != sexo)
                    empate = 1;
            }
        }
        if(empate == 1)
            printf("\nOcorreu um empate, ambos sexos possuem uma pessoa(as) com a maior altura\n");
        else if(sexo == 1)
            printf("\nA pessoa mais alta é do sexo masculino\n");
        else
            printf("\nA pessoa mais alta é do sexo feminino\n");
    }
}
void alturaHomemPesado(FILE *arqD){
    TDados rD;
    float maiorPeso = 0, altura;
    fseek(arqD, 0, SEEK_END);
    if(ftell(arqD)/sizeof(TDados) == 0)
        printf("\nNenhum dado inserido ainda!!!\n");
    else{
        rewind(arqD);
        while(fread(&rD, sizeof(TDados), 1, arqD) == 1){
            if(rD.sexo == 1){
                if(rD.peso > maiorPeso){
                    maiorPeso = rD.peso;
                    altura = rD.altura;
                }
            }
        }
        printf("A altura do homem mais pesado = %.2f\n", altura);
    }
}
void alturaMulherPesada(FILE *arqD){
    TDados rD;
    float maiorPeso = 0, altura;
    fseek(arqD, 0, SEEK_END);
    if(ftell(arqD)/sizeof(TDados) == 0)
        printf("\nNenhum dado inserido ainda!!!\n");
    else{
        rewind(arqD);
        while(fread(&rD, sizeof(TDados), 1, arqD) == 1){
            if(rD.sexo == 2){
                if(rD.peso > maiorPeso){
                    maiorPeso = rD.peso;
                    altura = rD.altura;
                }
            }
        }
    printf("A altura da mulher mais pesada = %.2f\n", altura);
    }
}
int main (){
    FILE *arqDados;
    int sair,opcao;
    arqDados = fopen("dados.dat", "rb+");
    if(!arqDados)
        arqDados = fopen("dados.dat", "wb+");
    do{
        printf("Sendo:\n");
        printf("1- Leitura de dados\n2- Peso médio\n3- Altura média\n");
        printf("4- Sexo pessoa mais alta\n5- Altura Homem mais pesado\n");
        printf("6- Altura Mulher mais pesada\nSelecione sua opção:");
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
                leituraDados(arqDados, MAX);
                break;
            case 2:
                pesoMedio(arqDados);
                break;
            case 3:
                alturaMedia(arqDados);
                break;
            case 4:
                sexoMaisAlta(arqDados);
                break;
            case 5:
                alturaHomemPesado(arqDados);
                break;
            case 6:
                alturaMulherPesada(arqDados);
                break;
        }
        printf("Deseja finalizar o programa:\n1- Sim\n2- Não\n");
        printf("Selecione sua opção:");
        scanf("%d", &sair);
    }while(sair != 1);
    return 0;
}