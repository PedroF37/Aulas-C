#include <stdio.h>
#include <stdlib.h>


/*


                                                    Exercicio 20
                                                    
                               Escreva um programa que gere a saída abaixo (10 linhas, 20 * por linha)
                               Restrições:
                                - A instrução printf pode ser usada no máximo 2 vezes;
                                - O \n pode ser usado no máximo 1 vez;
                                
                                ********************
                                ********************
                                ********************
                                ********************
                                ********************
                                ********************
                                ********************
                                ********************
                                ********************
                                ********************

*/

int main()
{
    int x, j;
    
    for (j = 1; j <= 10; j++)
    {
        for (x = 1; x <= 20; x++)
            printf("*");
        printf("\n");
    }
    
    return(0);
}
