#include <stdio.h>
#include <stdlib.h>


/*


                                        Exercicio 3

                       Escreva um programa em C que leia um número e informe se ele é divisível por 2, por 3 ou
                       por 5, ou se não é divisível por nenhum deles.

*/


int main()
{
    int num;
    
    printf("Digite um número inteiro: ");
    scanf("%d", &num);
    
    if (num % 2 == 0 || num % 3 == 0 || num % 5 == 0)
        printf("\n%d é divisivel por 2, por 3 ou por 5.\n", num);
    else
        printf("\n%d não é divisivel por 2, nem por 3 nem por 5\n", num);
    
    return(0);
}
