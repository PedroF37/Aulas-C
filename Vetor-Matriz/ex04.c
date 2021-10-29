#include <stdio.h>
#include <stdlib.h>


/*


                                                    Exercicio 4
                                                    
                               Uma pequena loja de artesanado possui apenas um vendedor e comercializa 10 tipos de objetos
                               diferentes. O vendedor recebe um salário de R$1100.00 acrescido de 5% do valor total de suas
                               vendas. O valor unitário dos objetos deve ser informado e armazenado em um vetor; a quantidade
                               vendida de cada objeto deve ficar em outro vetor, mas na mesma posição. Crie um programa que
                               receba os preços e as quantidades vendidas, armazenando-os em seus repectivos vetores. Depois,
                               determine e mostre:
                               
                               a) A quantidade vendida, valor unitário e valor total de cada objeto. Ao final, deverão ser mostrados
                               o valor total das vendas e o valor da comissão que será paga ao vendedor.
                               
                               b) O valor do objeto mais vendido e sua posição no vetor (em caso de empate mostre todos os empatados).
                               
                                                  i      j 
                               Quantidade         10 20 10 20 5 20
                               valor              15 30 20 45 62 70

*/

int main()
{
    int i, quant[10], maisVendido = 0;
    float valor[10], valorParcial, valorTotal = 0, comissao;
    
    for (i = 0; i < 10; i++)
    {
        printf("Digite o valor unitário e a quantidade vendida: ");
        scanf("%f%d", &valor[i], &quant[i]);
    }
    
    /* letra a */
    for (i = 0; i < 10; i++)
    {
        valorParcial = quant[i] * valor[i];
        printf("Vendido: %d\tValor unitário: R$%.2f\tValor total: R$%.2f\n", quant[i], valor[i], valorParcial);
        valorTotal += valorParcial;
    }
    
    comissao = (5.0 / 100.0) * valorTotal;
    printf("\nValor Total das vendas: R$%.2f\n", valorTotal);
    printf("Comissão paga ao vendedor: R$%.2f\n", comissao);
    
    /* letra b */
    for (i  = 0; i < 10; i++)
    {
        if (quant[i] > maisVendido)
            maisVendido = quant[i];
    }
    
    for (i = 0; i < 10; i++)
    {
        if (quant[i] == maisVendido)
            printf("Posição: %d\tValor: R$%.2f\n", i, valor[i]);
    }
    
    return(0);
}
