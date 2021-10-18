#include <stdio.h>
#include <stdlib.h>

/*


                                            Exercicio 15
                                            
                           Faça um programa que peça ao usuário dois números inteiros e apresente o resultado
                           da multiplicação entre os dois números sem utilizar a operação de multiplicação.
                           
                           num1 = 2
                           num2 = 3
                           
                           2 + 2 + 2 = 6 / = 2 * 3 = 6 

*/

int main()
{
    int x, num1, num2, resultado = 0;
    
    printf("Digite dois números inteiros: ");
    scanf("%d%d", &num1, &num2);
    
    for (x = 1; x <= num2; x++)
    {
        resultado += num1;
    }
    
    printf("Resultado: %d\n", resultado);
    
    
    
    return(0);
}
