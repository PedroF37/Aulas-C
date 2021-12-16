#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*


                                            Aula 6
                                            
                             Função que retorna a soma de uma coluna da matriz

*/

int mat[5][5];  // mat agora é global, não precisa incluir no parêntese das funções neno no parentese da chamada das funções
int tam = 5;

void imprimir()
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
int somarLinha(int linha)
{
    int coluna, soma = 0;
    
    for (coluna = 0; coluna < tam; coluna++)
    {
        soma += mat[linha][coluna];
    }
    
    return(soma);
}

/* Função que calcula e retorna a soma de uma coluna da matriz */
int somarColuna(int coluna)
{
    int linha, soma = 0;
    
    for (linha = 0; linha < tam; linha++)
    {
        soma += mat[linha][coluna];
    }
    
    return(soma);
}

int main()
{

    int i, j;
    
    srand(time(NULL));
    
    for (i = 0; i < tam; i++)
    {
        for (j = 0; j < tam; j++)
        {
            mat[i][j] = 1 + rand() % 20;
        }
    }
    
    imprimir();
    
    for (i = 0; i < 5; i++)
    {
        printf("A soma da linha %d é  %d\n", i + 1, somarLinha(i));
        printf("A soma da coluna %d é %d\n", i + 1, somarColuna(i));
    }
    return(0);
}
