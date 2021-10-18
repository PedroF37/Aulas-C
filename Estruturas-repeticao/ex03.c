#include <stdio.h>
#include <stdlib.h>

/*


                                            Exercicio 3
                                            
                          Faça um programa que some os números ímpares entre 1 e 1000 e imprima a resposta.

*/

int main()
{
    int x, contador = 0;
    
    for (x = 1; x <= 1000; x++)
        if (x % 2 == 1)
            contador += x;
    
    printf("\nA soma dos números ímpares entre 1 e 1000 é: %d\n", contador);
    
    
    
    return(0);
}
