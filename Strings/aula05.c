#include <stdio.h>
#include <stdlib.h>

/*


                                        Aula 5
                                        
                         Como identificar o fim de uma string?

*/

int main()
{
    int i;
    char palavras[55] = {"Oi. Vamos aprender a programar com a linguagem C?"};
    // printf("Digite seu nome: ");
    // fgets(palavras, 15, stdin);
    
    i = 0;
    while (palavras[i] != '\0')
    {
        printf("%d = %c\n", i, palavras[i]);    // ou palavras[i++] -> incrento á direita, imprime primeiro o valor e depois incrementa..
        i++;                                    // mas o meu compilador berra que nem uma vaca louca se fizer isso assim...
    }
    printf("\n");
    
    // ou:
    for (i = 0; palavras[i] != '\0'; i++)
        printf("%d = %c\n", i, palavras[i]);
    printf("\n");
}
