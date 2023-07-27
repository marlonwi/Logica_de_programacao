/*
Faça um programa que tenha como entrada a nota de cada um dos alunos de uma turma ( a nota 
é inteira e varia de 0 a 5). 
Calcule e imprima: 
a) A frequência absoluta (número de ocorrências de cada nota); 
b) A frequência relativa (a frequência de cada nota dividida pelo total de alunos)
*/
#include <stdio.h>
int main (){
    int numAlunos,nota,f0=0,f1=0,f2=0,f3=0,f4=0,f5=0,i;
    printf("Quantidade de alunos na sala:");
    scanf("%d", &numAlunos);
    for(i = 1; i <= numAlunos; i++){
        printf("Insira a nota do aluno(0 a 5):");
        scanf("%d", &nota);
        while(nota < 0 || nota >5){
            printf("A nota deve ser de 0 a 5!!!!\n");
            printf("Insira a nota do aluno(0 a 5)");
            scanf("%d", &nota);
        }
        switch (nota)
        {
        case 0:
        f0++;
            break;
        case 1:
        f1++;
            break;
        case 2:
        f2++;
            break;
        case 3:
        f3++;
            break;
        case 4:
        f4++;
            break;
        case 5:
        f5++;
            break;
        }
    }
    printf("Notas\t\tFrequencia absoluta\n0\t\t%d\n1\t\t%d\n2\t\t%d\n3\t\t%d\n4\t\t%d\n5\t\t%d\n", f0, f1, f2, f3, f4, f5);
    printf("Notas\t\tFrequencia relativa\n0\t\t%.2f\n1\t\t%.2f\n2\t\t%.2f\n3\t\t%.2f\n4\t\t%.2f\n5\t\t%.2f\n", (float)f0/numAlunos, (float)f1/numAlunos, (float)f2/numAlunos, (float)f3/numAlunos, (float)f4/numAlunos, (float)f5/numAlunos);
    return 0;
}