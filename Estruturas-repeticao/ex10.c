#include <stdio.h>
#include <stdlib.h>


/*


                                                Exercicio 10
                                                
                            Você deciciu ficar rico guardando dinheiro por 30 dias consecutivos. Para tal, decidiu guardar 1
                            centavo no primeiro dia, 2 centavos no segundo dia, 4 centavos no terceiro dia, 8 centavos no quarto
                            dia, e assim por diante. Faça um programa para calcular quanto você terá ao final dos 30 dias.
                            
                            Primeira versão. Menos eficiente. Segunda versão está no arquivo ex10.1.c

*/

int main()
{
    int x, quantia = 0, total = 0;
    
    for (x = 1; x <= 30; x++)
    {
        if (x == 1)
        {
            quantia += 1;
            total += quantia;
        }
        else
        {
            quantia *= 2;
            total += quantia;
            
        }
    }
    
    printf("\nValor em centavos: %d\n", total);
    printf("\nValor em reais: R$%.2f\n", total / 100.0);
    
    return(0);
}
