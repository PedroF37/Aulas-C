#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*


                                            Aula 15
                                            
                         Lêr uma palavra e vêr se é palindroma
                         
                         ama 
                         arara
                         asa
                         osso
                         radar
                         reviver
                         reviver
                         socos

*/

int main()
{
    char palavra[30], replica[30];
    int i, tamanho = 0, igual = 0;
    
    printf("Digite uma palavra: ");
    scanf("%s", palavra);   // se usar o fgets() temos que remover o \n
    
    for (i = 0; palavra[i] != '\0'; i++)
    {
        replica[i] = palavra[i];
        tamanho++;  // podia ter usado o strlen() mas quis fazer do jeito burrinho kk!
    }
    
    /* Debug */
    printf("Original: %s\nCópia: %s\n", palavra, replica);

   
    for (i = 0; palavra[i] != '\0'; i++)
    {
        if (replica[tamanho - i - 1] == palavra[i])
        {
            igual++;
        }
    }
    

    if (igual == tamanho)
        printf("\nÉ um palindrome\n");
    else
        printf("\nNão é um palindrome\n");

    return(0);
}
