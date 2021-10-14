#include <stdio.h>
#include <stdlib.h>


/*


                                                    Exercicio 1
                                                    
                            Escreva um programa em C que leia três valores e apresente qual é o maior e qual é o menor.

*/

int main()
{
    int num1, num2, num3, maior, menor;
    
    printf("Digite três valores para comparar: ");
    scanf("%d%d%d", &num1, &num2, &num3);
    
    
    maior = num1;
    menor = num1;
   
    if (maior < num2)
        maior = num2;

    if (maior < num3)
        maior = num3;
    
    if (menor > num2)
        menor = num2;
    
    if (menor > num3)
        menor = num3;
        
    
    printf("\nO valor maior é %d, e o valor menor é %d\n", maior, menor);
    
    
    return(0);
}
