/*
 Faça um programa que possua o menu:
1 – Cadastro
2 – Consulta
3 – Excluir
4 – Fim
caso a opção selecionada seja:
1 – Permitir que se cadastre a matrícula, nome e salário de no máximo 30 funcionários.
Obs.:
a) A matrícula é única
b) Aceitar apenas valores positivos para o campo salário
*/
#include <stdio.h>
#include <string.h>
#define MAX 3
typedef struct{
    int matricula;
    char nome[100];
    float salario;
}TFuncionarios;
void retiraEnter(char s[]){
    if (s[strlen(s)-1] == '\n')
        s[strlen(s)-1] = '\0';
}
int validaMatricula(TFuncionarios vF[], int tamanho, int matricula, int ultimaPos){
    int i;
    for(i = 0; i <= ultimaPos; i++){
        if(vF[i].matricula == matricula)
        return i;
    }
    return -1;
}
void cadastroFuncionario(TFuncionarios vF[], int tamanho, int *ultimaPos){
    int sair,matricula;
        if(*ultimaPos < tamanho - 1){
            do{
                 if(*ultimaPos == tamanho - 1)
                printf("\nNúmero máximo de funcionários já atingido!!!\n");
                else{
                    printf("Qual a matricula do funcionário que está sendo cadastrado:");
                    scanf("%d", &matricula);
                    setbuf(stdin, NULL);
                    if(validaMatricula(vF,tamanho,matricula,*ultimaPos) != -1)
                        printf("\nMatricula já cadastrada!!!!\n");
                    else{
                        (*ultimaPos)++;
                        vF[*ultimaPos].matricula = matricula;
                        printf("Qual o nome do funcionário que está sendo cadastrado:");
                        fgets(vF[*ultimaPos].nome, 100, stdin);
                        setbuf(stdin,NULL);
                        retiraEnter(vF[*ultimaPos].nome);
                        printf("Qual o salário do funcionário que está sendo cadastrado:");
                        scanf("%f", &vF[*ultimaPos].salario);
                        setbuf(stdin,NULL);
                        while(vF[*ultimaPos].salario < 0){
                            printf("Não existe salário negativo!!!!");
                            printf("Qual o salário do funcionário que está sendo cadastrado:");
                            scanf("%f", &vF[*ultimaPos].salario);
                            setbuf(stdin,NULL);
                        }
                    }
                }
                    printf("\nDeseja sair da opção de cadastro:\n1- Sim\n2- Não\n");
                    printf("Selecione sua opção:");
                    scanf("%d", &sair);
            }while(sair != 1);
        }
}
void consultaFuncionario(TFuncionarios vF[], int tamanho, int ultimaPos){
    int i;
    if(ultimaPos == -1)
    printf("\nNenhum funcionário cadastrado ainda!!!!\n");
    else{
        printf("Matrícula\t\tNome\t\tSalário");
        for(i = 0; i <= ultimaPos; i++){
            printf("\n%d\t\t\t%s\t\t%.1f\n", vF[i].matricula, vF[i].nome, vF[i].salario);
        }
    }
}
void excluirFuncionario(TFuncionarios vF[], int tamanho, int *ultimaPos){
    int matricula, sair,i;
    if(*ultimaPos == -1)
    printf("\nNenhum funcionário cadastrado ainda!!!!\n");
    else{
        do{
            printf("\nQual a matricula do funcionário que será demitido:\n");
            scanf("%d", &matricula);
            if(validaMatricula(vF, tamanho,matricula, *ultimaPos) == -1)
                printf("Matrícula não encontrada!!!\n");
            else{
                for(i = 0; i <= *ultimaPos; i++){
                    if(vF[i].matricula == matricula){
                    vF[i] = vF[*ultimaPos];
                    (*ultimaPos)--;
                    }
                }
            }
            printf("Deseja sair da opção de excluão:\n1- Sim\n2- Não\n");
            printf("Selecione sua opção:");
            scanf("%d", &sair);
        }while(sair != 1);
    }
    
}
int main (){
    TFuncionarios vFuncionarios[MAX];
    int opcao, ultimaPos = -1;
    do{
        printf("Sendo:\n1- Cadastro\n2- Consulta\n3- Excluir\n4- Sair\n");
        printf("Selecione sua opção:");
        scanf("%d", &opcao);
        switch (opcao){
        case 1:
            cadastroFuncionario(vFuncionarios,MAX,&ultimaPos);
            break;
        case 2:
            consultaFuncionario(vFuncionarios,MAX,ultimaPos);
            break;
        case 3:
            excluirFuncionario(vFuncionarios,MAX,&ultimaPos);
            break;
        default:
            break;
        }
    }while(opcao != 4);
    return 0;
}