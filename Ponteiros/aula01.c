#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num = 10;
    int *p;     // p é um ponteiro para uma região de memória que guarda um valor inteiro
    
    p = &num;   // ponteiro só armazena endereços de memória
    
    printf("Valor de num: %d\n", num);
    printf("Endereço na memória de num: %p\n", &num);
    
    printf("Valor de p: %p\n", p);
    printf("Endereço na memória de p: %p\n", &p);
    printf("Valor apontado por p: %d\n", *p);
    
    return(0);
}