/*Faça um algoritmo que dada a idade de um nadador classifica-o em uma das seguintes categorias:
infantil A = 5 - 7 anos
infantil B = 8-10 anos
juvenil A = 11-13 anos
juvenil B = 14-17 anos
adulto = maiores de 18 anos*/
#include <stdio.h>

int main()
{
    int idade;
    printf("Forneça a idade do nadador:");
    scanf("%d", &idade);
    if (idade >=5){
        if(idade >=5 && idade <=7)
        printf("Categoria: infantil A");
        else if(idade >=8 && idade <=10)
        printf("Categoria: infantil B");
        else if(idade >=11 && idade <=13)
        printf("Categoria: juvenil A");
        else if(idade >=14 && idade <=17)
        printf("Categoria: juvenil B");
        else
        printf("Categoria: adulto");
    }
    else
    printf("Nadadores com menos de 5 anos não pode competir!!!!");
    return 0;
}

