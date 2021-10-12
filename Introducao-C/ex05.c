#include <stdio.h>
#include <stdlib.h>


/*


                                            Exercicio 5
                                            
                      Crie um programa em C, que permite fazer a conversão cambial entre Reais e Dólares.
                      Considere que US$1,0 = R$5,30. Leia um valor em Reais e mostre o correspondente em 
                      Dólares.

*/

int main()
{
    float real, dolar;
    
    printf("Digite o valor em reais: ");
    scanf("%f", &real);
    
    dolar = real / 5.30;
    
    printf("\nCom a quantia de R$%.2f, você tem US$%.2f dólares.\n", real, dolar);
    
    
    return(0);
}
