#include <stdio.h>
#include <stdlib.h>


/*


                                            Aula 11
                                            
                                        else if encadeados

*/

int main()
{
    int a = 10;
    
    printf("Digite um valor qualquer: ");
    scanf("%d", &a);
    
    if (a < 0)
        printf("\n\tValor negativo!\n");
    else if (a > 0)
        printf("\n\tValor positivo!\n");
    else
        printf("\n\tValor igual a zero!\n");
    
    
    return(0);
}
