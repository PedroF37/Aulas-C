#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/*


                                                    Aula 9
                                                    
                                          Como gerar números aleatórios para preencher uma matriz

*/

int main()
{
    int i, j;
    int mat1[3][3] = {{11, 12, 13}, {14, 15, 16}, {17, 18, 19}};
    
    srand(time(NULL));
    
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
            mat1[i][j] = rand() % 1000;
    }
    printf("\n");
    
    
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
            printf("%3d ", mat1[i][j]);
        printf("\n");
    }
    
    
    return(0);
}
