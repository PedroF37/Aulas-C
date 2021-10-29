#include <stdio.h>
#include <stdlib.h>


/*


                                                    Exercicio 1
                                                    
                             Faça um programa que preencha um vetor de inteiros de tamanho 10 pedindo valores ao usuário.
                             Em seguida, calcule e salve em um segundo vetor, o quadrado de cada elemento do primeiro vetor.
                             Por fim, imprima os dois vetores.

*/

int main()
{
    int i, numeros1[10], numeros2[10];
    
    for (i = 0; i < 10; i++)
    {
        printf("Digite o valor #%d: ", i + 1);
        scanf("%d", &numeros1[i]);
        
        numeros2[i] = numeros1[i] * numeros1[i];
    }
    
    printf("\nOriginal:\n");
    for (i = 0; i < 10; i++)
        printf("%3d ", numeros1[i]);
    
    printf("\n\n");
    
    printf("\nAo quadrado:\n");
    for (i = 0; i < 10; i++)
        printf("%3d ", numeros2[i]);
    
    printf("\n\n");
    
    
    return(0);
}
