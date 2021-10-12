#include <stdio.h>
#include <stdlib.h>


/*


                                            Exercicio 6
                                            
                         Faça um programa para lêr do teclado uma quantidade de segundos e imprimir na tela
                         a conversão para horas, minutos e segundos.
                         Exemplo:
                         
                         Entrada: 3672
                         Saída: 1:1:12
                         
                         hora = 60 minutos -> 60 * 60 -> 3600 segundos
                         minuto = 60 segundos

*/

int main()
{
    int valor, segundos, horas, minutos;
    
    printf("Digite o valor dos segundos: ");
    scanf("%d", &valor);
    
    horas = valor / 3600;
    minutos = (valor % 3600) / 60;
    segundos = valor % 60;
    
    printf("\nO valor %d convertido em horas, minutos e segundos, dá: %d:%d:%d\n", valor, horas, minutos, segundos);
    
    
    return(0);
}
