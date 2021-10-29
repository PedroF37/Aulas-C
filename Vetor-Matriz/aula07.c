#include <stdio.h>
#include <stdlib.h>


/*


                                                    Aula 7
                                                    
                                   Como criar uma matriz (Array bidimensional)

*/

int main()
{
    int mat1[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    /*
               c0   c1   c2
     linha 0   1    2    3
     linha 1   4    5    6
     linha 2   7    8    9
    
    */
    
    // Neste caso temos que informar o conjunto dos elementos, pois como não informamos as linhas, será o conjunto
    // dos elementos que vai dizer quantas linhas serão.
    int mat2[][3] = {1, 2, 3, 4, 5, 6}; // aqui entao serão 2 linhas por 3 colunas.
    
    int mat3[3][3] = {0};   // preenche tudo com zero (0);
    
    float mat4[4][5];
    char mat5[10][10];
    
    return(0);
}
