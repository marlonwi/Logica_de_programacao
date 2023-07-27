/*
   Faça um programa que leia a, b, c, d, e que constituem o gabarito de uma prova de 5 questões. 
Leia, a seguir, um número não determinado de conjuntos de 6 valores num, a1, b1, c1, d1, e1 onde 
num é o número do aluno e os demais valores são as respostas dos alunos às 5 questões. Conte o 
número de acertos e multiplique por 2. Escrever, para cada aluno, o seu número e a sua nota.       
*/
#include <stdio.h>
#include <math.h>
int main()
{
    int aluno, i, cont=0;
    char resp1, resp2, resp3, resp4 ,resp5, respAluno;
    for(i = 1; i <= 5; i++){
        switch(i){
            case 1:
            printf("Qual o gabarito da questão %d:", i);
            scanf(" %c" , &resp1);
            while(resp1 != 'a' && resp1 != 'b' && resp1 != 'c' && resp1 != 'd' && resp1 != 'e'){
                printf("A resposta deve estar dentro das opções(a,b,c,d,e)\n");
                printf("Qual o gabarito da questão %d:", i);
                scanf(" %c" , &resp1);
            }
            break;
            case 2:
            printf("Qual o gabarito da questão %d:", i);
            scanf(" %c" , &resp2);
            while(resp2 != 'a' && resp2 != 'b' && resp2 != 'c' && resp2 != 'd' && resp2 != 'e'){
                printf("A resposta deve estar dentro das opções(a,b,c,d,e)\n");
                printf("Qual o gabarito da questão %d:", i);
                scanf(" %c" , &resp2);
            }
            break;
            case 3:
            printf("Qual o gabarito da questão %d:", i);
            scanf(" %c" , &resp3);
            while(resp3 != 'a' && resp3 != 'b' && resp3 != 'c' && resp3 != 'd' && resp3 != 'e'){
                printf("A resposta deve estar dentro das opções(a,b,c,d,e)\n");
                printf("Qual o gabarito da questão %d:", i);
                scanf(" %c" , &resp3);
            }
            break;
            case 4:
            printf("Qual o gabarito da questão %d:", i);
            scanf(" %c" , &resp4);
            while(resp4 != 'a' && resp4 != 'b' && resp4 != 'c' && resp4 != 'd' && resp4 != 'e'){
                printf("A resposta deve estar dentro das opções(a,b,c,d,e)\n");
                printf("Qual o gabarito da questão %d:", i);
                scanf(" %c" , &resp1);
            }
            break;
            case 5:
            printf("Qual o gabarito da questão %d:", i);
            scanf(" %c" , &resp5);
            while(resp5 != 'a' && resp5 != 'b' && resp5 != 'c' && resp5 != 'd' && resp5 != 'e'){
                printf("A resposta deve estar dentro das opções(a,b,c,d,e)\n");
                printf("Qual o gabarito da questão %d:", i);
                scanf(" %c" , &resp5);
            }
            break;
        }
        
        
    }
    do
    {
        printf("Forneça o código do aluno, ou 0 para finalizar a execução:");
        scanf("%d", &aluno);
        while(aluno < 0){
            printf("Não existe código de aluno negativo!!!\n");
            printf("Forneça o código do aluno, ou 0 para finalizar a execução:");
            scanf("%d", &aluno);
        }
        if(aluno != 0){
            for(i=1; i <= 5; i++){
            printf("Resposta do aluno %d na questão %d :", aluno, i);
            scanf(" %c", &respAluno);
            while(respAluno != 'a' && respAluno != 'b' && respAluno != 'c' && respAluno != 'd' && respAluno != 'e'){
                printf("A resposta deve estar dentro das opções(a,b,c,d,e)\n");
                printf("Resposta do aluno na %d questão:", i);
                scanf(" %c", &respAluno);
            }
                switch(i){
                case 1:
                if(resp1 == respAluno)
                    cont++;
                    break;
                    case 2:
                if(resp2 == respAluno)
                    cont++;
                    break;
                    case 3:
                if(resp3 == respAluno)
                    cont++;
                    break;
                    case 4:
                if(resp4 == respAluno)
                    cont++;
                    break;
                    case 5:
                if(resp5 == respAluno)
                    cont++;
                    break;
                    default:
                    break;
                }
            }
        }
                printf("Número de acertos do aluno %d = %d\nNota = %d\n", aluno, cont, cont * 2);
                cont = 0;
    }while(aluno != 0);
    return 0;
}