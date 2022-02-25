#include <stdio.h>
#include <stdlib.h>

/*

                             Aula 08.c: O que é ponteiro para ponteiro?

*/

int main()
{
    int A = 100, *B, **C;
    
    B = &A;
    C = &B;
    
    printf("Endereço de A: %p\tConteudo de A: %d\n", &A, A);
    printf("Endereço de B: %p\tConteudo de B: %p\n", &B, B);
    printf("Conteudo apontado por B: %d\n", *B);
    printf("Endereço de C: %p\tConteudo de C: %p\n", &C, C);
    printf("Conteudo apontado por C: %d\n", **C);
    return(0);
}