#include <stdio.h>
#include <stdlib.h>

/*


                                    Exercicio 6
                                    
                    Faça um programa que imprima na tela todos os múltiplos de 7
                    entre 1 e 9999.

*/

int main()
{
    int x;
    
    for (x = 7; x <= 999; x += 7)
        printf("%4d ", x);

    putchar('\n');
    
    
    return(0);
}
