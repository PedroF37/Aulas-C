#include <stdio.h>
#include <stdlib.h>


/*


                                                Exercicio 10
                                                
                            Você deciciu ficar rico guardando dinheiro por 30 dias consecutivos. Para tal, decidiu guardar 1
                            centavo no primeiro dia, 2 centavos no segundo dia, 4 centavos no terceiro dia, 8 centavos no quarto
                            dia, e assim por diante. Faça um programa para calcular quanto você terá ao final dos 30 dias.
                            
                            
                            
                            Se começar a quantia e o total com zero, temos que fazer o teste if no loop
                            para saber se é o primeiro dia ou não. Se for o primeiro dia, então quantia recebe 1;
                            quantia = 0; quantia = quantia + 1;
                            
                            Se não for o primeiro dia, então quantia recebe o que ela tem multiplicado por dois.
                            Tem que ser assim, porque quantia inicia em zero, e zero * 2 é zero.
                            
                            Mas podemos começar a contabilizar logo antes do loop o primeiro dia.
                            Sendo assim, quantia inicia antes mesmo do loop com 1 e o total também.
                            Assim o primeiro dia já está contabilizado, e o loop começa no dia dois,
                            e a quantia vai sendo multiplicada por dois: quantia += 2;
                            
                            

*/

int main()
{
    int x, quantia = 1, total = 1; // primeiro dia dos 30 dias.
    
    for (x = 2; x <= 30; x++)    // primeiro dia já foi, restam 29
    {
            quantia *= 2;
            total += quantia;
    }
    
    printf("\nValor em centavos: %d\n", total);
    printf("\nValor em reais: R$%.2f\n", total / 100.0);
    
    return(0);
}
