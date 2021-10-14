#include <stdio.h>
#include <stdlib.h>


/*


                                                Aula 12
                                                
                                      Estrutura de seleção switch case


*/

int main()
{
    int opcao;
    
    printf("1 - Cadastrar produto\n2 - Vender produto\n3 - Buscar produto\n4 - Imprimir\n5 - Sair\n");
    scanf("%d", &opcao);
    
    switch(opcao)
    {
        case 1:
            printf("\nCadastrando novo produto.\n");
            break;
        case 2:
            printf("\nVendendo um novo produto.\n");
            break;
        case 3:
            printf("\nBuscando novo produto.\n");
            break;
        case 4:
            printf("\nImprimindo relatório.\n");
            break;
        case 5:
            printf("\nSaindo...\n");
            break;
        default:
            printf("\nOpção inválida!\n");
    }
    
    
    
    
    return(0);
}
