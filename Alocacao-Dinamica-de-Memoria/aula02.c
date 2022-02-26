#include <stdio.h>
#include <stdlib.h>


/*

                            Aula 02: Alocação dinâmica de memória com a função calloc.
                            Retorna um ponteiro para a região de memória alocada ou NULL.

*/

int main()
{
    //int *x;
    char *x;
    
    //x = malloc(sizeof(int));
    x = calloc(1, sizeof(char));
    
    if (x)
    {
        printf("Memória alocada com sucesso!\n");
        printf("x: %c\n", *x);
        *x = 'H';
        printf("x: %c\n", *x);
    }
    else
        printf("Erro ao alocar memória!\n");
    
    
    
    return(0);
}