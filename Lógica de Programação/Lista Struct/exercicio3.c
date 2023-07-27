/*
Faça um programa que mostre  o menu:
1 – Cadastro de Departamento
2 -  Cadastro de Funcionários
3 – Consulta de Funcionários
4 – Funcionários de um Departamento
5 – Excluir Funcionário
6 – Excluir Departamento
7 – Fim
Caso a opção selecionada seja;
Cadastro de Departamento; cadastrar o código, nome e sigla de no máximo 20 departamentos. O 
código é único e o nome não pode ser vazio.
Cadastro de Funcionários; cadastrar a matrícula, nome, data de nascimento, cpf, salário e código de 
departammento de no máximo 1000 funcionários.
Obs.; 
a) A matrícula é única;
b) O nome não pode ser vazio;
c) Validar a data de nascimento e cpf;
d) O salário deve ser maior que zero;
e) Aceitar para o campo código do departamento apenas departamentos já cadastrados.
Consulta de Funcionários: mostrar a matrícula, nome e nome do departamentos dos funcionários que 
tenham o nome com um determinado prefixo.
Funcionários   de   um   Departamento:   mostrar   os   dados   dos   funcionários   pertencentes   a   um 
determinado departamento.
Excluir Funcionário: excluir um funcionário a partir de sua matrícula.
Excluir Departamento:   excluir   um   departamento   a   partir   de   seu   código   bem   como   todos   os 
funcionários pertencentes ao departamento excluído.
*/
#include <stdio.h>
#include <string.h>
#define MAX_DEP 20
#define MAX_FUNC 1000
typedef struct{
    int codDep;
    char nome[100],sigla[10];
}TDepartamentos;
typedef struct{
    int matricula, dataNascimento[3], dep, cpf;
    char nome[100];
    float salario;
}TFuncionarios;
void retiraEnter(char s[]){
    if (s[strlen(s)-1] == '\n')
        s[strlen(s)-1] = '\0';
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
int validaMatricula(TFuncionarios vF[],int tamanho, int ultimaPosFunc, int matricula){
    int i;
    for(i = 0; i <= ultimaPosFunc; i++){
        if(matricula == vF[i].matricula)
            return i;
    }
    return -1;
}
int validaDep(TDepartamentos vD[], int tamanho, int ultimaPosDep, int codDep){
    int i;
    for(i = 0; i <= ultimaPosDep; i++){
        if(vD[i].codDep == codDep)
        return i;
    }
    return -1;
}
int validaNome(char s[]){
    int i = 0;
    if(s[i] == '\n')
        return -1;
    return 1;
}
void cadastroDep(TDepartamentos vD[], int tamanho, int *ultimaPosDep){
    int codDep,sair,valida;
    do{
        if(*ultimaPosDep < tamanho -1){
            printf("Forneça o código do departamento que será cadastrado:");
            scanf("%d", &codDep);
            setbuf(stdin,NULL);
            if(validaDep(vD,tamanho,*ultimaPosDep,codDep) == -1){
                (*ultimaPosDep)++;
                vD[*ultimaPosDep].codDep = codDep;
                do{
                    printf("Forneça o nome do departamento cadastrado:");
                    fgets(vD[*ultimaPosDep].nome, 100, stdin);
                    setbuf(stdin,NULL);
                    valida = validaNome(vD[*ultimaPosDep].nome);
                    if(valida == -1)
                        printf("\nNão existe nome sem nenhum caractere!!!\n");
                    retiraEnter(vD[*ultimaPosDep].nome);
                    }while(valida == -1);
                printf("Digite a sigla do departamento cadastrado:");
                fgets(vD[*ultimaPosDep].sigla, 10, stdin);
                setbuf(stdin,NULL);
                retiraEnter(vD[*ultimaPosDep].sigla);
                }
            else
                printf("\nCódigo de departamento já cadastrado!!!\n");
            }
        else
            printf("\nLimite de departamentos cadastrados atingido!!!\n");
        printf("Deseja sair da opção cadastro de departamento:\n");
        printf("1- Sim\n2- Não\n");
        printf("Selecione sua opção:");
        scanf("%d", &sair);
        setbuf(stdin,NULL);
    }while(sair != 1);
}
void cadastroFunc(TFuncionarios vF[], int tamanhoFunc, int *ultimaPosFunc,TDepartamentos vD[], int tamanhoDep, int ultimaPosDep){
    int sair,matricula,valNome,data[3],valData,codigoDep,valDep,i;
    if(ultimaPosDep == -1)
        printf("\nNenhum departamento cadastrado!!!!\n");
    else{
        do{
            if(*ultimaPosFunc == tamanhoFunc -1){
                printf("\nLimite máximo de funcionários atingido!!!!\n");
                sair = 1;
            }
            else{
                printf("Forneça a matrícula do funcionário:");
                scanf("%d", &matricula);
                setbuf(stdin,NULL);
                if(validaMatricula(vF,tamanhoFunc,*ultimaPosFunc,matricula) == -1){
                    (*ultimaPosFunc)++;
                    vF[*ultimaPosFunc].matricula = matricula;
                    do{
                        printf("Qual o nome do funcionario:");
                        fgets(vF[*ultimaPosFunc].nome, 100, stdin);
                        setbuf(stdin,NULL);
                        valNome = validaNome(vF[*ultimaPosFunc].nome);
                        retiraEnter(vF[*ultimaPosFunc].nome);
                        if(valNome == -1)
                        printf("\nNão existe nome sem nenhum caractere!!!\n");
                    }while(valNome == -1);
                    do{
                        printf("Forneça a data de nascimento do funcionário(dd/mm/aaaa):");
                        scanf("%d/%d/%d", &data[1], &data[2], &data[3]);
                        setbuf(stdin,NULL);
                        valData = validaData(data[1], data[2], data[3]);
                        if(valData == -1)
                            printf("\nData incorreta!!!\n");
                    }while(valData == -1);
                    vF[*ultimaPosFunc].dataNascimento[0] = data[1];
                    vF[*ultimaPosFunc].dataNascimento[1] = data[2];
                    vF[*ultimaPosFunc].dataNascimento[2] = data[3];
                    //printf("Forneça o cpf do funcionário(xxxxxxxxxxx):");
                    //scanf("%d", &vF[*ultimaPosFunc].cpf);
                    //setbuf(stdin,NULL);
                    do{
                        printf("Forneça o salário do funcionário:");
                        scanf("%f", &vF[*ultimaPosFunc].salario);
                        setbuf(stdin,NULL);
                    }while(vF[*ultimaPosFunc].salario <= 0);
                    do{
                        printf("Sendo os seguintes departamentos:\nCódigo\t\t\tDepartamento\t\t\tSigla\n");
                        for(i = 0; i <= ultimaPosDep; i++){
                            printf("%d\t\t\t%s\t\t\t%s\n", vD[i].codDep, vD[i].nome, vD[i].sigla);
                        }
                        printf("Selecione o departamento do funcionário:");
                        scanf("%d", &codigoDep);
                        setbuf(stdin,NULL);
                        valDep = validaDep(vD, tamanhoDep, ultimaPosDep, codigoDep);
                        if(valDep == -1)
                            printf("\nDepartamento inexistente!!!\n");
                    }while(valDep == -1);
                    vF[*ultimaPosFunc].dep = codigoDep;
                }
                else
                    printf("\nMatrícula já cadastrada!!!\n");
            printf("Deseja sair do cadastro de funcionários:\n1- Sim\n 2- Não\n");
            printf("Selecione sua opção:");
            scanf("%d", &sair);
            setbuf(stdin,NULL);
            }
        }while(sair != 1);
    }
}
void consultaFunc(TFuncionarios vF[], int tamanhoFunc, int ultimaPosFunc, TDepartamentos vD[], int tamanhoDep, int ultimaPosDep){
    char prefixo[50];
    int i,codDep,str,matricula;
    setbuf(stdin,NULL);
    printf("Forneça um prefixo a ser consultado:");
    fgets(prefixo, 50, stdin);
    setbuf(stdin,NULL);
    retiraEnter(prefixo);
    printf("Matrícula\t\tNome\n");
    for(i = 0; i <= ultimaPosFunc; i++){
        str = strncmp(vF[i].nome, prefixo, strlen(prefixo));
        if(str == 0)
        //matricula = vF[i].dep;
        //printf("\n%d\n", matricula);
        //codDep = validaDep(vD,tamanhoDep,ultimaPosDep,matricula);
        printf("%d\t\t\t%s\n", vF[i].matricula, vF[i].nome);
    }
}
void funcionariosDep(TFuncionarios vF[], int tamanhoFunc, int ultimaPosFunc, TDepartamentos vD[], int tamanhoDep, int ultimaPosDep){
    int codDep,dep,i;
    printf("Forneça o código do departamento a ser consultado:");
    scanf("%d", &codDep);
    dep = validaDep(vD,tamanhoDep,ultimaPosDep,codDep);
    if(dep == -1)
        printf("\nDepartamento não encontrado!!!\n");
    else{
        printf("Departamento:\n Código\t\tNome\t\t\tSigla\n%d\t\t\t%s\t\t\t%s\n", vD[dep].codDep, vD[dep].nome, vD[dep].sigla);
        printf("Funcionários:\nMatrícula\t\tNome\t\tData de nascimento\t\tSalário\n");
        for(i = 0; i <= ultimaPosFunc; i++){
            if(codDep == vF[i].dep){
                printf("%d\t\t\t%s\t\t\t%d/%d/%d\t\t\t%.2f\n", vF[i].matricula, vF[i].nome, vF[i].dataNascimento[0], vF[i].dataNascimento[1], vF[i].dataNascimento[2], vF[i].salario);
            }
        }
    }
}
void excluirFunc(TFuncionarios vF[], int tamanhoFunc, int *ultimaPosFunc){
    int i, matricula,func;
    printf("Forneça a matricula do funcionário que será excluido:");
    scanf("%d", &matricula);
    func = validaMatricula(vF, tamanhoFunc, *ultimaPosFunc, matricula);
    if(func == -1)
        printf("\nMatricula não encontrada!!!\n");
    else{
        if(func == *ultimaPosFunc)
            (*ultimaPosFunc)--;
        else{
            vF[func] = vF[*ultimaPosFunc];
            (*ultimaPosFunc)--;
        }
    }
}
void excluirDep(TDepartamentos vD[], int tamanhoDep, int *ultimaPosDep,TFuncionarios vF[], int tamanhoFunc, int *ultimaPosFunc){
    int codDep,dep,i;
    printf("Forneça o código do departamento que será excluido:");
    scanf("%d", &codDep);
    dep = validaDep(vD, tamanhoDep, *ultimaPosDep, codDep);
    if(dep == -1)
        printf("\nDepartamento não encontrado!!!!\n");
    else{
        if(dep == *ultimaPosDep)
            (*ultimaPosDep)--;
        else{
            vD[dep] = vD[*ultimaPosDep];
            (*ultimaPosDep)--;
        }
        for(i = 0; i <= *ultimaPosFunc; i++){
            if(codDep == vF[i].dep){
                if(i == *ultimaPosFunc)
                    (*ultimaPosFunc)--;
                else{
                    do{
                    vF[i] = vF[*ultimaPosFunc];
                    (*ultimaPosFunc)--;
                    }while(vF[i].dep == codDep || i < *ultimaPosFunc);
                }
            }
        }
    }
}
int main(){
    TDepartamentos vDepartamentos[MAX_DEP];
    TFuncionarios vFuncionarios[MAX_FUNC];
    int ultimaPosDep = -1,ultimaPosFunc =-1,opcao,sair;
    do{
        printf("Sendo:\n1 - Cadastro de Departamento\n2 - Cadastro de Funcionários\n3 - Consulta de Funcionários\n");
        printf("4 - Funcionários de um Departamento\n5 - Excluir Funcionário\n6 - Excluir Departamento\n");
        printf("Selecione sua opção:");
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
                cadastroDep(vDepartamentos,MAX_DEP,&ultimaPosDep);
                break;
            case 2:
                cadastroFunc(vFuncionarios,MAX_FUNC,&ultimaPosFunc,vDepartamentos,MAX_DEP,ultimaPosDep);
                break;
            case 3:
                consultaFunc(vFuncionarios,MAX_FUNC,ultimaPosFunc,vDepartamentos,MAX_DEP,ultimaPosDep);
                break;
            case 4:
                funcionariosDep(vFuncionarios,MAX_FUNC,ultimaPosFunc,vDepartamentos,MAX_DEP,ultimaPosDep);
                break;
            case 5:
                excluirFunc(vFuncionarios,MAX_FUNC,&ultimaPosFunc);
                break;
            case 6:
                excluirDep(vDepartamentos,MAX_DEP,&ultimaPosDep,vFuncionarios,MAX_FUNC,&ultimaPosFunc);
                break;
        }
        printf("Deseja finalizar o programa:\n1- Sim\n2- Não\n");
        printf("Selecione sua opção:");
        scanf("%d", &sair);
    }while(sair != 1);
    return 0;
}