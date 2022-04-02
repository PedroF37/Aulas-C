#include <stdio.h>
#include <stdlib.h>

/*
                            Aula 02: Tabela Hash com lista encadeada
*/


#define TAM 31


typedef struct no
{
    int chave;
    struct no *proximo;
}
No;


typedef struct
{
    No *inicio;
    int tam;
}
Lista;


/* Procedimento para inicializar a Lista */
void inicializarLista(Lista *lista)
{
    lista->inicio = NULL;
    lista->tam = 0;
}


/* Procedimento para inserir na Lista */
void inserirLista(Lista *lista, int valor)
{
    No *novo = malloc(sizeof(No));
    
    if (novo != NULL)
    {
        novo->chave = valor;
        novo->proximo = lista->inicio;
        lista->inicio = novo;
        lista->tam++;
    }
    else
    {
        printf("\n\tErro ao alocar memoria\n");
    }
}


/* Função para buscar na Lista */
int buscarLista(Lista *lista, int valor)
{
    No *aux = lista->inicio;
    
    while (aux != NULL && aux->chave != valor)
    {
        aux = aux->proximo;
    }
    
    if (aux != NULL)
    {
        return(aux->chave);
    }
    
    return(0);   // Não encontrado
}


/* Procedimento para imprimir Lista */
void imprimirLista(Lista *lista)
{
    No *aux = lista->inicio;
    
    printf(" Tam: %d: ", lista->tam);
    while (aux != NULL)
    {
        printf("%d ", aux->chave);
        aux = aux->proximo;
    }
}


/* Procedimento para inicializar a tabela */
void inicializarTabela(Lista tabela[])
{
    int i;
    
    for (i = 0; i < TAM; i++)
    {
        inicializarLista(&tabela[i]);
    }
}


/* Função Hash ou de espalhamento */
int funcaoHash(int chave)
{
    return(chave % TAM);
}


/* Procedimento para inserir na tabela */
void inserir(Lista tabela[], int valor)
{
    int id = funcaoHash(valor);  // id = 3
    inserirLista(&tabela[id], valor);
}


/* Fução para buscar na tabela */
int busca(Lista tabela[], int chave)
{
    int id = funcaoHash(chave);
    printf("\nIndice Gerado: %d\n", id);
    return(buscarLista(&tabela[id], chave));
}


/* Procedimento para imprimir a tabela */
void imprimir(Lista tabela[])
{
    int i;
    
    for (i = 0; i < TAM; i++)
    {
        printf("%2d =  ", i);
        imprimirLista(&tabela[i]);
        printf("\n");
    }
}


int main()
{
    int opcao, valor, retorno;
    Lista tabela[TAM];
    
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