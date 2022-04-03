#include <stdio.h>
#include <stdlib.h>

/*
                                Aula 02: Operador bit a bit NOT (~)
                                * 
                                *  1 = 0001               2 = 0010               3 = 0011                 9 = 1001
                                * ~1 = 1110 (-2)         ~2 = 1101 (-3)         ~3 = 1100 (-4)           ~9 = 0110 (-10)  
                                * 
                                
                                                  * Complemento de dois
                                        
                                        Como representar o -2 em binario?
                                        * 
                                        * 2    - em decimal
                                        * 0010 - dois em binario
                                        * 1101 - not
                                        *    1 - adiciona 1 e volta a fazer o not (a inversao)
                                        * 1110
*/

int main()
{
    int a, b;
    a = 9;
    b = ~a;
    
    printf("\ta: %d\t!a: %d\n", a, b);
    return(0);
}
