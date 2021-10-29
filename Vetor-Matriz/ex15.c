#include <stdio.h>
#include <stdlib.h>

/*


                                        Exercicio 15
                                        
                         Dada uma matriz 4x4 faça um programa que diga se ela é um Quadrado Mágico ou não. 
                        
                         Condição para ser Quadrado Mágico:
                        
                         -> A soma de todas as linhas, colunas, diagonal principal e secundária são iguais.
                         
                         Exemplo:
                         
                         16  3  2  13 = 34
                          5 10 11   8 = 34
                          9  6  7  12 = 34
                          4 15 14   1 = 34
                         
                         34 34 34  34          16 + 10 + 7 + 1 = 34
                                               13 + 11 + 6 + 4 = 34
                                               
                        Método:
                        
                        - Descobrimos o valor da soma de uma linha ou coluna ou diagonal e guardamos em uma variável (total);
                        - depois, para ser quadrado mágico, percorremos as linhas , colunas e vemos se a soma de cada linha e de 
                        cada coluna é igual ou diferente de total.

*/

#define tam 4 

int main()
{
    int total, soma, l, c, falhou = 0, mat[tam][tam] = {{16, 3, 2, 13}, {5, 10, 11, 8}, {9, 6, 7, 12}, {4, 15, 14, 1}};
    
    soma = 0;
    for (l = 0; l < tam; l++)
        soma += mat[l][l];
    printf("\nDiagonal Principal: %d\n", soma);
    
    total = soma;
    
    soma = 0;
    for (l = 0; l < tam; l++)
        soma += mat[l][tam - 1 -l];
    printf("\nDiagonal Secundária: %d\n", soma);
    
    if (total != soma)
    {
        printf("Diagonal Secundária diferente\n");
        falhou = 1;
    }
    
    for (l = 0; l < tam; l++)
    {
        soma = 0;
        for (c = 0; c < tam; c++)
            soma += mat[l][c];
        printf("Linha %d: %d\n",l, soma);
        
        if (total != soma)
        {
            printf("A linha %d é diferente!\n", l);
            falhou = 1;
        }
    }
    
    for (c = 0; c < tam; c++)
    {
        soma = 0;
        for (l = 0; l < tam; l++)
            soma += mat[l][c];
        printf("Coluna %d: %d\n",c, soma);
        
        if (total != soma)
        {
            printf("A coluna %d é diferente!\n", c);
            falhou = 1;
        }
    }
    
    if (falhou)
        printf("\nNão é um quadrado mágico!\n");
    else
        printf("\nÉ um quadrado mágico!\n");
    
    return(0);
}
