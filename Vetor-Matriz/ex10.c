#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*


                                        Exercicio 10
                                        
                       Dadas duas matrizes A e B 3x3, faça um programa para calcular a soma das matrizes e salvar
                       em uma matriz C. Imprima as três matrizes.

*/

int main()
{
    int i, j, mat1[3][3], mat2[3][3], mat3[3][3]; 
    
    srand(time(NULL));
    
    /* Preenche as matrizez e soma */
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
        {
            mat1[i][j] = 1 + rand() % 20;
            mat2[i][j] = 1 + rand() % 20;
            mat3[i][j] = mat1[i][j] + mat2[i][j];
        }
    
    /* Imprime mat1 */
    printf("Matriz mat1:\n\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
            printf("%2d ", mat1[i][j]);
        printf("\n");
    }
    
    printf("\n\n");

    
    /* Imprime mat2 */
    printf("Matriz mat2:\n\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
            printf("%2d ", mat2[i][j]);
        printf("\n");
    }

    printf("\n\n");
    
    /* Imprime mat3 */
    printf("Matriz mat3:\n\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
            printf("%2d ", mat3[i][j]);
        printf("\n");
    }
    
    printf("\n");
    
    return(0);
}
