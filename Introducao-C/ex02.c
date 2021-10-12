#include <stdio.h>
#include <stdlib.h>


/*


                                                Exercicio 2

                              Faça um programa em C para trocar o valor de duas variáveis inteiras
                              sem usar nenhuma variável auxiliar.

*/

int main()
{
    int a, b;
    
    printf("Digite dois valores inteiros: ");
    scanf("%d%d", &a, &b);
    printf("\nValores iniciais: %d, %d\n", a, b);
    
    a = a + b;
    b = a - b;
    a = a - b;
    
    printf("\nValores depois da troca: %d, %d\n", a, b);
    
    
    /*
    
     a = 10;
     b = 5;
     
     a = b; a = 5; b = 5; errado.
     
     a = a + b; a = 10 + 5 = 15; a = 15; b = 5;
     b = a - b; b = 15 - 5 = 10; a = 15; b = 10; uma feita
     a = a - b; a = 15 - 10 = 5; a = 5; b = 10; feito
    
     
    */
    return(0);
}
