#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/*


                                            Exercicio 8
                                            
                      Faça um programa que calcule e imprima a soma de todos os elementos
                      de uma matriz 5 x 7.

*/

int main()
{
    int i, j, soma = 0, mat[5][7];
    
    srand(time(NULL));
    
    for (i = 0; i < 5; i++)
        for(j = 0; j <7; j++)
            mat[i][j] = 1 + rand() % 50;
    
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 7; j++)
        {
            printf("%2d ", mat[i][j]);
            soma += mat[i][j];
        }
        printf("\n");
    }
    printf("\nSoma = %2d\n", soma);
    
    return(0);
}
