#include <stdio.h>
#include <stdlib.h>


/*
 
                                            Aula 7
                                    Lendo vários valores com o scanf
 
*/

int main()
{
    int num1, num2, num3;
    
    printf("Digite três valores inteiros: ");
    scanf("%d %d %d", &num1, &num2, &num3);
    
    printf("\nOs valores digitados foram: %d, %d e %d\n", num1, num2, num3);
    
    return(0);
}
