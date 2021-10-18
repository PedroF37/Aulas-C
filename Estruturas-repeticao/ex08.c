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
    int escolha;
    

    do
    {
        printf("\nEscolha a operação:\n\n1 - Somar\n2 - Subtrair\n3 - Multiplicar\n4 - Dividir\n0 - Sair\n\n");
        scanf("%d", &escolha);
        
        if (escolha > 0 && escolha < 5)
        {
            printf("\nDigite dois valores: ");
            scanf("%f%f", &num1, &num2);
        }
        
        
        switch (escolha)
        {
            case 0:
                printf("\nTerminando programa.\n");
                break;
            case 1:
                printf("Soma: %.1f\n", num1 + num2);
                break;
            case 2:
                printf("Subtração: %.1f\n", num1 - num2);
                break;
            case 3:
                printf("Multiplicação: %.1f\n", num1 * num2);
                break;
            case 4:
                while (num2 == 0.0)
                {
                    printf("\nNão pode dividir por zero.\nDigite outro valor: ");
                    scanf("%f", &num2);
                }
                
                printf("Divisão: %.1f\n", num1 / num2);
                break;
            default:
                printf("\nOpção inválida.\nEscolha outra opção.\n");

        }
        
    }
    while (escolha != 0);
    
    return(0);
}
