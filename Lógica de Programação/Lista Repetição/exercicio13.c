/*
 Escreva um programa que calcule a média aritmética das 3 notas dos alunos de uma classe. O
programa deverá ler, além das notas, o código do aluno e deverá ser encerrado quando o código for
igual a zero. 
*/
#include <stdio.h>
#include <math.h>
int main()
{
    int codigo;
    float n1, n2, n3;
    do
    {
        printf("Forneça o codigo de um aluno\n");
        printf("ou 0 para encerrar o programa:");
        scanf("%d", &codigo);
           if(codigo != 0){
           printf("Forneça a primeira nota do aluno %d:", codigo);
           scanf("%f", &n1);
           printf("Forneça a segunda nota do aluno %d:", codigo);
           scanf("%f", &n2);
           printf("Forneça a terceira nota do aluno %d:", codigo);
           scanf("%f", &n3);
           while(n1 < 0 || n2 < 0 || n3 < 0){
               printf("Alguma nota foi incorreta, pois não existe nota negativa!!!\n");
               printf("Forneça a primeira nota do aluno %d:", codigo);
               scanf("%f", &n1);
               printf("Forneça a segunda nota do aluno %d:", codigo);
               scanf("%f", &n2);
               printf("Forneça a terceira nota do aluno %d:", codigo);
               scanf("%f", &n3);
           }
           printf("A média das 3 notas do aluno %d = %.2f\n", codigo,(n1+n2+n3)/3);
        }
    }while(codigo != 0);
    return 0;
}