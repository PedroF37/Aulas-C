#include <stdio.h>
#include <stdlib.h>


/*


                                        Exercicio 7
                                        
                        Faça um programa que peça ao usuário um caractere e diga se é uma vogal ou não.

*/

int main()
{
    char letra;
    
    printf("Digite uma letra: ");
    scanf("%c", &letra);
    
    if (letra == 'a' || letra == 'e' ||letra == 'i' || letra == 'o' || letra == 'u' ||
        letra == 'A' || letra == 'E' || letra == 'I' || letra == 'O' || letra == 'U')
        
        printf("\nVogal\n");
    else
        printf("\nNão é vogal\n");
    
    // Podemos fazer com switch case também
    
    return(0);
}
