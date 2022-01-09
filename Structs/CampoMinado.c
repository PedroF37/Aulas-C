#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*                      Campo Minado     */


/*
    CELULA
    eBomba 0 ou 1
    estaAberta 0 ou 1
    vizinhos 0 a 4
*/

typedef struct
{
    int eBomba;
    int estaAberta;
    int vizinhos;
}
Celula;

/* Variáveis Globais */
Celula jogo[10][10];
int l, c, tam = 10;

/* Procedimento para inicializar a matriz do jogo */
void inicializarJogo()
{
    for (l = 0; l < tam; l++)
    {
        for (c = 0; c < tam; c++)
        {
            jogo[l][c].eBomba = 0;
            jogo[l][c].estaAberta = 0;
            jogo[l][c].vizinhos = 0;
        }
    }
}

/* Procedimento para sortear N bombas */
void sortearBombas(int n)
{
    int i;
    srand(time(NULL));
    
    for (i = 1; i <= n; i++)
    {
        l = rand() % tam;
        c = rand() % tam;
        
        if (jogo[l][c].eBomba == 0)
        {
            jogo[l][c].eBomba = 1;
        }
        else
        {
            i--;
        }
    }
}


/*

    Função que diz se um par de coordenadas é válido ou não
    1 - é válido
    0 - não é válido

*/
int coordenadaEhValida(int l, int c)
{
    if (l >= 0 && l < tam && c >= 0 && c < tam)
    {
        return(1);
    }
    else
    {
        return(0);
    }
}


/*

    Função que retorna a quantidade de bombas na vizinhança de l e c
    n - quantidade de bombas

*/
int bombasVizinhas(int l, int c)
{
    /*
        l - 1 e c
        l + 1 e c
        l e c + 1
        l e c - 1
    */
    int quantidade = 0;
    
    if (coordenadaEhValida(l - 1, c) && jogo[l - 1][c].eBomba)
    {
        quantidade++;
    }
    
    if (coordenadaEhValida(l + 1, c) && jogo[l + 1][c].eBomba)
    {
        quantidade++;
    }
    
    if (coordenadaEhValida(l, c + 1) && jogo[l][c + 1].eBomba)
    {
        quantidade++;
    }
    
    if (coordenadaEhValida(l, c - 1) && jogo[l][c - 1].eBomba)
    {
        quantidade++;
    }
    
    return(quantidade);
}

/* Procedimento para contar as bombas vizinhas */
void contarBombas()
{
    for (l = 0; l < tam; l++)
    {
        for (c = 0; c < tam; c++)
        {
            jogo[l][c].vizinhos = bombasVizinhas(l, c);
        }
    }
}


/* Procedimento para imprimir jogo */
void imprimir()
{
    printf("\n\n\t    ");
    for (l = 0; l < tam; l++)
    {
        printf(" %d  ", l);   // indices das colunas.
    }
    
    printf("\n\t   -----------------------------------------\n");
    
    for (l = 0; l < tam; l++)
    {
        printf("\t%d  |", l);    // indices das linhas.
        for (c = 0; c < tam; c++)
        {
            if (jogo[l][c].estaAberta)
            {
                if (jogo[l][c].eBomba)
                {
                    printf(" * ");
                }
                else
                {
                    printf(" %d ", jogo[l][c].vizinhos);
                }
            }
            else
            {
                printf("   ");
            }
            
            printf("|");
        }
        
        printf("\n\t   -----------------------------------------\n");
    }
}


/* Procedimento para abrir a coordenada digitada pelo usuário */
void abrirCelula(int l, int c)
{
    if (coordenadaEhValida(l, c) == 1 && jogo[l][c].estaAberta == 0)
    {
        
        jogo[l][c].estaAberta = 1;
        
        if (jogo[l][c].vizinhos == 0)
        {
            /*
            
                l - 1 e c -> vizinho acima
                l + 1 e c -> vizinho abaixo
                l e c + 1 -> vizinho da direita
                l e c - 1 -> vizinho da esquerda
            
            */
            abrirCelula(l - 1, c);
            abrirCelula(l + 1, c);
            abrirCelula(l, c + 1);
            abrirCelula(l, c - 1);
        }
    }
}

/*

    Função para verificar vitória
    n - ganhou
    0 - não ganhou ainda

*/
int ganhou()
{
    int quantidade = 0;
    
    for (l = 0; l < tam; l++)
    {
        for (c = 0; c < tam; c++)
        {
            if (jogo[l][c].estaAberta == 0 && jogo[l][c].eBomba == 0)
            {
                quantidade++;
            }
        }
    }
    
    return(quantidade);
}

/* Procedimento jogar que faz a leitura das coordenadas */
void jogar()
{
    int linha, coluna;
    
    do
    {
        imprimir();
        
        do
        {
            printf("\nDigite as coordenadas de linha e coluna: ");
            scanf("%d%d", &linha, &coluna);
            
            if (coordenadaEhValida(linha, coluna) == 0 || jogo[linha][coluna].estaAberta == 1)
            {
                printf("\nCoordenada inválida ou já aberta!");
            }
        }
        while (coordenadaEhValida(linha, coluna) == 0 || jogo[linha][coluna].estaAberta == 1);
        
        abrirCelula(linha, coluna);
    }
    while (ganhou() != 0 && jogo[linha][coluna].eBomba == 0);
    
    if (jogo[linha][coluna].eBomba == 1)
    {
        printf("\n\tQue pena! Voce perdeu!!!\n");
    }
    else
    {
        printf("\n\tPARABENS! VOCE GANHOU!!\n");
    }
    
    imprimir();
}

int main()
{
    int opcao;
    
    do
    {
        inicializarJogo();
        sortearBombas(10);
        contarBombas();
        printf("\n\t\t\tCAMPO MINADO\n");
        jogar();
        
        printf("\nDigite 1 para jogar novamente: ");
        scanf("%d", &opcao);
    }
    while (opcao == 1);
    
    return(0);
}
