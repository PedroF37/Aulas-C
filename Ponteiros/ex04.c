#include <stdio.h>
#include <stdlib.h>

/*

                                       Exercicio 4:
                                       
                                       Considere  a seguinte declaração: int A, *B, **C, ***D
                                       
                                       Escreva um programa que leia a variável A e calcule  e exiba o dobro, o triplo e o
                                       quadruplo desse valor usando apenas os ponteiros B, c e D. O ponteiro B deve ser
                                       usado para calcular o dobro, o C o triplo e o D o quadruplo.

*/

int main()
{
    int A, *B, **C, ***D;
    
    printf("Digite um valor inteiro: ");
    scanf("%d", &A);
    
    B = &A; 
    C = &B;
    D = &C;
    
    printf("Valor digitado: %d\n", A);
    printf("Dobro: %d\n", *B * 2);
    printf("Triplo: %d\n", **C * 3);
    printf("Quadruplo: %d\n", ***D * 4);
    return(0);
}