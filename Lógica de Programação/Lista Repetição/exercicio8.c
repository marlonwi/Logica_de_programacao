/*
Faça um programa que leia um conjunto de 50 informações contendo, cada uma delas, a altura e
o sexo de uma pessoa (código=1, masculino código=2, feminino), calcule e mostre o seguinte:
a) a maior e a menor altura da turma;
b) a média da altura das mulheres;
c) a média da altura da turma;
d) A maior e a menor altura dos homens.
*/
#include <stdio.h>
#include <math.h>
int main()
{
    int i, sexo,numMulheres=0;
    float soma = 0, somaHomens=0, altura, maior, menor, somaMulheres=0;
    const int QNTD = 50;
    for(i = 1;i <= QNTD; i++){
           printf("Sendo:\n1 - Masculino\n2 - Feminino\nForneça o sexo do %d aluno(a):", i);
           scanf("%d", &sexo);
           while(sexo <= 0 || sexo > 2){
               printf("Código inválido!!!!\n");
               printf("Sendo:\n1 - Masculino\n2 - Feminino\nForneça o sexo do %d aluno(a):", i);
               scanf("%d", &sexo);
           }
           printf("Forneça a altura em metros do aluno(a):");
           scanf("%f", &altura);
           while(altura <= 0){
               printf("Não exite altura negativa!!!!\n");
               printf("Forneça a altura em metros do aluno(a):");
               scanf("%f", &altura);
           }
           soma = soma + altura;
              if(sexo == 1){
                  if(somaHomens == 0){
                      maior = altura;
                      menor = altura;
                  }
                  else{
                      if(altura > maior)
                      maior = altura;
                      else if(altura < menor)
                      menor = altura;
                  }
                  somaHomens += altura;
              }
              else{
                  numMulheres++;
                  somaMulheres += altura;
              }
    }
    printf("\nA média de altura da turma = %2.fm", soma/QNTD);
    if(numMulheres > 0)
       printf("\nA média de altura das mulheres turma = %2.fm", somaMulheres/numMulheres);
    if(somaHomens > 0){
       printf("\nO maior homem da turma possui = %2.fm de altura", maior);
       printf("\nO menor homem da turma = %2.fm de altura", menor);
    }
    return 0;
}