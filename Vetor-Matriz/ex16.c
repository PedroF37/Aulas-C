#include <stdio.h>
#include <stdlib.h>

/*

                                                    Exercicio 16
                                                    
                              Faça um programa para jogar o jogo da velha. Ao final imprima o
                              resultado do jogo e pergunte se deseja jogar novamente.

*/

int main()
{
    int l, c, linha, coluna, jogador, ganhou, jogadas, opcao;
    
    /* Estrutura de dados? */
    char jogo[3][3];
    
    do
    {
        jogador = 1;
        ganhou = 0;
        jogadas = 0;
        /* Como inicializar nossa estrutura de dados? */
        for (l = 0; l < 3; l++)
        {
            for (c = 0; c < 3; c++)
            {
                jogo[l][c] = ' ';
            }
        }
        

        do
        {
            /* Imprimir jogo */
            printf("\n\n\t 0   1   2\n\n");
            for (l = 0; l < 3; l++)
            {
                for (c = 0; c < 3; c++)
                {
                    if (c == 0)
                    {
                        printf("\t");
                    }
                    printf(" %c ", jogo[l][c]);
                    
                    if (c < 2)
                    {
                        printf("|");
                    }
                    
                    if (c == 2)
                    {
                        printf("  %d", l);
                    }
                }
                
                if (l < 2)
                {
                    printf("\n\t-----------");
                }
                
                printf("\n");
            }
            
            /* Lêr as cordenadas do jogador */
            do
            {
                printf("\nJOGADOR 1 = 0\nJOGADOR 2 = X\n");
                printf("JOGADOR %d: Digite a linha e coluna que deseja jogar: ", jogador);
                scanf("%d%d", &linha, &coluna);
            }
            while (linha < 0 || linha > 2 || coluna < 0 || coluna > 2 || jogo[linha][coluna] != ' ');
            
            /* Salvar as cordenadas */
            if (jogador == 1)
            {
                jogo[linha][coluna] = '0';
                jogador++;
            }
            else
            {
                jogo[linha][coluna] = 'X';
                jogador = 1;
            }
            
            jogadas++;
            
            /* Ver se alguem ganhou */
            
            /* Ganhou em linha? */
            if ((jogo[0][0] == '0' && jogo[0][1] == '0' && jogo[0][2] == '0') || 
                (jogo[1][0] == '0' && jogo[1][1] == '0' && jogo[1][2] == '0') ||
                (jogo[2][0] == '0' && jogo[2][1] == '0' && jogo[2][2] == '0'))
            {
                printf("\nParabens! O jogador 1 venceu por linha!\n");
                ganhou = 1;
            }
            
            if ((jogo[0][0] == 'X' && jogo[0][1] == 'X' && jogo[0][2] == 'X') || 
                (jogo[1][0] == 'X' && jogo[1][1] == 'X' && jogo[1][2] == 'X') ||
                (jogo[2][0] == 'X' && jogo[2][1] == 'X' && jogo[2][2] == 'X'))
            {
                printf("\nParabens! O jogador 2 venceu por linha!\n");
                ganhou = 1;
            }
            
            /* Ganhou em coluna? */
            if ((jogo[0][0] == '0' && jogo[1][0] == '0' && jogo[2][0] == '0') ||
                (jogo[0][1] == '0' && jogo[1][1] == '0' && jogo[2][1] == '0') ||
                (jogo[0][2] == '0' && jogo[1][2] == '0' && jogo[2][2] == '0'))
            {
                printf("\nParabens! O jogador 1 venceu por coluna!\n");
                ganhou = 1;
            }
            
            if ((jogo[0][0] == 'X' && jogo[1][0] == 'X' && jogo[2][0] == 'X') ||
                (jogo[0][1] == 'X' && jogo[1][1] == 'X' && jogo[2][1] == 'X') ||
                (jogo[0][2] == 'X' && jogo[1][2] == 'X' && jogo[2][2] == 'X'))
            {
                printf("\nParabens! O jogador 2 venceu por coluna!\n");
                ganhou = 1;
            }
            
            /* Ganhou em diagonal principal? */
            if (jogo[0][0] == '0' && jogo[1][1] == '0' && jogo[2][2] == 0)
            {
                printf("\nParabens! O jogador 1 venceu na diagonal principal!\n");
                ganhou = 1;
            }
            
            if (jogo[0][0] == 'X' && jogo[1][1] == 'X' && jogo[2][2] == 0)
            {
                printf("\nParabens! O jogador 2 venceu na diagonal principal!\n");
                ganhou = 1;
            }
            
            /* Ganhou em diagonal secundária? */
            if (jogo[0][2] == '0' && jogo[1][1] == '0' && jogo[2][0] == '0')
            {
                printf("\nParabens! O jogador 1 venceu na diagonal secundária!\n");
                ganhou = 1;
            }
            
            if (jogo[0][2] == 'X' && jogo[1][1] == 'X' && jogo[2][0] == 'X')
            {
                printf("\nParabens! O jogador 2 venceu na diagonal secundária!\n");
                ganhou = 1;
            }
        }
        while (ganhou == 0 && jogadas < 9);
        
        if (ganhou == 0)
        {
            printf("\nO jogo finalizou sem ganhador!\n");
        }
        
        printf("\nDigite 1 para jogar novamente: \n");
        scanf("%d", &opcao);
    }
    while (opcao == 1);
    
    return(0);
}
