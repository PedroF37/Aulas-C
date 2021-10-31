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
    char palavra[30];
    // char replica[30];
    int i, tamanho, igual = 0;
    
    printf("Digite uma palavra: ");
    scanf("%s", palavra);   // se usar o fgets() temos que remover o \n
    
    tamanho = strlen(palavra);
    tamanho--;
    i = 0;
    
    while (tamanho >= i)
    {
        if (palavra[i] != palavra[tamanho])
            igual++;
        
        i++;
        tamanho--;
    }
    
    if (igual == 0)
        printf("Palindroma\n");
    else
        printf("Não é palindroma\n");
    
    /*
    tamanho = strlen(palavra);
    for (i = 0; i < strlen(palavra); i++)
    {
        replica[i] = palavra[tamanho - 1];
        tamanho--;
    }
    replica[i] = '\0';
    
    printf("Original: %s\nCopia: %s\n", palavra, replica);
    
    tamanho = strlen(palavra);
    for (i = 0; i < tamanho; i++)
    {
        if (palavra[i] == replica[i])
            igual++;
    }
    
    if (tamanho == igual)
        printf("\nÉ Palindroma\n");
    else
        printf("\nNão é palindroma\n");
    
    */
    
    return(0);
}
