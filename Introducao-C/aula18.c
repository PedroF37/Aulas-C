#include <stdio.h>
#include <stdlib.h>


/*


                                            Aula 18

                                        Operadores matemáticos para:
                                        
                                        soma            +
                                        subtração       -
                                        multiplicação   *
                                        divisão         /

*/

int main()
{
    printf("\nSoma: %d\n", 10 + 20);
    printf("\nSubração: %d\n", 10 - 20);
    printf("\nMultilicação: %d\n", 10 * 20);
    printf("\nDivisão: %d\n", 10 / 20);
    printf("\nDivisão: %f\n", 10.0 / 20);
    
    /* Dividir inteiro por inteiro, a resposta vai ser inteira. Então aqui, 10 / 20, a resposta é 0.5
       mas como estamos fazendo divisão inteira (/) o programa dá nos resposta inteira (0).
       Podemos fazer assim: 10.0 / 20 -> agora dá 0.5
    */
    
    return(0);
}
