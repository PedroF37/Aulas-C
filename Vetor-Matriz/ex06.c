#include <stdio.h>
#include <stdlib.h>

/*


                                                Exercicio 6
                                                
                              Faça um programa que lê 10 números reais e os armazene em um vetor. Em seguida, leia um
                              código inteiro e faça uma das ações abaixo:
                              
                              0 - finaliza o programa;
                              1 - imprime o vetor na ordem do início ao fim;
                              2 - imprime o vetor na ordem inversa (do fim para o início)
                              
                              O programa deve funcionar até que o usuário digite 0 para finlizar.

*/

int main()
{
    int i, opcao;
    float nums[10];
    
    
     for (i = 0; i < 10; i++)
     {
        printf("Digite o valor #%d: ", i + 1);
        scanf("%f", &nums[i]);
     }
    

    do
    {
       
        
        printf("\n0 - Terminar\n1 - Imprimir do principio ao fim\n2 - Imprimir do fim para o principio\n\n");
        scanf("%d", &opcao);
        
        switch (opcao)
        {
            case 0:
                printf("\nTerminando programa...\n");
                break;
            case 1:
                printf("\nImprimindo do inicio ao fim...\n");
                
                for (i = 0; i < 10; i++)
                    printf("%.2f ", nums[i]);
                printf("\n");
                break;
            case 2:
                printf("\nImprimindo do fim para o inicio...\n");
                
                for (i = 9; i >= 0; i--)
                    printf("%.2f ", nums[i]);
                printf("\n");
                break;
            default:
                printf("\nOpção inválida. Escolha outra opção..\n");
        }
    }
    while (opcao != 0);
    
    return(0);
}
