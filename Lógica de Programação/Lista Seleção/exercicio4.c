/*Faça um algoritmo que leia as três notas de uma aluno. Calcular a média ponderada do aluno, 
considerando que o peso para a maior nota seja 4 e para as duas restantes, 3. Mostrar a média 
calculada e uma mensagem "APROVADO" se a média for maior ou igual a 5 e "REPROVADO" se 
a média for menor que 5. 
*/
#include <stdio.h>
int main(){
    float n1,n2,n3,mp;
       printf("Forneça a primeira nota:");
       scanf("%f", &n1);
       printf("Forneça a segunda nota:");
       scanf("%f", &n2);
       printf("Forneça a terceira nota:");
       scanf("%f", &n3);
          if(n1>n2 && n1>n3)
          mp=(n1*4+n2*3+n3*3)/10;
          else if(n2>n1 && n2>n3)
          mp=(n1*3+n2*4+n3*3)/10;
          else
          mp=(n1*3+n2*3+n3*4)/10;
            printf("Média =%.1f\n", mp); 
            if(mp>=5)
            printf("APROVADO!!!");
            else
            printf("REPROVADO!!!");
    return 0;
}