#include <stdio.h>
#include <stdlib.h>

/*


                                        Aula 6
                                        
                         Como descobrir o tamanho de uma string?

*/

int main()
{
    int i, tamanho = 0;
    char palavras[55] = {"Oi. Vamos aprender a programar com a linguagem C?"};
    // printf("Digite seu nome: ");
    // fgets(palavras, 15, stdin);
    
    for (i = 0; palavras[i] != '\0'; i++)
        tamanho++;
    
    printf("O tamanho da string é: %d\n", tamanho);
    
    printf("\n");
    
    // Ou...
    i = 0;
    tamanho = 0; // por causa do tamanho no loop for kkk
    while(palavras[i] != '\0')
    {
        tamanho++;
        i++;
    }
    
    printf("O tamanho da string é: %d\n", tamanho);
    
    // Ou:
    
    i = 0;
    tamanho = 0;
    while (palavras[i])
    {
        tamanho++;
        i++;
    }
    
    printf("\nO tamanho da string é: %d\n", tamanho);
    
    return(0);
}
