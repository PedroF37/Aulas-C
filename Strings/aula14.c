#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*


                                        Aula 14
                                        
                        Matriz de Strings na linguagem C
                        
                        Matriz de String, podemos indicar apenas as linhas, normalmente, não precisa da coluna

*/

int main()
{
    char nomes[5][25];
    int l;
    
    for (l = 0; l < 5; l++)
    {
        printf("Digite o nome da posição %d: ", l);
        scanf("%25[^\n]", nomes[l]);    // ou pudemos usar o fgets(), a vantagem é que a fgets() lê o enter também,
                                        // logo não precisa do getchar();
        getchar();
    }
    
    for (l = 0; l < 5; l++)
    {
        printf("\nNome na posição %d: %s\n", l, nomes[l]);
    }
    
    
    return(0);
}
