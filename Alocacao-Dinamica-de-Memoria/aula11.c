#include <stdio.h>
#include <stdlib.h>

/*

                        Aula 11: Curiosidade entre as funções malloc e calloc

*/

int main()
{
    int i, *vet1, *vet2;
    
    vet1 = malloc(10 * sizeof(int));    // separa as regiões de memória, mas se tiver lixo, o lixo continua lá
    vet2 = calloc(10, sizeof(int));     // separa as regiões de memória mas inicia automáticamente elas com zero.
                                        // se bem que rodei o programa assim umas mil vzes e ambas iniciaram com zero, mas os entendidos paladinos das artes computacionais
                                        // dizem que a malloc deixa o lixo na memória e a calloc não..
    
    printf("\nCom malloc: ");
    for (i = 0; i < 10; i++)
    {
        printf("%d ", *(vet1 + i));
    }
    printf("\n");
    
    printf("\nCom calloc: ");
    for (i = 0; i < 10; i++)
    {
        printf("%d ", *(vet2 + i));
    }
    printf("\n");
        
    return(0);
}