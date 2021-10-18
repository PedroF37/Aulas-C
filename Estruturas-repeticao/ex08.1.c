#include <stdio.h>
#include <stdlib.h>

/*


                                        Exercicio 8
                                        
                       Escreva um programa em C que funcione como uma calculadora. O programa deve apresentar
                       um menu ao usuário da seguinte forma:
                       
                       1 - Somar
                       2 - Subtrair
                       3 - Multiplicar
                       4 - Dividir
                       0 - Sair
                       
                       Uma estrutura do tipo switch case deve ser utilizada para realizar cada operação em um case. Após a
                       escolha da operação, dois valores devem ser pedidos ao usuário para realizar a operação escolhida.
                       Se a operação escolhida for a 4, o dividendo não pode ser zero, um novo valor deve ser solicitado.
                       O programa deve funcionar até que o usuário escolha a opção 0 (opção de saída).

*/

int main()
{
    float num1, num2;
    int escolha = 9;
    
    while (escolha != 0)
    {
        printf("1 - Soma\n2 - Subtração\n3 - Multiplicação\n4 - Divisão\n0 - Sair\n\n");
        scanf("%d", &escolha);
        
        if (escolha > 0 && escolha < 5)
        {
            printf("Digite os dois valores: ");
            scanf("%f%f", &num1, &num2);
        }
        
        
        switch (escolha)
        {
            case 0:
                printf("\nTerminando programa.\n");
                break;
            case 1:
                printf("\nSoma: %.2f + %.2f = %.2f\n", num1, num2, num1 + num2);
                break;
            case 2:
                printf("\nSubtração: %.2f - %.2f = %.2f\n", num1, num2, num1 - num2);
                break;
            case 3:
                printf("\nMultiplicação: %.2f * %.2f = %.2f\n", num1, num2, num1 * num2);
                break;
            case 4:
                while (num2 == 0.0)
                {
                    printf("\nDivisão não pode ser por zero.\nDigite outro valor: ");
                    scanf("%f", &num2);
                }
                printf("\nDivisão: %.2f / %.2f = %.2f\n", num1, num2, num1 / num2);
                break;
            default:
                printf("\nOpção inválida.\nEscolha outra opção.\n");
        }
    }
    
    
    return(0);
}
