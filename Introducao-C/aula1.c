#include <stdio.h>
#include <stdlib.h>

// Caractere de escape para saltar uma linha -> \n

int main()
{
    // printf é uma função de saída.
    
    printf("\nOlá. Seja bem vindo!\n\n");
    printf("\n\n1234567890\n\n");
    printf("Valor retornado: %d\n", printf("\nOi\n"));  // Valor retornado = 4. 4 é o número de caracteres -> \nOi\n -> 4
    return(0);
}
