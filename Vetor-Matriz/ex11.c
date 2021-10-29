#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*


                                            Exercicio 11
                                            
                          Faça um programa que imprima na tela a diagonal principal de uma matriz 5x5
                          
                          1 2 3 4 5 -> i = 0 j = 0
                          6 7 8 9 0 -> i = 1 j = 1
                          1 2 3 4 5 etc etc
                          6 7 8 9 0  if (i == j)
                          1 2 3 4 5     printf("%d ", mat[i][j]);

*/

int main()
{
    int tam = 5, i, j, mat[tam][tam];
    
    srand(time(NULL));
    
    for (i = 0; i < tam; i++)
        for (j = 0; j < tam; j++)
            mat[i][j] = 1 + rand() % 50;
    
    printf("Matriz Original:\n\n");
    for (i = 0; i < tam; i++)
    {
        for (j = 0; j < tam; j++)
            printf("%2d ", mat[i][j]);
        printf("\n");
    }
    printf("\n\n");
    
    printf("Diagonal Principal:\n\n");
    for (i = 0; i < tam; i++)
    {
        for (j = 0; j < tam; j++)
        {
            if (i == j)
                printf("%d ", mat[i][j]);
            else
                printf("   ");
        }
        printf("\n");
    }
    
    return(0);
}
