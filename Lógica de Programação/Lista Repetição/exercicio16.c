/*
 Escreva um programa que leia o código de um aluno e suas três notas. Calcule a média
ponderada do aluno, considerando que o peso para a maior nota seja 4 e para as duas restantes, 3.
Mostre o código do aluno, suas três notas, a média calculada e uma mensagem "APROVADO" se a
média for maior ou igual a 5 e "REPROVADO" se a média for menor que 5. Repita a operação até
que o código lido seja negativo.   
*/
#include <stdio.h>
#include <math.h>
int main()
{
    int codigo;
    float n1, n2, n3,media;
    do
    {
        printf("Forneça o codigo de um aluno\n");
        printf("ou um número menor que 0 para encerrar o programa:");
        scanf("%d", &codigo);
           if(codigo >= 0){
           printf("Forneça a primeira nota do aluno %d:", codigo);
           scanf("%f", &n1);
           printf("Forneça a segunda nota do aluno %d:", codigo);
           scanf("%f", &n2);
           printf("Forneça a terceira nota do aluno %d:", codigo);
           scanf("%f", &n3);
           while(n1 < 0 || n2 < 0 || n3 < 0){
               printf("Alguma nota foi incorreta, pois nÃ£o existe nota negativa!!!\n");
               printf("Forneça a primeira nota do aluno %d:", codigo);
               scanf("%f", &n1);
               printf("Forneça a segunda nota do aluno %d:", codigo);
               scanf("%f", &n2);
               printf("Forneça a terceira nota do aluno %d:", codigo);
               scanf("%f", &n3);
           }
           if(n1 > n2 && n1 > n3)
           media = (n1 * 4 + n2 * 3 + n3 * 3)/10;
           else if(n2 > n3)
           media = (n1 * 3 + n2 * 4 + n3 * 3)/10;
           else
           media = (n1 * 3 + n2 * 3 + n3 * 4)/10;
           if(media >= 5)
           printf("A média das 3 notas do aluno %d = %.2f\nAPROVADO!!!\n", codigo,media);
           else
           printf("A média das 3 notas do aluno %d = %.2f\nREPROVADO!!!\n", codigo,media);
        }
    }while(codigo >= 0);
    return 0;
}