#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*


                                                Aula 5
                                                
                               Como gerar números aleatórios dentro de um intervalo determinado.

*/

int main()
{
    int i;
    int num1[50];
    
    srand(time(NULL));
    
    for (i = 0; i < 50; i++)
        num1[i] = 1 + rand() % 99;
    
    printf("\n\n");
    
    for (i = 0; i < 50; i++)
        printf("%d ", num1[i]);
    
    printf("\n\n");
    
    
    return(0);
}
