#include <stdio.h>
#include <stdlib.h>


/*

                                    Aula 05 (não tem a ver com struct)


*/

int main()
{
    int i, j, n;
    
    printf("Digite o valor de n: ");
    scanf("%d", &n);
    
    for (i = 1; i <= n; i++)
    {
        for (j = n - i; j >= 1; j--)
        {
            printf(" ");
        }
        
        for (j = 1; j <= i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    
    return(0);
}
