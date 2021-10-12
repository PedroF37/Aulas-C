#include <stdio.h>
#include <stdlib.h>


/*


                                        Exercicio 4

                         Uma empresa contrata um encanador a R$45,00 por dia. Faça um programa que peça o
                         número de dias trabalhados pelo encanador e que imprima a quantia líquida  que deve ser
                         paga, sabendo que são descontados 8% para o imposto de renda.

*/

int main()
{
    int dias;
    float quantia, desconto, total;
    
    printf("Digite os dias trabalhados: ");
    scanf("%d", &dias);
    
    quantia = 45.00 * dias;
    desconto = 8.0 / 100 * quantia; // ou (float) 8 / 100;
    total = quantia - desconto;
    
    printf("\nO valor total a pagar serão %.2f\n", total);
    
    return(0);
}
