#include <stdio.h>
#include <stdlib.h>


/*


                                             Aula 19

                                        Conversão de tipos
                                        
                                        int = 10;
                                        (float) a;
                                        
                                        inteiro dividido por inteiro = resultado inteiro.
                                        int a = 10, b = 20;
                                        
                                        a / b = 0 divisão inteira
                                        (float) a / b = 0.5

*/

int main()
{
    int a = 10, b = 20;
    int c;  // pode converter float para inteiro só que vai perder a parte decimal. vai mostrar 3
    float pi = 3.1415;
    
    c = (int)pi;
    printf("Valor de c: %d", c);
    printf("\nSoma: %d\n", a + b);
    printf("\nSubtração: %d\n", a - b);
    printf("\nMultiplicação: %d\n", a * b);
    printf("\nDivisão: %f\n", (float)a / b);
    
    
    
    return(0);
}
