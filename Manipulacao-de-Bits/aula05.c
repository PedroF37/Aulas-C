#include <stdio.h>
#include <stdlib.h>

/*
                                                Aula 05: Operador bit a bit  OU EXCLUSIVO (^)
                                                * 
                                                * Resumo:
                                                * 
                                                * 0 e 0 ou 1 e 1 da 0
                                                * 0 e 1 ou 1 e 0 da 1 pronto kkk
                                                * 
                                                * Esta operação é util quando precisamos inverter o estado de um bit 
*/


int main()
{
    int a, b;
    
    a = 73;             // 01001001
    b = a ^ (1 << 3);   // 00001000 (1 << 3), para inverter o bit 3 = 65
    printf("a: %d\tb: %d\n", a, b);
    
    b = b ^ (1 << 3);   // 00001000 (1 << 3), para inverter o bit 3 = 73
    printf("a: %d\tb: %d\n", a, b);
    
    return(0);
}
