#include <stdio.h>
#include <stdlib.h>

/*

                                                 Aula 04.c: Como passar um ponteiro como parâmetro ?

*/

void imprimir(int *num)
{
    printf("%d\n", *num);
    *num = 80;
}

int main()
{
    int idade = 38;
    imprimir(&idade);
    printf("No main: %d\n", idade);
    
    return(0);
}