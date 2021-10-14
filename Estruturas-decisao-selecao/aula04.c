#include <stdio.h>
#include <stdlib.h>


/*


                                    Aula 4

                          Verdadeiro e Falso na linguagem C

*/

int main()
{
    int a = 10;
    
    printf("\nDigite um valor qualquer: ");
    scanf("%d", &a);
    
    printf("\nResultado lógico: %d\n", a < 0);
    
    if (a < 0)
        printf("\n\tValor negativo!\n");
    else
        printf("\n\tValor positivo ou igual a zero!\n");
    
    printf("\nContinuação do programa...\n");
    
    return(0);
}
