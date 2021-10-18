#include <stdio.h>
#include <stdlib.h>


/*


                                                Exercicio 16
                                                
                                 Faça um programa para encontrar o menor número inteiro que seja divisível por
                                 todos os números inteiros entre 1 e 10.
                                 
                                 

*/

int main()
{
    int x, divisor, valor = 8; // entre 1 e 9 não tem nenhum número que seja divisivel por 10.
    
    do
    {
        divisor = 0;
        valor += 2;
        
        for (x = 1; x <= 10; x++ )
            if (valor % x == 0)
                divisor++;
    }
    while (divisor != 10);
    
    printf("Valor: %d\n", valor);
    
    return(0);
}
