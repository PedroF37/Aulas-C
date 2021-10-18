#include <stdio.h>
#include <stdlib.h>

/*


                                            Exercicio 4
                                            
                          Faça um programa que some os números ímpares entre 1 e 1000 e imprima a resposta.
                          Restrição: O bloco de repetição deve executar no máximo 500 vezes.

*/

int main()
{
    int x, contador = 1;
    
    for (x = 3; x <= 999; x += 2)
        contador += x;

    printf("\nA soma dos números ímpares entre 1 e 1000 é: %d\n", contador);
    
    
    
    return(0);
}
