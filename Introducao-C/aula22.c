#include <stdio.h>
#include <stdlib.h>


/*


                                            Aula 29
                                        Operador unsigned
                                        
                                        unsigned int -> %u
                                        unsigned short int -> %d ou %d
                                        unsigned long int -> %lu
                                        
                                        
                                        limite para o tipo int: 2.147.483.647 -> positivo, com sinal 
                                        
                                        4 bytes = 4 * 8 = 32 bits -> signed usa 31 bits para o valor e 1 bit para o sinal
                                        
                                        Com o unsigned, o computador não reserva o bit á esquerda para armazenar o sinal,
                                        logo todos os valores são positivos apenas e logo temos mais um bit disponivel, o que
                                        quer dizer que armazenamos valores positivos maiores do que com 'signed'.
                                        
                                        4 bytes = 4 * 8 = 32 bits -> unsigned não usa sinal; é sempre positivo, então usar os 32 bits todos, os 4 bytes completos.
                                        
                                        Os valores vao de 0 até 4.294.967.295
*/

int main()
{
    int x = 2147483647;
    unsigned int y = 2147483647;
    
    short int z = 55000;    // short int -> 2 bytes -> 16 bits apenas na memória. Este valor de 55000 ocuma mais do que 16 bits
    unsigned short int t = 55000;   // %hu ou %d;
    
    printf("\n\t%d\n\n", ++x);  // vai dar valor negativo, porque não o valor já está no limite.
    printf("\n\t%u\n\n", ++y);  // aqui vai funcionar normal, porque y é unsigned, então tem um intervalo maior.
    printf("\n\t%d\n\n", z);    // -10536 -> passou do limite do short int
    printf("\n\t%d\n\n", t);    // 55000 -> unsigned short int; está no range
    
    return(0);
}
