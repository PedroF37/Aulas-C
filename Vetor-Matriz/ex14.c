#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*


                                                Exercicio 14
                                                
                           Faça um programa que imprima na tela apenas os valores abaixo da diagonal
                           principal de uma matriz 4x4.
                           
                           1 2 3 4  
                           5 6 7 8 i = 1, j = 0
                           9 0 1 2 i = 2, j = 1
                           3 4 5 6 i = 3, j = 2

*/

int main()
{
    int i, j, mat1[4][4];
    
    srand(time(NULL));
    
    /* Preenche a matriz */
    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
            mat1[i][j] = 1 + rand() % 20;
    
    /* Imprime para debug */
    printf("Matriz original:\n\n");
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
            printf("%2d ", mat1[i][j]);
        printf("\n");
    }
    
    printf("\n\nValores abaixo da diagonal principal:\n");
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (i > j)
                printf("%2d ", mat1[i][j]);
            else
                printf("   ");
        }
        printf("\n");
    }
    
    return(0);
}
