#include <stdio.h>
#include <stdlib.h>


/*

                                          Aula 12
                                Operador short para o tipo int
                                intervalo: -32.768 até 32.767
                                %hi ou %d
                                
                                32767 -> 111111111111111 -> 15 bits apenas porque o primeiro bit á esquerda, é o bit do sinal que diz
                                                            se é positivo ou negativo. Se fizer assim:
                                
                                32768 -> 1000000000000000 -> 16 bits, o número vai ficar -32768, ocorre um estouro de  memória, porque
                                                             precisa de 16 bits para o digito e ia precisar de mais um para o sinal, mas não tem.
                                
                                Moral da história: se trabalhar com inteiros entre estes valores, podemos usar o short int, para economizar memória,
                                mas se não, então usamos o int.

*/

int main()
{
    int x = 0;
    short int y = 32767;
    
    printf("Tamanho de um int na memória: %lu bytes\n", sizeof(x));
    printf("Tamanho de um short int na memória: %lu bytes\n", sizeof(y));
    
    
    return(0);
}
