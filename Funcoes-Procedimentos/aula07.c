#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*


                                                    Aula 7
                                                    
                                  Criar um procedimento para converter uma string para maiúsculo ou minúsculo
                                  
                                  strupr() e strlwr(), funcionam apenas no Windows, porque não fazem parte da
                                  biblioteca padrão do C.

*/

/* Procedimento que converte string para maiúsculo */
void maiusculo(char str1[], char str2[])
{
    int index = 0;
    while (str1[index] != '\0')
    {
        str2[index] = toupper(str1[index]);
        index++;
    }
    str2[index] = '\0';
}

/* Procedimento que converte string para minúsculo */
void minusculo(char str1[], char str2[])
{
    int index = 0;
    while (str1[index] != '\0')
    {
        str2[index] = tolower(str1[index]);
        index++;
    }
    str2[index] = '\0';
}

int main()
{
    char str1[] = "Ola. Bom dia.";
    char str2[50];  // Em vez de copiar a str1 para str2 convertendo para maiúsculo ou minusculo, podiamos simplemente
                    // converter cada caractere na str1 e guardar na mesma str1 sem ter que usar a str2.
    
    printf("%s\n", str1);

    maiusculo(str1, str2);
    printf("%s\n", str2);
    
    minusculo(str1, str2);
    printf("%s\n", str2);

    return(0);
}
