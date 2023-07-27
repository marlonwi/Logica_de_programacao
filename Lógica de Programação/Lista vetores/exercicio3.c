/*
Fazer um programa que: 
a)  leia um conjunto de valores correspondentes a 80 notas dos alunos de uma turma (de 
0 a 10); 
b) calcule a freqüência absoluta e a freqüência relativa de cada nota; 
c) imprima uma tabela contendo os valores das notas (de 0 a 10) e suas respectivas 
freqüências absoluta e relativa. 
Observações: 
 freqüência absoluta de uma nota é o número de vezes que ela aparece no conjunto de 
dados; 
 freqüência relativa é a freqüência absoluta dividida pelo número total de dados;
 utilizar como variável composta somente aquelas que forem necessárias.
*/
#include <stdio.h>
#define TAM 80
int calculandoFrequencias(int nota,int v[]){
    int i,cont;
    cont = 0;
    for(i = 0; i < TAM; i++){
        if(v[i] == nota)
        cont++;
    }
    return cont;
}
int main (){
    int vNotas[TAM],frequenciaAbs,i;
    for(i = 0; i < TAM; i++){
        printf("Informe a %d nota(0 a 10):", i+1);
        scanf("%d", &vNotas[i]);
        while(vNotas[i] < 0 || vNotas[i] > 10){
            printf("Nota negativa ou maior que 10 não existe!!!\n");
            printf("Informe a %d nota(0 a 10):", i+1);
            scanf("%d", &vNotas[i]);
        }
    }
    printf("\nNota\t\tFrequencia absoluta\t\tFrequencia relativa\n");
    for(i = 0; i < 11; i++){
        frequenciaAbs = calculandoFrequencias(i,vNotas);
        printf("%d\t\t%d\t\t\t\t%d\n",i,frequenciaAbs, frequenciaAbs/TAM);
    }
    return 0;
}