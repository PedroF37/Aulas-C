#include <stdio.h>
#include <stdlib.h>

/*


                                        Aula 3
                                        
                          Lendo uma String com a função gets()
                          
                          Função Insegura. Não usar!!

*/

int main()
{
    char palavras[10] = {"Oi. Vamos aprender a programar com a linguagem C?"};
    
    printf("Digite seu nome: ");
    gets(palavras);
    
    printf("%s\n\n", palavras);
}
