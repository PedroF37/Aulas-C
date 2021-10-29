#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*


                                                Exercicio 13
                                                
                          Faça um programa para calcular a transposta de uma matriz 5x4.
                          Imprima as duas matrizes na tela.
                          
                          Rascunho..
                          
                          j                      
                        i 1 2 3 4     1 5 9 3 7
                          5 6 7 8     2 6 0 4 8
                          9 0 1 2     3 7 1 5 9
                          3 4 5 6     4 8 2 6 0
                          7 8 9 0

*/

int main()
{
    int i, j, mat1[5][4], mat2[4][5];
    
    srand(time(NULL));
    
    /* Preenche a matriz 5x4 */
    for (i = 0; i < 5; i++)
        for (j = 0; j < 4; j++)
            mat1[i][j] = 1 + rand() % 20;
    
    /* Imprime a matriz original */
    printf("\nMatriz Original: 5x4\n\n");
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 4; j++)
            printf("%2d ", mat1[i][j]);
        printf("\n");
    }
    printf("\n\n");
    
    /* Cria a transposta */
    for (i = 0; i < 4; i++)
        for (j = 0; j < 5; j++)
            mat2[i][j] = mat1[j][i];
    

    /* Imprime a transposta */
    printf("\nMatriz Transposta: 4x5\n\n");
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 5; j++)
            printf("%2d ", mat2[i][j]);
        printf("\n");
    }
    
    return(0);
}
