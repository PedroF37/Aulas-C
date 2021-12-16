#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*


                                            Aula 5
                                            
                             Função que retorna a soma de uma linha da matriz

*/

int tam = 5;

void imprimir(int mat[][tam])
{
    int i, j;
    
    for (i = 0; i < tam; i++)
    {
        for (j = 0; j < tam; j++)
        {
            printf("%2d ", mat[i][j]);
        }
        printf("\n");
    }
}

/* Função que calcula e retorna a soma de uma linha da matriz */
int somarLinha(int mat[][tam], int linha)
{
    int coluna, soma = 0;
    
    for (coluna = 0; coluna < tam; coluna++)
    {
        soma += mat[linha][coluna];
    }
    
    return(soma);
}

int main()
{
    int mat[5][5];
    int i, j;
    
    srand(time(NULL));
    
    for (i = 0; i < tam; i++)
    {
        for (j = 0; j < tam; j++)
        {
            mat[i][j] = 1 + rand() % 20;
        }
    }
    
    imprimir(mat);
    
    for (i = 0; i < 5; i++)
    {
        printf("A soma da linha %d é  %d\n", i + 1, somarLinha(mat, i));
    }
    return(0);
}
