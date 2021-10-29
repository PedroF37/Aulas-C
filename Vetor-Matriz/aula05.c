#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*


                                                Aula 5
                                                
                               Como gerar números aleatórios para preencher um vetor.

*/

int main()
{
    int i;
    int num1[10];
    
    srand(time(NULL));
    
    for (i = 0; i < 10; i++)
        num1[i] = rand();
    
    printf("\n\n");
    
    for (i = 0; i < 10; i++)
        printf("%d ", num1[i]);
    
    printf("\n\n");
    
    
    return(0);
}
