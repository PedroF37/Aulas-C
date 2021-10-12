#include <stdio.h>
#include <stdlib.h>


/*

                                              Aula 13
                                     Tamanho de um int na memória
                                     intervalos: -2.147.483.648 até 2.147.483.647
                                     %hi ou %d

*/

int main()
{
    
    int x = 2147483647;     // O maior número positivo para um inteiro.
    
    printf("Valor de x: %d\n", x);

    return(0);
}
