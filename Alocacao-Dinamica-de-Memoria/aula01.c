#include <stdio.h>
#include <stdlib.h>


/*

                            Aula 01: Alocação dinâmica de memória com a função malloc.
                            Retorna um ponteiro para a região de memória alocada ou NULL.

*/

int main()
{
    int *x;
    
    x = malloc(sizeof(int));
    
    if (x)
    {
        printf("Memória alocada com sucesso!\n");
        printf("x: %d\n", *x);
        *x = 50;
        printf("x: %d\n", *x);
    }
    else
        printf("Erro ao alocar memória!\n");
    
    
    return(0);
}