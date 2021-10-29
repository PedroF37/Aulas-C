#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*


                                                    Aula 12
                                                    
                                  Como evitar a geração de números repetidos

*/

int main()
{
    int i = 0, j, igual, vet[25];
    
    srand(time(NULL));
    
    do
    {
        vet[i] = rand() % 50;
        igual = 0;
        for (j = 0; j < i; j++)
        {
            if (vet[j] == vet[i])
                igual = 1;
        }
        
        if (igual == 0)
            i++;
    }
    while (i < 25);
    
    for (i = 0; i < 25; i++)
    {
        printf("%d ", vet[i]);
    }
    printf("\n\n");
    
    
    return(0);
}
