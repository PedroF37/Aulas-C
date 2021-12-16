#include <stdio.h>
#include <stdlib.h>

/*


                                                Aula 12
                                                
                              Implemente uma função recursiva que, dados dois números inteiros
                              x e n, calcula e retorna o valor de x elevado a n.
                              
                              4 = 2 * 2
                              9 = 3 * 3

*/

int potencia(int x, int n)
{
    if (n == 0)
        return(1);
    else
    {
        return(x * potencia(x, n - 1));
    }
}

int main()
{
    int n, x;
    
    printf("Digite o valor para X e para N: ");
    scanf("%d%d", &x, &n);
    
    printf("Resultado de %d elevado a %d: %d\n", x, n, potencia(x, n));
    return(0);
}
