#include <stdio.h>
#include <stdlib.h>


/*


                                            Exercicio 3
                                            
                             Escrever um programa que lê um vetor N de tamanho 20 e o imprime na tela. Em seguida, troque
                             o 1º elemento com o último, o 2º elemento com o penúltimo,... até o 10º com o 11º. Imprima
                             o vetor N modificado.

                             1 2 3 4 5 6
                             2 1 3 4 5 6
                             3 1 2 4 5 6
                             4 1 2 3 5 6
                             5 1 2 3 4 6
                             6 1 2 3 4 5
                             
                             6 1 2 3 4 5
                             6 2 1 3 4 5
                             6 3 1 2 4 5
                             6 4 1 2 3 5
                             6 5 1 2 3 4
                             
                             .........
                             
                             6 5 4 3 2 1
*/

int main()
{
    int i, j, temp, vetorN[20];
    
    for (i = 0; i < 20; i++)
    {
        printf("Digite o valor #%d de %d: ", i + 1, 20);
        scanf("%d", &vetorN[i]);
    }

    printf("\nOriginal:\n");
    for (i = 0; i < 20; i++)
        printf("%d ", vetorN[i]);
    
    
    printf("\n\n");
    
    for (i = 0; i < 20; i++)
    {
        for (j = i + 1; j < 20; j++)
        {
            temp = vetorN[j];
            vetorN[j] = vetorN[i];
            vetorN[i] = temp;
        }
    }
  
    
    printf("\n\nTrocado\n");
    for (i = 0; i < 20; i++)
        printf("%d ", vetorN[i]);
    
    printf("\n");
    
    return(0);
}
