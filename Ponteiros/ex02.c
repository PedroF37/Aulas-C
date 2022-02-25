#include <stdio.h>
#include <stdlib.h>


/*

                                   Exercicio 2:
                                   
                                   Escreva um procedimento que troca os valores dos parametros recebidos.
                                   Sua assinatura deve ser: void troca(float *a, float *b).

*/

void troca(float *a, float *b)
{
    float temp;
    temp = *a;
    *a = *b;
    *b = temp;
}


int main()
{
    float a = 50, b = 101;
    
    printf("Antes da troca: %.1f\t%.1f\n", a, b);
    troca(&a, &b);
    
    printf("Depois da troca: %.1f\t%.1f\n", a, b);
    
    return(0);
}