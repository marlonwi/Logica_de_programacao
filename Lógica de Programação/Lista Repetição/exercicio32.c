/*
Faça um programa que tenha como entrada a nota de cada um dos alunos de uma turma. Deve 
ser  calculado  e  impresso  o  número  de  alunos  que  tiraram  a  maior  nota  e  o  número  de  alunos  que 
tiraram a segunda maior nota. Imprimir os resultados.
*/
#include <stdio.h>
int main (){
    int numAlunos,contMaior = 0,contSegundaMaior=0,i;
    float nota,maior = 0,segundaMaior = 0;
    printf("Quantos alunos possuem na turma:");
    scanf("%d", &numAlunos);
    for(i=1; i <= numAlunos; i++){
        printf("Insira a nota do %d aluno:", i);
        scanf("%f", &nota);
        while(nota < 0 || nota > 10){
            printf("Não existe nota negativa ou maior que 10!!!\n");
            printf("Insira a nota do %d aluno:", i);
            scanf("%f", &nota);
        }
        if(nota == maior)
            contMaior++;
        else if(nota == segundaMaior)
            contSegundaMaior++;
        else if(nota > maior){
            segundaMaior = maior;
            maior = nota;
            contSegundaMaior = contMaior;
            contMaior = 1;
        }
        else if(nota > segundaMaior){
            segundaMaior = nota;
            contSegundaMaior = 1;
        }
    }
        printf("\nA quantidade de alunos que tiraram %.1f(maior nota) = %d", maior, contMaior);
        printf("\nA quantidade de alunos que tiraram %.1f(segunda maior nota) = %d", segundaMaior, contSegundaMaior);
    return 0;
}