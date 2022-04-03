#include <stdio.h>
#include <stdlib.h>

/*
                                    Aula 01: Deslocamento á esquerda e á direita
*/

int main()
{
    /* Deslocamento á esquerda: é equivalente a multiplicar por dois (2) */

    int a, b;

    /*
    a = 1;      // 0001
    b = a << 1; // 0010 = 2  
    printf("a: %d:\tb: %d\n", a, b);
    
    b = a << 2; // 0100 = 4
    printf("a: %d\tb: %d\n", a, b);
    
    b = a << 3; // 1000 = 8
    printf("a: %d\tb: %d\n", a, b);
    */

    /* Deslocamento á direita: é equivalente a dividir (divisão inteira) */
    
    a = 10;     // 1010
    b = a >> 1; // 0101 = 5
    printf("a: %d\tb: %d\n", a, b);
    
    b = a >> 2; // 0010 = 2
    printf("a: %d\tb: %d\n", a, b);
    
    b = a >> 3; // 0001 = 1
    printf("a: %d\tb: %d\n", a, b);
    
    return(0);
}
