#include <stdio.h>
#include <stdlib.h>


/*
 *
 *                                      Aula 4
 *                                 Lêr números reais
 */

int main()
{
    /* tipo nome; */
    float numero = 3.1415;
    
    // printf("Valor da minha variável: %.2f\n", numero);
    
    printf("Digite um número real: ");
    scanf("%f", &numero);
    
    printf("\nO valor digitado foi: %.2f\n", numero);
    return(0);
}
