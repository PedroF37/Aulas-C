#include <stdio.h>
#include <stdlib.h>

/*


                                                Aula 13
                                                
                             Desenvolva uma função recursiva que calcula a soma
                             dos números inteiros de 1 até N.

*/

int soma(int n)
{
    if (n == 0)
        return(0);
    else
    {
        return(n + soma(n - 1));
    }
}

int main()
{
    int n;
    
    printf("Digite N: ");
    scanf("%d", &n);
    
    printf("Soma de 1 até %d: %d\n", n, soma(n));
    
    return(0);
}
