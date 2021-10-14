#include <stdio.h>
#include <stdlib.h>


/*


                                                    Aula 3

                                               Decisão completa

*/

int main()
{
    int a = 10;
    
    printf("Digite um valor qualquer: ");
    scanf("%d", &a);
    
    if (a < 0)
        printf("\n\tValor negativo!\n");
    else
        printf("\n\tValor positivo ou igual a zero!\n");
    
    printf("\nContinuação do programa...\n");
    
    
    return(0);
}
