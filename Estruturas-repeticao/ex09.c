#include <stdio.h>
#include <stdlib.h>

/*


                                    Exercicio 9
                                    
                        Faça um programa que calcule o valor de A, dado por:
                        A = 1 + 2 + 3 + 4 + ... + n, onde n é um número inteiro, maior do que zero
                        informado pelo usuário.

*/

int main()
{
    int termo, x, a = 0;
    
    do
    {
        printf("Digite um valor inteiro maior do que zero: ");
        scanf("%d", &termo);
    }
    while (termo <= 0);
    
    for (x = 1; x <= termo; x++)
        a += x;
    
    printf("\nO valor total é: %d\n", a);
    
    
    
    
    return(0);
}
