#include <stdio.h>
#include <stdlib.h>


/*


                                                    Exercicio 20
                                                    
                         Uma rainha requesitou os serviços de um monge e disse-lhe que pagaria qualquer preço.
                         O monge, necessitado de alimentos, indagou a rainha sobre o pagamento, se poderia ser
                         feito com grãos de trigo dispostos em um tabuleiro de xadrez (que possui 64 casas), de
                         tal forma que o primeiro quadro deveria conter apenas um grão e os quadros subsequentes
                         o dobro do quadro anterior. Crie um programa para calcular o total de grãos de trigo
                         que o monge recebeu.

*/

int main()
{
    int x;
    long double grao = 1, total = 1;
    
    for (x = 2; x <= 64; x++)
    {
        grao *= 2;
        total += grao;

    }
    
    printf("\nAo final do serviço, o monge terá um total de: %Lf grãos\n", total);  // Windows -> __mingw_printf(); ao invés do printf();
    
    return(0);
}
