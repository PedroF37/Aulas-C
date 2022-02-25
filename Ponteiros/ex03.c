#include <stdio.h>
#include <stdlib.h>

/*

                                  Exercicio 3:
                                  
                                  Crie um programa que contenha um array de inteiros com 10 elementos.
                                  Imprima o elemento e o endereço de cada posição do array.

*/

int main()
{
    int vet[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, i;
    
    for (i = 0; i < 10; i++)
    {
        printf("Valor: %d\n", *(vet + i));
        printf("Endereço: %p\n", vet + i);
    }
    return(0);
}