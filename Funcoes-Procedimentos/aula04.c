#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*


                                                    Aula 4
                                                    
                                Variáveis globais e escopo de variáveis.

*/

int idade2 = 35;

void imprimir(int idade)
{
    printf("\nIdade: %d\n", idade);
    printf("\nIdade2: %d\n", idade2);
}

int main()
{
    int idade = 25;
    
    printf("\nIdade: %d\n", idade);
    printf("\nIdade2: %d\n", idade2);
    imprimir(idade);
    
    return(0);
}
