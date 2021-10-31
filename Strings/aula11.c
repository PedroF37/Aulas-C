#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*

                                                    Aula 11
                                                    
                               Procurando caracteres em uma String com as funções strchr e srtrchr
                               
                               strchr  ->  retorna a primeira ocorrência
                               strrchr ->  retorna a última ocorrência

*/

int main()
{
    char palavra[50] = {"abacate"};
    char *letra;
    char *letra2;
    
    letra = strchr(palavra, 'a');
    
    printf("\n%c\n", *letra);
    printf("\n%c\n", *(letra + 1));
    printf("\n%c\n", *(letra + 2));
    
    letra2 = strrchr(palavra, 'a');
    
    printf("\n%c\n", *letra2);
    printf("\n%c\n", *(letra2 + 1));
    printf("\n%c\n", *(letra2 + 2));
    
    
    
    return(0);
}
