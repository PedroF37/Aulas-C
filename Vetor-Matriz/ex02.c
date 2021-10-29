#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/*


                                                Exercicio 2
                                                
                              Faça um programa que some o conteúdo de dois vetores de tamanho 25 e armazene o
                              resultado em um terceiro vetor. Imprima os três vetores na tela.

*/

int main()
{
    int i, vetorA[25], vetorB[25], vetorC[25];
    
    srand(time(NULL));
    
    for (i = 0; i < 25; i++)
    {
        vetorA[i] = 1 + rand() % 100;
        vetorB[i] = 1 + rand() % 100;
        vetorC[i] = vetorA[i] + vetorB[i];
    }
    
    printf("\nVetor A: ");
    
    for (i = 0; i < 25; i++)
        printf("%3d ", vetorA[i]);
    
    printf("\n");
    printf("\nVetor B: ");
    
    for (i = 0; i < 25; i++)
        printf("%3d ", vetorB[i]);
    
    printf("\n");
    printf("\nVetor C: ");
    
    for (i = 0; i < 25; i++)
        printf("%3d ", vetorC[i]);
    
    printf("\n");
    
    return(0);
}
