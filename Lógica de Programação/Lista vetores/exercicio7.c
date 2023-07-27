/*
Faça um programa que tenha como entrada 2 vetores X(10) e Y(10). Criar, a seguir, um 
vetor Z que seja 
a) a união de X com Y; 
b) a diferença entre X e Y; 
c) a soma entre X e Y; 
d) o produto entre X e Y; 
e) a intersecção entre X e Y. 
Escreva o vetor Z a cada cálculo.
*/
#include <stdio.h>
#define TAM 10
void uniaoVetores(int vX[], int vY[]){
    int i,j,pos=0,igual,vZ[2*TAM];
    printf("\nA uniao do vetor x e y formou o vetor z\n");
    for(i = 0; i < TAM; i++){
        vZ[pos] = vX[i];
        printf("%d\t");
        pos++;
    }
    for(i=0; i < TAM; i++){
        igual = 0;
        for(j = 0; j < pos; j++){
            if(vY[i] == vZ[j])
            igual = 1;
        }
        if(igual = 0){
            pos++;
            vZ[pos] = vY[i];
        }
    }
}
void diferencaVetores(int vX[], int vY[]){
    int i,j,pos=0,vZ[2*TAM];
    printf("\nA diferença do vetor x e y formou o vetor z\n");
    for(i = 0; i < TAM; i++){
        for(j = 0; j < TAM; j++){
            if(vX[i] != vY[j]){
                vZ[pos] = vX[i];
                printf("%d\t", vZ[pos]);
                pos++;
            }
        }
    }
}
void somaVetores(int vX[], int vY[]){
    int i,vZ[2*TAM];
    printf("\nA soma do vetor x e y formou o vetor z\n");
    for (i = 0; i < TAM; i++){
        vZ[i] = vX[i] + vY[i];
        printf("%d\t", vZ[i]);
    }
    
}
void produtoVetores(int vX[], int vY[]){
    int i,vZ[2*TAM];
    printf("\nO produto do vetor x e y formou o vetor z\n");
    for (i = 0; i < TAM; i++){
        vZ[i] = vX[i] * vY[i];
        printf("%d\t", vZ[i]);
    }
    
}
void interseccaoVetores(int vX[], int vY[]){
    int i,j,pos=0,vZ[2*TAM];
    printf("\nA intersecção do vetor x e y formou o vetor z\n");
    for(i = 0; i < TAM; i++){
        for(j = 0; j < TAM; j++){
            if(vX[i] == vY[j]){
                vZ[pos] = vX[i];
                printf("%d\t", vZ[pos]);
                pos++;
            }
        }
    }
}
int main(){
    int i,vX[TAM], vY[TAM], vZ[2*TAM];
    for(i = 0; i < 10; i++){
        printf("Digite o %d elemento do vetor x:", i+1);
        scanf("%d", &vX[i]);
    }
    for(i = 0; i < 10; i++){
        printf("Digite o %d elemento do vetor y:", i+1);
        scanf("%d", &vY[i]);
    }
    uniaoVetores(vX,vY);
    printf("\n");
    diferencaVetores(vX,vY);
    printf("\n");
    somaVetores(vX,vY);
    printf("\n");
    produtoVetores(vX,vY);
    printf("\n");
    interseccaoVetores(vX,vY);
    printf("\n");
    
    return 0;
}