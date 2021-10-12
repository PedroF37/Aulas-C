#include <stdio.h>
#include <stdlib.h>


/*


                                           Aula 17
                               Operador long para o tipo double
                               double -> %lf
                               long double -> %Lf
                               
                               Windows precisa usar a função:  __mingw_printf() ao invés do printf
                               O windows não suporta a impressão de um número de 16 bytes de memória

*/

int main()
{
    long double y = 3.14155896587458962548;
    
    printf("Valor de y: %.15Lf\n", y);
    printf("Tamanho de um long double na memória: %lu bytes\n", sizeof(y));
    
    // 16 bytes
    // 16 * 8 = 128 bits
    
    return(0);
}
