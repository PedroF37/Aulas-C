#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*


                                            Exercicio 11
                                            
                          Faça um programa que imprima na tela a diagonal secundária de uma matriz 7x7
                          
                          1 2 3 4 5 6 7 -> i = 0, j = 6
                          8 9 0 1 2 3 4 -> i = 1, j = 5
                          5 6 7 8 9 0 1 -> i = 2, j = 4
                          2 3 4 5 6 7 8 -> i = 3, j = 3
                          9 0 1 2 3 4 5 -> i = 4, j = 2
                          6 7 8 9 0 1 2 -> i = 5, j = 1
                          3 4 5 6 7 8 9 -> i = 6, j = 0

*/

int main()
{
    int tam = 7, i, j, mat[tam][tam];
    
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
    
    /* Do jeito burrinho, pelos vistos kkk
    printf("Diagonal Secundária:\n\n");
    for (i = 0; i < tam; i++)
    {
        for (j = 0; j < tam; j++)
        {
            if ((i == 0 && j == 6) || (i == 1 && j == 5) || (i == 2 && j == 4) ||
                (i == 3 && j == 3) || (i == 4 && j == 2) || (i == 5 && j == 1) ||
                (i == 6 && j == 0))
                printf("%d ", mat[i][j]);
            else
                printf("   ");
        }
        printf("\n");
    }
    */
    
    /* Do jeito esperto kkk */
    printf("\nDiagonal Secundária: ");
    for (i = 0; i < tam; i++)
    {
        printf("%d ", mat[i][tam - 1 - i]);
    }
    printf("\n");
    
    return(0);
}
