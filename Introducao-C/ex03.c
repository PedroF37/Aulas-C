#include <stdio.h>
#include <stdlib.h>


/*


                                        Exercicio 3

                    Escreva um programa que leia um valor de despesa de restaurante, o valor da gorjeta (em
                    porcentagem) e o número de pessoas para dividir a conta. Imprima o valor que cada um deve pagar.
                    Assuma que a conta será dividida igualmente.

*/

int main()
{
    int pessoas;
    float despesa, gorjeta, porcentagem, total;
    
    printf("Digite o valor da despesa: ");
    scanf("%f", &despesa);
    
    printf("Digite a porcentagem de gorjeta dada: ");
    scanf("%f", &gorjeta);
    
    printf("Quantas pessoas irão dividir a conta: ");
    scanf("%d", &pessoas);
    
    porcentagem = gorjeta / 100 * despesa;
    total = (despesa + porcentagem) / pessoas;
    
    printf("\nA despesa total, contando com a gorjeta foi: R$%.2f\n", despesa + porcentagem);
    printf("Dividindo por %d pessoas dará R$%.2f a cada uma.\n", pessoas, total);
    
    
    return(0);
}
