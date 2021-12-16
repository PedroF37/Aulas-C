#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*


                                                    Aula 3
                                                    
                                Criando um procedimento para imprimir uma string.

*/

void imprimeString(char str[])
{
    int index = 0;
    
    while (str[index] != '\0')
    {
        printf("%c", str[index]);
        index++;
    }
    printf("\n");
}

int main()
{
    char vet[20] = {"Ola. Bom dia!"};
    imprimeString(vet);
    
    return(0);
}
