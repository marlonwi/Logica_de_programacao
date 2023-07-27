/*Faça um algoritmo para calcular a média aritmética das 3 notas de um aluno e mostrar, além do
valor da média, uma mensagem de "Aprovado", caso a média seja igual ou superior a 6, ou a
mensagem "reprovado", caso contrário. */
#include <stdio.h>

int main()
{
    float n1,n2,n3,media;
    printf("Forneça a primeira nota do aluno:");
    scanf("%f", &n1);
    printf("Forneça a segunda nota do aluno:");
    scanf("%f", &n2);
    printf("Forneça a terceira nota do aluno:");
    scanf("%f", &n3);
    if(n1 >= 0 && n2 >= 0 && n3 >= 0 && n1<=10 && n2<=10 && n3<=10){
        media = (n1+n2+n3)/3;
        if(media >= 6)
        printf("A média do aluno foi %.2f, a situação dele:APROVADO", media);
        else
        printf("A média do aluno foi %.2f, a situação dele:REPROVADO", media);
    }
    else
    printf("Alguma nota informada está incorreta");
    return 0;
}
