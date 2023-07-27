/*
Escrever um programa que gere os 5 primeiros números perfeitos. Um número perfeito é aquele 
que é igual a soma dos seus divisores. (Ex.: 6 = 1+2+3; 28= 1+2+4+7+14 etc).
*/
#include <stdio.h>
int main (){
int i,j,somaDivisores,numPerfeitos = 0;
printf("Os 5 primeiros números perfeitos:\n");
for(i = 2; numPerfeitos < 5; i++){
    somaDivisores = 0;
    for(j = 1; j < i; j++){
        if(i % j == 0){
            somaDivisores += j;
        }
    }
    if(somaDivisores == i){
        printf("%d\n", i);
        numPerfeitos++;
    }
}
return 0;    
}
