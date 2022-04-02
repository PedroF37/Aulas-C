#include <stdio.h>
#include <stdlib.h>

/*
                        Aula 01: Tabela Hash linear com vetor
                        
                        2 * 15 = 30 - primo 29 ou 31
                        
                         Constante -> valor não pode ser alterado
                         #define TAM 31     -> quando compilar vai ser pego todas as ocorrencias
                                                de TAM e vai ser substituido por 31, não vai ter região de
                                                memória associada á constanmte 
*/

#define TAM 31


/* Procedimento para inicializar a tabela */
void inicializarTabela(int tabela[])    // Não precisa do TAM, porque já está definido acima
{
    int i;
    
    for (i = 0; i < TAM; i++)
    {
        tabela[i] = -1; // ou 0 ou outro valor que não faça parte das chaves
    }
}


/* Função Hash ou de espalhamento */
int funcaoHash(int chave)
{
    return(chave % TAM);
}


/* Procedimento para inserir na tabela */
void inserir(int tabela[], int valor)
{
    int id = funcaoHash(valor);  // id = 3
    
    while (tabela[id] != -1)    // já tem 3?
    {
        id = funcaoHash(id + 1); // id recebe valor id + 1 id recebe 3 + 1
    }
    
    tabela[id] = valor; // se asaiu do while, então a posição id é igual a -1, logo está vaga, sem mais colisão
}


/* Fução para buscar na tabela */
int busca(int tabela[], int chave)
{
    int id = funcaoHash(chave);
    printf("\nIndice Gerado: %d\n", id);
    
    while (tabela[id] != -1)
    {
        if (tabela[id] == chave)
        {
            return(tabela[id]);
        }
        else
        {
            id = funcaoHash(id + 1);
        }
    }
    
    return(-1);
}


/* Procedimento para imprimir a tabela */
void imprimir(int tabela[])
{
    int i;
    
    for (i = 0; i < TAM; i++)
    {
        printf("%d = %d\n", i, tabela[i]);
    }
}


int main()
{
    int opcao, valor, retorno, tabela[TAM];
    
    inicializarTabela(tabela);
    
    do
    {
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Buscar\n\t3 - Imprimir\n");
        scanf("%d", &opcao);
        
        switch (opcao)
        {
            case 1:
                printf("\tDigite o valor para inserir: ");
                scanf("%d", &valor);
                inserir(tabela, valor);
                break;
            case 2:
                printf("\tDigite o valor para buscar: ");
                scanf("%d", &valor);
                retorno = busca(tabela, valor);
                
                if (retorno != -1)
                {
                    printf("\tValor encontrado: %d\n", retorno);
                }
                else
                {
                    printf("\tValor não encontrado\n");
                }
                break;
            case 3:
                imprimir(tabela);
                break;
            default:
                if (opcao != 0)
                {
                    printf("\nOpçao invalida!\n");
                }
        }
    }
    while (opcao != 0);
    return(0);
}