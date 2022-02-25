#include <stdio.h>
#include <stdlib.h>


/*                                    Aula 02: De quantta memória um ponteiro precisa? */

int main()
{
    int *p;
    char *p2;
    float *p3;
    
    printf("Tamanho: %lu\n", sizeof(p));
    printf("Tamanho: %lu\n", sizeof(p2));
    printf("Tamanho: %lu\n", sizeof(p3));
    
    /* O tamanho é o mesmo (no meu caso 8) porque o ponteiro aponta para um endereço de memória e um endereço de memoria tem o mesmo tamanho, independente se 
    guarda um int, float, char etc..
    */
    return(0);
}