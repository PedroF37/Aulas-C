#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*


                                                    Aula 16
                                                    
                                        Lêr uma frase e dizer se é palindroma
                                        
                                        Exemplos:
                                        
                                        roma me tem amor
                                        a grama é amarga -> agramaeamarga
                                        anotaram a data da maratona
                                        a mãe te ama
                                        a torre da derrota
                                        a sacada da casa
                                        luz azul

*/

int main()
{
    char frase[50], copia[50];
    int i, j = 0, tamanho, diferente = 0;
    
    printf("Digite uma frase: ");
    scanf("%50[^\n]", frase);
    
    /* remover => !? ,;. */
    for (i = 0; i < strlen(frase); i++)
    {
        if (frase[i] != '!' && frase[i] != '?' && frase[i] != ' ' && frase[i] != '.')
        {
            copia[j] = frase[i];
            j++;    // podia fazer => copia[j++] = frase[i]; aí não precisava das chaves
        }
    }
    
    copia[j] = '\0';
    
    //printf("Original: %s\nCópia: %s\n", frase, copia);
    
    tamanho = strlen(copia);
    tamanho--;
    for (i = 0; i < strlen(copia); i++)
    {
        if (copia[i] != copia[tamanho])
            diferente++;
        
        tamanho--;
    }
    
    if (diferente == 0)
        printf("\nÉ palindroma\n");
    else
        printf("\nNão é palindroma\n");
    
    return(0);
}
