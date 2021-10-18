#include <stdio.h>
#include <stdlib.h>

/*


                                Exercicio 17
                                
                 Faça um programa peça números ao usuário. Quando o usuário digitar o número 0 (zero) o
                 programa deve imprimir na tela quantos números positivos e negativos foram digitados.

*/

int main()
{
    int num, positivo = 0, negativo = 0;
    
    do
    {
        printf("Digite um valor (0 para terminar): ");
        scanf("%d", &num);
        
        if (num < 0)
            negativo++;
        else if (num > 0)
            positivo++;
    }
    while (num != 0);
    
    printf("Positivos: %d\n", positivo);
    printf("Negativos: %d\n", negativo);

    
    return(0);
}
