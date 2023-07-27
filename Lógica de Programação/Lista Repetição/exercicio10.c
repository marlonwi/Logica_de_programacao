/*
 Chico tem 1,50 metros e cresce 2 centímetros por ano, enquanto Zé tem 1,10 metros e cresce 3
centímetros por ano. Construa um programa que calcule e imprima quantos anos serão necessários
para que Zé seja maior que Chico. 
*/
#include <stdio.h>
#include <math.h>
int main()
{
    int contAnos=0;
    float alturaChico = 1.50,alturaZe = 1.10;
    do
    {
        contAnos++;
        alturaChico = alturaChico + 0.02;
        printf("\n%f\n", alturaChico);
        alturaZe = alturaZe + 0.03;
        printf("\n%f\n", alturaZe);
    }while(alturaChico >= alturaZe);
    printf("A quantidade de anos necessários = %d", contAnos);
    return 0;
}