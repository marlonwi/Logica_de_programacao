/*
Para a eleição do Diretório Acadêmico, inscreveram-se 20 chapas. Cada chapa é descrita pelos 
seguintes dados:
• Nome da chapa (é único)
• Nome do responsável
• Número de votos (inicialmente igual a zero)
Construa um programa que permita:
a) O cadastro das chapas.
b) Ler os votos alunos. Para cada voto lido, some 1 ao número de votos da chapa correspondente.
c) Após a leitura dos votos, exiba no vídeo o nome da chapa, o nome do responsável e o número
 de votos da chapa campeã. Caso tenha ocorrido empate, exiba a mensagem Chapas empatadas
 com n votos, sendo n o número de votos.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    char nomeChapa[100], nomeResponsavel[100];
    int contVotos,codChapa;
}TChapa;
typedef struct{
    int codEleitor, voto;
}TVotos;
void retiraEnter(char *s){
    int t = strlen(s);
    if(s[t-1]=='\n')
       s[t-1]='\0';
}
int validaNome(FILE *c, char *s){
    TChapa vC;
    int pos = 0;
    rewind(c);
    while(fread(&vC, sizeof(TChapa), 1, c) == 1){
        if(strcmp(vC.nomeChapa, s) == 0)
            return pos;
        else
            pos++;
    }
    return -1;
}
int validaVoto(FILE *c, int voto){
    TChapa vC;
    int pos = 0;
    rewind(c);
    while(fread(&vC, sizeof(TChapa), 1, c) == 1){
        if(vC.codChapa == voto){
            vC.contVotos++;
            fseek(c, -sizeof(TChapa), SEEK_CUR);
            fwrite(&vC, sizeof(TChapa), 1, c);
            return pos;
        }
        else
            pos++;
    }
    return -1;
}
void cadastroChapa(FILE *arqC){
    TChapa vC;
    int sair;
    char nCh[100];
    fseek(arqC, 0, SEEK_END);
    vC.codChapa=ftell(arqC)/sizeof(TChapa);
    do{
        vC.codChapa++;
        printf("Forneça o nome da chapa:");
        setbuf(stdin, NULL);
        fgets(nCh, 100, stdin);
        retiraEnter(nCh);
        setbuf(stdin, NULL);
        if(validaNome(arqC, nCh) != -1)
            printf("\nNome de chapa já cadastrado!!!\n");
        else{
            strcpy(vC.nomeChapa, nCh);
            printf("Forneça o nome do responsável pela chapa:");
            fgets(vC.nomeResponsavel, 100, stdin);
            retiraEnter(vC.nomeResponsavel);
            setbuf(stdin, NULL);
            vC.contVotos = 0;
            fseek(arqC, 0, SEEK_END);
            fwrite(&vC, sizeof(TChapa), 1, arqC);
        }
        printf("Deseja sair da opção cadastro de chapa:\n1- Sim\n2-Não\n");
        printf("Selecione sua opção:");
        scanf("%d", &sair);
        setbuf(stdin, NULL);
    }while(sair != 1);
}
void cadastroVoto(FILE *arqC, FILE *arqV){
    TChapa vC;
    TVotos vV;
    int sair, pos;
    fseek(arqV,0,SEEK_END);
    vV.codEleitor=ftell(arqV)/sizeof(TVotos);
    fseek(arqC, 0, SEEK_END);
    if(ftell(arqC)/sizeof(TChapa) == 0){
        printf("\nNenhuma chapa cadastrada!!!\n");
        sair = 1;
    }
    else{
        do{
            vV.codEleitor++;
            do{
                printf("\nChapas cadastradas:\n");
                printf("Código\t\tNome Chapa\n");
                rewind(arqC);
                while(fread(&vC, sizeof(TChapa), 1, arqC) == 1)
                    printf("%d\t\t%s\n", vC.codChapa, vC.nomeChapa);
                printf("Digite o código da chapa em que quer votar:");
                scanf("%d", &vV.voto);
                pos = validaVoto(arqC, vV.voto);
                if(pos == -1)
                    printf("\nChapa inexistente!!!\n");
            }while(pos == -1);
            printf("Deseja sair do cadastro de votos:\n1- Sim\n2- Não\n");
            printf("Selecione sua opção:");
            scanf("%d", &sair);
        }while(sair != 1);
    }
}
void resultadoChapa(FILE *arqC){
    TChapa vC;
    int maior = 0,empate = 0;
    printf("\nCódigo\t\t\tNome\t\t\tNome Representante\t\t\tVotos\n");
    rewind(arqC);
    while(fread(&vC, sizeof(TChapa), 1, arqC) == 1){
        printf("%d\t\t\t%s\t\t\t%s\t\t\t\t\t%d\n", vC.codChapa, vC.nomeChapa, vC.nomeResponsavel, vC.contVotos);
        if(vC.contVotos > maior){
            maior = vC.contVotos;
            empate = 0;
        }
        else if(vC.contVotos == maior)
            empate = 1;
    }
    if(empate == 1)
        printf("Ocorreu empate:\n");
    else
        printf("Vencedor:\n");
    printf("Código\t\t\tNome\t\t\tNome Representante\t\t\tVotos\n");
    rewind(arqC);
    while(fread(&vC, sizeof(TChapa), 1, arqC) == 1){
        if(vC.contVotos == maior)
            printf("%d\t\t\t%s\t\t\t%s\t\t\t\t\t%d\n", vC.codChapa, vC.nomeChapa, vC.nomeResponsavel, vC.contVotos);
    }
        
}
int main (){
    FILE *arqChapa, *arqVotos;
    int opcao,sair;
    arqChapa = fopen("chapa.dat", "rb+");
    if(!arqChapa)
        arqChapa = fopen("chapa.dat", "wb+");
    arqVotos = fopen("votos.dat", "rb+");
    if(!arqVotos)
        arqVotos = fopen("votos.dat", "wb+");
    do{
        printf("Sendo:");
        printf("\n1- Cadastro chapa\n2- Cadastro votos");
        printf("\n3- Resultado\nSelecione sua opção:");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            cadastroChapa(arqChapa);
            break;
        case 2:
            cadastroVoto(arqChapa, arqVotos);
            break;
        case 3:
            resultadoChapa(arqChapa);
            break;
        }
        printf("Deseja encerrar o programa:\n1- Sim\n2- Não");
        printf("\nSelecione sua opção");
        scanf("%d", &sair);
    }while(sair != 1);
    return 0;
}