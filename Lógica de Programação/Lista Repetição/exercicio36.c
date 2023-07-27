/*
Faça  um  programa  que  mostre  os  conceitos  finais  dos  alunos  de  uma  classe  de  75  alunos, 
considerando: 
a) os dados de cada aluno (número de matrícula e nota numérica final) serão fornecidos pelo 
usuário; 
b) a tabela de conceitos segue abaixo: 
Nota    Conceito 
de 0,0 a 4,9   D 
de 5,0 a 6,9   C 
de 7,0 a 8,9   B 
de 9,0 a 10,0    A 
*/
#include <stdio.h>
int main (){
    int i,matricula;
    float notaFinal;
    for(i=1; i <= 5; i++){
        printf("Forneça a matrícula do aluno:");
        scanf("%d", &matricula);
        printf("Forneça a nota final do aluno:");
        scanf("%f", &notaFinal);
        while(notaFinal < 0 || notaFinal > 10){
            printf("Não existe nota negativa ou maior que 10!!!!\n");
            printf("Forneça a nota final do aluno:");
            scanf("%f", &notaFinal);
        }
        if(notaFinal < 5)
        printf("Matricula\t\tNota Final\t\tConceito\n%d\t\t\t%d\t\t\tD\n",matricula, notaFinal);
        else if(notaFinal < 7)
        printf("Matricula\t\tNota Final\t\tConceito\n%d\t\t\t%d\t\t\tC\n",matricula, notaFinal);
        else if(notaFinal < 9)
        printf("Matricula\t\tNota Final\t\tConceito\n%d\t\t\t%d\t\t\tB\n",matricula, notaFinal);
        else
        printf("Matricula\t\tNota Final\t\tConceito\n%d\t\t\t%d\t\t\tA\n",matricula, notaFinal);
    }
    return 0;
}