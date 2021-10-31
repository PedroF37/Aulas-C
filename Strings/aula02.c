#include <stdio.h>
#include <stdlib.h>

/*


                                        Aula 2
                                        
                          Lendo uma String com a função scanf()
                          scanf("%80[^\n]", str);

*/

int main()
{
    char palavras[100] = {"Oi. Vamos aprender a programar com a linguagem C?"};
    
    printf("Digite seu nome: ");
    scanf("%100[^\n]", palavras);
    
    printf("%s\n\n", palavras);
}
