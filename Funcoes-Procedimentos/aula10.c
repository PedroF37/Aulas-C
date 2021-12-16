#include <stdio.h>
#include <stdlib.h>

/*


                                                    Aula 10
                                                    
                               Fazer uma função que calcula e retorna o fatorial de n.
                               
                               4! = 4 * 3 * 2 * 1 = 24
                               1! e 0! = 1

*/

int fatorial(int n)
{
    if (n == 0 || n == 1)
        return(1);
    else
    {
        return(n * fatorial(n - 1));
    }
}

int main()
{
    int n;
    
    printf("Digite um valor maior do que zero: ");
    scanf("%d", &n);
    
    printf("O fatorial de %d é: %d\n", n, fatorial(n));
    
    return(0);
}
