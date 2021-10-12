#include <stdio.h>
#include <stdlib.h>

/*


                                                Aula 20
                                    Operador de resto da divisão -> %
                                    Resto da divisão em uma divisão inteira /
                                    int a = 10, b = 20;
                                    
                                    a % b = 10;

*/

int main()
{
    int a = 7, b = 20;
    
    printf("Resto da divisão inteira: %d\n", a % b);
    printf("Resto da divisão inteira: %d\n", b % a);
    printf("Par ou impar, 20 ? -> %d\n", b % 2);
    printf("Par ou impar, 7 ? -> %d\n", a % 2);
    
    return(0);
}
