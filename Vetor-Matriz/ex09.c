#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*


                                            Exercicio 9
                                            
                           Crie um programa que preencha uma matriz 5x10 com números inteiros. Em seguida faça:
                           
                           a) Some cada uma das linhas armazenando o resultado em um vetor;
                           
                           b) Some cada uma das colunas armazenando e o resultado em um vetor;
                           
                           c) Imprima os dois vetores identificando qual é a soma  das linhas e qual é a soma das colunas.

*/

int main()
{
    int i, j, mat[5][10], vetorLinhas[5] = {0}, vetorColunas[10] = {0};
    
    srand(time(NULL));
    
    // Preenche a matriz:
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 10; j++)
            mat[i][j] = 1 + rand() % 50;
    }
    
    // Imprimir para debug:
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 10; j++)
            printf("%2d ", mat[i][j]);
        printf("\n");
    }
    printf("\n\n");
    
    
    // Soma linhas e as colunas
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 10; j++)
        {
            vetorLinhas[i] += mat[i][j];
            vetorColunas[j] += mat[i][j];
        }
    }
    
    
    printf("\nVetor de Linhas:\n");
    for (i = 0; i < 5; i++)
        printf("%d ", vetorLinhas[i]);
    
    printf("\n\n");
    printf("Vetor Colunas:\n");
    for (i = 0; i < 10; i++)
        printf("%d ", vetorColunas[i]);
    
    printf("\n");
    
    
    return(0);
}
