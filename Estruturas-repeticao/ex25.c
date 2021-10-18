#include <stdio.h>
#include <stdlib.h>

/*


                                                    Exercicio 25
                                                    
                             Escreva um programa que leia dois valores X e Y. A seguir, mostre uma sequência de 1 até Y,
                             passando para a próxima linha a cada X números.
                             
                             Exemplo de entrada:
                             
                             3 99
                             
                             Exemplo de saída:
                             
                             1 2 3
                             4 5 6
                             7 8 9
                             10 11 12
                             
                             ...
                             
                             97 98 99

*/

int main()
{
    int x, termino, salto;
    
    printf("Digite o valor do salto e o término, (ex: 3 99): ");
    scanf("%d%d", &salto, &termino);
    
    for (x = 1; x <= termino; x++)
    {
        printf("%3d ", x);
        
        if (x % salto == 0)
            printf("\n");
    }
    
    
    return(0);
}
