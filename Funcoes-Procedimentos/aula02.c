#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*


                                                    Aula 2
                                                    
                                Criando uma função que retorna o tamanho de uma string.

*/

int minhaStrLen(char str[])
{
    int tam = 0;
    
    while (str[tam] != '\0')
    {
        tam++;
    }
    
    return(tam);
}

int main()
{
    char vet[20] = {"Ola. Bom dia!"};
    
    printf("strlen: %lu\n", strlen(vet));
    printf("minhaStrLen: %d\n", minhaStrLen(vet));
    
    return(0);
}
