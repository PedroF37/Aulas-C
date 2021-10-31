#include <stdio.h>
#include <stdlib.h>

/*


                                        Aula 4
                                        
                          Lendo uma String com a função fgets() - File get String? kk deve ser né? kk
                          
                          fgets(onde-guardar, quantidade-caracters, de-onde-lemos)
                          
                          fgets(palavras, 50, stdin);

*/

int main()
{
    char palavras[15] = {"Oi. Vamos aprender a programar com a linguagem C?"};
    
    printf("Digite seu nome: ");
    fgets(palavras, 15, stdin);
    
    printf("%s\n\n", palavras);
}
