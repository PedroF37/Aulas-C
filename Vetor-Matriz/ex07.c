#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*


                                     Exercicio 7
                                     
                       Faça um programa para ordenar um vetor com 100 números inteiros. Imprima o vetor antes 
                       e após a ordenação.

*/

int main()
{
    int i, contador = 0, troca = 0, temp, nums[100];
    
    srand(time(NULL));
    
    for (i = 0; i < 100; i++)
        nums[i] = 1 + rand() % 100;
    
    printf("\n\nOriginal\n");
    for (i = 0; i < 100; i++)
        printf("%2d ", nums[i]);
    printf("\n\n");
    
    
    do
    {
        troca = 0;
        contador++;
        for (i = 0; i < 99; i++)
        {
            if (nums[i] > nums[i + 1])
            {
                temp = nums[i];
                nums[i] = nums[i + 1];
                nums[i + 1] = temp;
                troca = 1;
            }
        }
    }
    while (troca);  // ou while (troca == 1);
    
    printf("\n\nOrdenado: Contador: %d\n", contador);
    for (i = 0; i < 100; i++)
        printf("%2d ", nums[i]);
    printf("\n");
    
    
    
    return(0);
}
