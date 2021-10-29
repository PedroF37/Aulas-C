#include <stdio.h>
#include <stdlib.h>



/*


                                                    Aula 2
                                                    
                                   Como imprimir o conteúdo de  um vetor

*/

int main()
{
    int i;
    int num1[] = {1, 5, 9, 15, 43};
    char vogais[5] = {'a', 'e', 'i', 'o', 'u'};
    float notas[3] = {7.5, 8.3, 9.5};
    
    for (i = 0; i < 5; i++)     // ou i <= 4
        printf("%d ", num1[i]);
    printf("\n\n");
    
    for (i = 0; i < 5; i++)
        printf("%c ", vogais[i]);
    printf("\n\n");
    
    for (i = 0; i < 3; i++)
        printf("%.1f, ", notas[i]);
    printf("\n\n");
    
    
    
    return(0);
}
