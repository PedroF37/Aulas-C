#include <stdio.h>
#include <stdlib.h>


/*


                                         Aula 14
                               Operador long para o tipo int
                               %li ou %ld

*/

int main()
{
    long int x = 2147483647;
    
    printf("Tamanho de um long int na memória: %lu bytes\n", sizeof(x));
    
    printf("Valor de x: %ld\n", x);
    
    x++;
    
    printf("Valor de x: %ld\n", x);
    // 8 bytes na minha máquina. Pode variar de máquina para máquina.
    // 8 * 8 = 64 bits
    // em casos ou máquinas onde não dá diferença do long int para o int, podemos usar o long long int: long long int x = 2147483647;
    // para long long int é: %lld.
    return(0);
}
