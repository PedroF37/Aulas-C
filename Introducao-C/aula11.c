#include <stdio.h>
#include <stdlib.h>


/*

                                                    Aula 11
                                                Operador sizeof
                                                
                                                sizeof x ou sizeof(int)
                                                int num = 8;
                                                sizeof num ou pudemos usar o parêntese -> sizeof(num)
                                                mas não pudemos usar sizeof int, tem que ser sizeof(int)


*/

int main()
{
    float x = 1.0;
    
    printf("Tamanho em memória de um int: %lu bytes.\n", sizeof(int));
    printf("Tamanho de um float na memória: %lu bytes\n", sizeof x);    // ou sizeof(x)
    // 4 * 8 = 32 bits
    
    
    return(0);
}
