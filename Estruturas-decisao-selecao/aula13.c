#include <stdio.h>
#include <stdlib.h>


/*


                                                Aula 13
                                                
                                      Estrutura de seleção switch case com caractere


*/

int main()
{
    char opcao;
    
    printf("a - Cadastrar produto\nb - Vender produto\nb - Buscar produto\nd - Imprimir\nz - Sair\n");
    scanf("%c", &opcao);
    
    switch(opcao)
    {
        case 'a':
            printf("\nCadastrando novo produto.\n");
            break;
        case 'b':
            printf("\nVendendo um novo produto.\n");
            break;
        case 'c':
            printf("\nBuscando novo produto.\n");
            break;
        case 'd':
            printf("\nImprimindo relatório.\n");
            break;
        case 'z':
            printf("\nSaindo...\n");
            break;
        default:
            printf("\nOpção inválida!\n");
    }
    
    
    
    
    return(0);
}
