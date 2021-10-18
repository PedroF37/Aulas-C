#include <stdio.h>
#include <stdlib.h>


/*


                                                Exercicio 19
                                
                         Escreva um programa para lêr as coordenadas (X,Y) de uma quantidade indeterminada de
                         pontos no sistema cartesiano. Para cada ponto escrever o quadrante a que ele pertence.
                         O algoritmo será encerrado quando pelo menos uma de duas coordenadas for NULA (nesta situação
                         sem escrever mensagem alguma).
                         
                         Exemplo de entrada:
                         2 2
                         3 -2
                         -8 -1
                         -7 1
                         0 2
                         
                         Exemplo de saída:
                         primeiro
                         quarto
                         terceiro
                         segundo

*/

int main()
{
    int x, y;

    
    do
    {
        printf("Digite as duas coordenadas X e Y: ");
        scanf("%d%d", &x, &y);
        
        if (x > 0 && y > 0)
            printf("\nPrimeiro quadrante\n");
        
        else if (x > 0 && y < 0)
            printf("\nQuarto quadrante\n");
        
        else if (x < 0 && y < 0)
            printf("\nTerceiro quadrante\n");
        
        else if (x < 0 && y > 0)
            printf("\nSegundo quadrante\n");
        
    }
    while (x != 0 && y != 0);
    
    
    return(0);
}
