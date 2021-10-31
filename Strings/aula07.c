#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*


                                        Aula 7
                                        
                         Como descobrir o tamanho de uma string com a função strlen()?

*/

int main()
{
    //int tam;
    char palavras[55] = {"Oi. Vamos aprender a programar com a linguagem C?"};
   
    // printf("Digite seu nome: ");
    // fgets(palavras, 15, stdin);
    
    //tam = strlen(palavras);
    printf("Tamanho da string: %lu\n", strlen(palavras)); // na minha máquina pede %lu ao invés de %d
    
    
    return(0);
}
