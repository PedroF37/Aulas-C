#include <stdio.h>
#include <stdlib.h>


/*
 
                                                Aula 5
                                          Lendo caracteres

                                          
*/

int main()
{
    char sexo = 'k';
    
    // printf("Valor da variável sexo: %c\n", sexo);
    
    printf("Digite seu sexo: (f, F, m, M) ");
    scanf("%c", &sexo);
    
    printf("Valor da variável sexo: %c\n", sexo);
    return(0);
}
