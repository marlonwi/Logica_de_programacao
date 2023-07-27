/*
Escrever  um  programa  que  leia  um  conjunto  de  50  informações  contendo,  cada  uma  delas,  a 
altura  e  o  sexo  de  uma  pessoa  (código=1,  masculino  código=2,  feminino),  calcule  e  mostre  o 
seguinte:  
a) a maior e a menor altura da turma 
b) a média da altura das mulheres 
c) a média da altura da turma. 
d) A maior e a menor altura dos homens
*/
#include <stdio.h>
int main (){
    int sexo,i,contH=0,contM=0;
    float altura,maiorAlt,menorAlt,somaAltMulheres = 0,somaAlt = 0,maiorAltH,menorAltH;
    for(i = 1; i<=50; i++){
        printf("Qual a altura do %d aluno em metros:", i);
        scanf("%f", &altura);
        while(altura < 0){
            printf("Não existe altura negativa!!!!\n");
            printf("Qual a altura do %d aluno em metros:");
            scanf("%f", &altura);
        }
        somaAlt += altura;
        printf("Sendo:\n1 - Masculino\n2 - Feminino\nQual sexo do %d aluno:", i);
        scanf("%d", &sexo);
        while(sexo != 1 && sexo !=2){
            printf("Código inválido!!!!\n");
            printf("Sendo:\n1 - Masculino\n2 - Feminino\nQual sexo do %d aluno:", i);
            scanf("%d", &sexo);
        }
        if(i == 1){
            maiorAlt = altura;
            menorAlt=altura;
        }
        else if(altura > maiorAlt)
            maiorAlt = altura;
        else if(menorAlt < altura)
            menorAlt = altura;
        if(sexo == 2){
        contM++;
        somaAltMulheres += altura;
        }
        else{
            contH++;
            if(contH == 1){
                maiorAltH = altura;
                menorAltH = altura;
            }
            else if(altura > maiorAltH)
                maiorAltH = altura;
            else if(altura < menorAltH)
                menorAltH = altura;
        }
    }
    printf("\nA maior altura da turma = %.1f\nA menor altura da turma = %.1f", maiorAlt, menorAlt);
    if(contM > 0)
    printf("\nA média da altura das mulheres = %.2f", somaAltMulheres/contM);
    printf("\nA média da altura da turma = %.2f", somaAlt/(i-1));
    if(contH > 0)
    printf("\nA maior altura entre os homens = %.1f\nA menor altura entre os homens = %.1f", maiorAltH, menorAltH);
    return 0;
}