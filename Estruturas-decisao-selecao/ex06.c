#include <stdio.h>
#include <stdlib.h>


/*


                                        Exercicio 6
                                        
                       Faça um programa para lêr um número inteiro e verificar se corresponde a um mês válido
                       no Calendário. Caso corresponda, escrever o nome do mês, caso contrário, escrever a mensagem
                       'Mês Inválido'.

*/

int main()
{
    int num;
    
    printf("Digite o número do mês: ");
    scanf("%d", &num);
    
    switch (num)
    {
        case 1:
            printf("\nJaneiro\n");
            break;
        case 2:
            printf("\nFevereiro\n");
            break;
        case 3:
            printf("\nMarço\n");
            break;
        case 4:
            printf("\nAbril\n");
            break;
        case 5:
            printf("\nMaio\n");
            break;
        case 6:
            printf("\nJunho\n");
            break;
        case 7:
            printf("\nJulho\n");
            break;
        case 8:
            printf("\nAgosto\n");
            break;
        case 9:
            printf("\nSetembro\n");
            break;
        case 10:
            printf("\nOutubro\n");
            break;
        case 11:
            printf("\nNovembro\n");
            break;
        case 12:
            printf("\nDezembro\n");
            break;
        default:
            printf("\nMês inválido\n");
    }
    
    return(0);
}
