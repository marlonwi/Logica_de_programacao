/*
Faça um programa que leia um vetor G de 20 elementos inteiros que representa o gabarito de uma
prova, com as opções 1, 2, 3, 4 e 5. A seguir, para cada um dos 50 alunos da turma, leia a
matrícula(que é única), o nome e as respostas de cada questão e conte o número de acertos. Mostre
o no final da entrada de dados o número acertos de cada aluno e uma mensagem APROVADO, se a
nota for maior ou igual a 12; e mostre uma mensagem de REPROVADO, caso contrário.
Obs. Validar as opções de respostas, tanto do gabarito como das respostas dos alunos.
*/
#include <stdio.h>
#include <string.h>
#define TAM 50
int main (){
    int matricula[TAM] = {0},gabarito[20], respostas[20], contAcertos=0,i,j,acertos[TAM];
    for(i=0; i < 20; i++){
        printf("Forneça o gabarito da %d questão:", i+1);
        scanf("%d", &gabarito[i]);
        setbuf(stdin,NULL);
        while (gabarito[i] < 0 || gabarito[i] > 5){
            printf("A resposta informada não está dentro das alternativas(1,2,3,4,5)!!!\n");
            printf("Forneça o gabarito da %d questão:", i+1);
            scanf("%d", &gabarito[i]);
            setbuf(stdin,NULL);
        }
    }
    for(i = 0; i < TAM; i++){
        printf("Forneça a matricula(deve ser maior que 0):");
        scanf("%d", &matricula[i]);
        setbuf(stdin,NULL);
        while(matricula[i] <= 0){
            printf("Valor menor ou igual a 0 informado!!!\n");
            printf("Forneça a matricula(deve ser maior que 0):");
            scanf("%d", &matricula[i]);
            setbuf(stdin,NULL);
        }
        for(j = 0; j < TAM; j++){
            if(matricula[i] == matricula[j] && i != j){
                printf("Matricula já foi cadastrada antes!!!\n");
                printf("Forneça a matricula(deve ser maior que 0):");
                scanf("%d", &matricula[i]);
                setbuf(stdin,NULL);
                while(matricula[i] <= 0){
                printf("Valor menor ou igual a 0 informado!!!\n");
                printf("Forneça a matricula(deve ser maior que 0):");
                scanf("%d", &matricula[i]);
                setbuf(stdin,NULL);
              }
                j = 0;
            }
        }
        for(j = 0; j < 20; j++){
            printf("Forneça a resposta da %d questão:", j+1);
            scanf("%d", &respostas[j]);
            while(respostas[j] < 0 || respostas[j] > 5){
                printf("A resposta informada não está dentro das alternativas(1,2,3,4,5)!!!\n");
                printf("Forneça a resposta da %d questão:", j+1);
                scanf("%d", &respostas[j]);
                setbuf(stdin,NULL);
            }
            if(respostas[j] == gabarito[j])
            contAcertos++;
        }
        acertos[i] = contAcertos;
        contAcertos = 0;
    }
    printf("Matrícula\tAcertos\t\tSituação\n");
    for(i = 0; i < TAM; i++){
        printf("%d\t\t%d\t\t", matricula[i], acertos[i]);
        if(acertos[i] >= 12)
        printf("APROVADO\n");
        else
        printf("REPROVADO\n");
    }
    return 0;
}