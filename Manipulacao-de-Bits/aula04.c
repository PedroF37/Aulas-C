#include <stdio.h>
#include <stdlib.h>

/*
                                                Aula 04: Operador bit a bit  OU (|)
*/


int main()
{
    int a, b, c;
    
    a = 30;     // 0000.0000.0001.1110
    b = 19;     // 0000.0000.0001.0011
    c = a | b;  // 0000.0000.0001.0010 = 31
    //c = a || b; // 0000.0000.0000.0001 = 1
    
    printf("%d & %d = %d\n", a, b, c);
    
    
    /* Como ativar um bit (colocar um bit em 1) */
    
    a = 1;              // 0000.0001
    b = a | (1 << 1);   // 0000.0010 = 3
    printf("a: %d\tb: %d\n", a, b);
    b = a | (1 << 2);   // 0000.0100 = 5
    printf("a: %d\tb: %d\n", a, b);
    b = a | (1 << 3);   // 0000.1000 = 9
    printf("a: %d\tb: %d\n", a, b);
    
    
    return(0);
}
