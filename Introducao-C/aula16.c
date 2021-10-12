#include <stdio.h>
#include <stdlib.h>


/*


                                                Aula 16
                        Tipo double. Armazena números fracionários (reais) com maior precisão
                        do que o float.
                        %lf

*/

int main()
{
    // float x = 3.1415;
    double y = 3.14155896587458962548;
    
    printf("Um double precisa de %lu bytest de memória\n", sizeof(y));
    
    // 8 bytes
    // 8 * 8 = 64 bits
    
    
    return(0);
}
