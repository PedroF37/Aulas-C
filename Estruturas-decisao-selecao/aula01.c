#include <stdio.h>
#include <stdlib.h>


/*


                                            Aula 1
                                            
                                      Operadores relacionais:
                                      
                                      menor que (a < b)
                                      maior que (a > b)
                                      menor ou igual (a <= b)
                                      maior ou igual (a >= b)
                                      igual (a == b)
                                      diferente (a != b)

*/

int main()
{
    int a = 10, b = 20;
    
    printf("\n\tResultado: %d\n\n", a <  b);        // Resultado -> 1 - Verdadeiro
    printf("\n\tResultado: %d\n\n", a >  b);        // Resultado -> 0 - Falso
    printf("\n\tResultado: %d\n\n", a <=  b);       // Resultado -> 1 - Verdadeiro
    printf("\n\tResultado: %d\n\n", a >=  b);       // Resultado -> 0 - Falso
    printf("\n\tResultado: %d\n\n", a ==  b);       // Resultado -> 0 - Falso
    printf("\n\tResultado: %d\n\n", a !=  b);       // Resultado -> 1 - Verdadeiro
    
    return(0);
}
