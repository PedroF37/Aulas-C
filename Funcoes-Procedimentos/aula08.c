#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*


                                                        Aula 8
                                                        
                                           Como converter número para texto em C?
                                           
                                           sprintf(onde-salvar, formatação, de-onde-vem);
                                           snprintf(onde-salvar, número-de-carateres, formatação, de-onde-vem);
                                           
                                           sprintf() não verifica a quanntitade máxima de caracteres
                                           snprintf() verifica a quantidade máxima de caracteres usando o segundo parâmetro.

*/

int main()
{
    int tam;
    char str1[10] = {"%"}, str2[10];
    
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tam);
    getchar();
    
    //sprintf(str2, "%d[^\n]", tam);
    snprintf(str2, 10, "%d[^\n]", tam);
    strcat(str1, str2);
    
    printf("%s\n", str2);

    char palavras[tam];
    
    printf("Digite uma frase: ");
    scanf(str1, palavras);
    printf("%s\n", palavras);
    
    return(0);
}
