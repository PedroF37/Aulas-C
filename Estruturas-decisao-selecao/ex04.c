#include <stdio.h>
#include <stdlib.h>


/*


                                            Exercicio 4
                                            
                         Crie um programa que permita ao usuário escolher entre fazer a conversão de Real para Dólar
                         ou Dólar para Real. Utilize como taxa de câmbio US$1 igual a R$5.30.

*/

int main()
{
    int escolha;
    float conversao, quantia;
    
    printf("1. Converter de Real para Dólar\n2. Converter de Dólár para Real\n");
    scanf("%d", &escolha);
    
    if (!(escolha == 1 || escolha == 2))
        printf("\nInput inválido!\n");
    else
    {
        printf("Digite a quantia para converter: ");
        scanf("%f", &quantia);
    
    
        if (escolha == 1)
        {
            conversao = quantia / 5.30;
            printf("\nCom a quantia de R$%.2f, você terá US$%.2f.\n", quantia, conversao);
        }
        else if (escolha == 2)
        {
            conversao = quantia * 5.30;
            printf("\nCom a quantia de US$%.2f, você terá R$%.2f.\n", quantia, conversao);
        }
    }
    return(0);
}
