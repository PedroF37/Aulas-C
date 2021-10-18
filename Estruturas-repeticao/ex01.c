#include <stdio.h>
#include <stdlib.h>


/*


                                            Exercicio 1
                                            
                          Elabore um programa em C para lêr do teclado um valor inteiro entre 1 e 10
                          e apresentar a tabuada.

*/

int main()
{
    int num, x;
    
    do
    {
        printf("Digite um número inteiro entre 1 e 10: ");
        scanf("%d", &num);
    }
    while (num < 1 || num > 10);
    
    for (x = 1; x <= 10; x++)
        printf("%2d * %2d = %2d\n", num, x, num * x);
    
    
    return(0);
}
