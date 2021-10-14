#include <stdio.h>
#include <stdlib.h>


/*


                                    Aula 5

                               Decisão aninhada

*/

int main()
{
    int a = 10;
    
    printf("\nDigite um valor qualquer: ");
    scanf("%d", &a);
    
    printf("Operador ternário:\n");
    a < 0 ? printf("\n\tValor negativo!\n") : printf("\n\tValor positivo ou igual a zero!\n");
    
    printf("\n\nif/else\n");
    if (a < 0)
        printf("\n\tValor negativo!\n");
    else
    {
        if (a > 0)
            printf("\n\tValor positivo!\n");
        else
            printf("\n\tValor igual a zero!\n");
    }
    
    printf("\nContinuação do programa...\n");
    
    return(0);
}
