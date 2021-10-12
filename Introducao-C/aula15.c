#include <stdio.h>
#include <stdlib.h>


/*


                                            Aula 15
                               Tamanho de um float na memória
                               %f

*/

int main()
{
    float x = 3.1415;
    
    printf("Um float precisa de: %lu bytes de memória\n", sizeof(x));
    
    // 4 bytes.
    // 4 * 8 = 32 bits
    // na minha máquina o operador sizeof queixa-se se não usar o %lu
    return(0);
}
