#include <stdio.h>
#include <stdlib.h>

/*


                                                    Aula 19
                                                    
                                                 Jogo da velha

*/

/* Variáveis Globais */
char jogo[3][3];
int l, c;

/* Procedimento para inicializar todas as posições da matriz */
void inicializar()
{
    for (l = 0; l < 3; l++)
    {
        for (c = 0; c < 3; c++)
            jogo[l][c] = ' ';
    }
}

/* Procedimento para imprimir o jogo na tela */
void imprimir()
{
    printf("\n\n\t 0   1   2\n\n");
    for (l = 0; l < 3; l++)
    {
        for (c = 0; c < 3; c++)
        {
            if (c == 0)
                printf("\t");
            
            printf(" %c ", jogo[l][c]);
            
            if (c < 2)
                printf("|");
            if (c == 2)
                printf("   %d", l);
        }
        printf("\n");
        
        if (l < 2)
            printf("\t-----------\n");
    }
}

/* 
 * Função para verificar vitória por linha
 *  1 - ganhou
 *  0 - não ganhou ainda 
*/
int ganhouPorLinha(int l, char c)
{
    if (jogo[l][0] == c && jogo[l][1] == c && jogo[l][2] == c)
        return(1);  // ganhou
    else
        return(0);  // não ganhou ainda
}

/*
    Função para verificar vitória por linhas
    1 - ganhou
    0 - não ganhou ainda
*/
int ganhouPorLinhas(char c)
{
    int ganhou = 0;
    
    for (l = 0; l < 3; l++)
    {
        ganhou += ganhouPorLinha(l, c);
    }
    return(ganhou);
}

/*
    Função para verificar vitória em uma coluna
    1 - ganhou
    0 - não ganhou ainda
*/
int ganhouPorColuna(int c, char j)
{
    if (jogo[0][c] == j && jogo[1][c] == j && jogo[2][c] == j)
        return(1);  // ganhou
    else
        return(0);  // não ganhou ainda
}

/*

    Função que verifica vitória por colunas
    1 - ganhou
    0 - não ganhou ainda
*/
int ganhouPorColunas(char j)
{
    int ganhou = 0;
    
    for (c = 0; c < 3; c++)
    {
        ganhou += ganhouPorColuna(c, j);
    }
    return(ganhou);
}

/*
    Função para verificar vitória na diagonal principal
    1 - ganhou
    0 - não ganhou ainda
*/
int ganhouPorDiagPrincipal(char c)
{
    if (jogo[0][0] == c && jogo[1][1] == c && jogo[2][2])
        return(1);  // ganhou
    else
        return(0);  // não ganhou ainda;
}

/*
    Função para verificar vitória na diagonal secundária
    1 - ganhou
    0 - não ganhou ainda
*/
int ganhouPorDiagSecundaria(char c)
{
    if (jogo[0][2] == c && jogo[1][1] == c && jogo[2][0])
        return(1);  // ganhou
    else
        return(0);  // não ganhou ainda;
}

/*
    Função que diz se cordenada é válida ou não
    1 - válida
    0 - não é válida
*/
int valida(int l, int c)
{
    if (l >= 0 && l < 3 && c >= 0 && c < 3 && jogo[l][c] == ' ')
        return(1);  // válida
    else
        return(0);  // inválida
}

/* Procedimento para lêr as cordenadas */
void coordenadas(char j)
{
    int linha, coluna;
    
    printf("Digite linha e coluna: ");
    scanf("%d%d", &linha, &coluna);
    
    while (valida(linha,coluna) == 0)  // Falso
    {
        printf("Coordenadas inválidas! Digite outra linha e coluna: ");
        scanf("%d%d", &linha, &coluna);
    }
    jogo[linha][coluna] = j;
}

/* Função que retorna a quantidade de posições vazias */
int quantVazias()
{
    int quantidade = 0;
    
    for (l = 0; l < 3; l++)
    {
        for (c = 0; c < 3; c++)
        {
            if (jogo[l][c] == ' ')
                quantidade++;
        }
    }
    return(quantidade);
}

/* Procedimento jogar com o loop principal do jogo */
void jogar()
{
    int jogador = 1, vitoriaX = 0, vitoriaO = 0;
    char jogador1 = 'X', jogador2 = 'O';
    
    do
    {
        imprimir();
        
        if (jogador == 1)
        {
            coordenadas(jogador1);
            jogador++;
            vitoriaX += ganhouPorLinhas(jogador1);
            vitoriaX += ganhouPorColunas(jogador1);
            vitoriaX += ganhouPorDiagPrincipal(jogador1);
            vitoriaX += ganhouPorDiagSecundaria(jogador1);
        }
        else
        {
            coordenadas(jogador2);
            jogador = 1;
            vitoriaO += ganhouPorLinhas(jogador2);
            vitoriaO += ganhouPorColunas(jogador2);
            vitoriaO += ganhouPorDiagPrincipal(jogador2);
            vitoriaO += ganhouPorDiagSecundaria(jogador2);
        }
    }
    while (vitoriaX == 0 && vitoriaO == 0 && quantVazias() > 0);
    
    imprimir();
    
    if (vitoriaO == 1)
        printf("\nParabéns Jogador 2. Você venceu!!!\n");
    else if (vitoriaX == 1)
        printf("\nParabéns Jogador 1. Você venceu!!!\n");
    else
        printf("\nQue pena. Perderam!!!\n");
        
}

/* Função Main */
int main()
{
    int opcao;
    
    do
    {
        inicializar();
        jogar();
        
        printf("\nDigite 1 para jogar novamente: ");
        scanf("%d", &opcao);
    }
    while (opcao == 1);
    
    return(0);
}
