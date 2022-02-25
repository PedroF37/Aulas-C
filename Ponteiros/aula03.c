#include <stdio.h>
#include <stdlib.h>

/*

                                    Aula 03: Porque não usamos o & ao ler uma string com a função scanf ?

*/

int main()
{
    char palavra[100];
    
    //scanf("%100[^\n]", palavra);
    //printf("%s\n", palavra);
    
    printf("%p\n", palavra);
    printf("%p\n", &palavra);
    printf("%p\n", &palavra[0]);
    
    return(0);
}