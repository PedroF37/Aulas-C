#include <stdio.h>
#include <stdlib.h>


/*


                                                    Exercicio 23
                                                    
                                  Escreva um programa que gera a saída abaixo
                                  Restrições:
                                  - A instrução printf pode ser usada no máximo 2 vezes;
                                  - O \n pode ser usado no máximo 2 vezes;
                                  
                                  *
                                  **
                                  ***
                                  ****
                                  *****
                                  ******
                                  *******
                                  ********

*/

int main()
{
   int x, j;
   
   for (j = 1; j <= 8; j++)
   {
        for (x = 1; x <= j; x++)
            printf("*");
        printf("\n");
   } 
    return(0);
}
