#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*


                                        Aula 10
                                        
                         Copiando uma string com a função strcpy()
                         
                         Sem função:
                         
                         Percorremos o array até achar o '\o';

*/

int main()
{
    char palavra1[50] = {"Oi"};
    char palavra2[50] = {"Bom"};
    
    printf("\nAntes de copiar:\npalavra1: %s\npalavra2: %s\n", palavra1, palavra2);
    
    strcpy(palavra2, palavra1);
    
    printf("\nDepois de copiar:\npalavra1: %s\npalavra2: %s\n", palavra1, palavra2);
    
    return(0);
}
