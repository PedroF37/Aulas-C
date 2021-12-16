#include <stdio.h>
#include <stdlib.h>

/*


                                                Aula 17
                                                
                              Faça um procedimento recursivo para converter um número decimal n
                              para sua forma binária.
                              
                              Converter decimal (inteiro) para binário:
                              
                                     resultado  resto
                              3 / 2  1          1
                              1 / 2  0          1
                              
                              3 em binário: 011

                              ------------------------
                                    resultado   resto
                              
                              4/2     2          0
                              2/2     1          0
                              1/2     0          1
                              
                              4 em binário: 0100
*/

void binario(int n)
{
    if (n == 0)
        printf("%d", n);
    else
    {
        binario(n / 2);
        printf("%d", n % 2);
    }
}

int main()
{
    int n;
    
    printf("Digite um valor decimal: ");
    scanf("%d", &n);
    
    binario(n);
    printf("\n");
    
    return(0);
}
