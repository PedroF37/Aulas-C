#include <stdio.h>
#include <stdlib.h>


/*


                                        Exercicio 7
                                        
                       Leia um valor inteiro N. Apresente o quadrado de cada um dos valores pares,
                       de 1 até N, inclusive o N, se for o caso.

*/

int main()
{
    int num, x;
    
    do
    {
        printf("Digite um valor inteiro maior do que zero: ");
        scanf("%d", &num);
    }
    while (num <= 0);
    
    for (x = 2; x <= num; x += 2)
        printf("Quadrado de %4d = %4d\n", x, x * x);
    
    return(0);
}
