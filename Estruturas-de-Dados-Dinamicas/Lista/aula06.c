#include <stdio.h>
#include <stdlib.h>

/*
                            Aula 04: Lista Simplesmente Enadeada
                            Como inserir de forma ordenada COM a estrututa (struct) lista?
*/


typedef struct no
{
    int valor;
    struct no *proximo;
}
No;



typedef struct
{
    No *inicio;
    int tam;
}
Lista;


/* Procedimento para criar a lista */
void criarLista(Lista *lista)
{
    lista->inicio = NULL;
    lista->tam = 0;
}


/* Procedimento para inserir no inicio */
void inserirNoInicio(Lista *lista, int num)
{
    No *novo = malloc(sizeof(No));
    
    if (novo != NULL)
    {
        novo->valor = num;
        novo->proximo = lista->inicio;
        lista->inicio = novo;
        lista->tam++;
    }
    else
    {
        printf("\nErro ao alocar memoria!\n");
    }
}


/* Procedimento ppara inserir no final da lista */
void inserirNoFim(Lista *lista, int num)
{
    No *aux, *novo = malloc(sizeof(No));
    
    if (novo != NULL)
    {
        novo->valor = num;
        novo->proximo = NULL;
        
        /* É o primeiro No?*/
        if (lista->inicio == NULL)
        {
            lista->inicio = novo;
        }
        else
        {
            aux = lista->inicio;
            
            while (aux->proximo != NULL)
            {
                aux = aux->proximo;
            }
            
            aux->proximo = novo;
        }
        
        lista->tam++;
    }
    else
    {
        printf("\nErro ao alocar memoria!\n");
    }
}


/* Procedimento para inserir no meio da lista */
void inserirNoMeio(Lista *lista, int num, int anterior)
{
    No *aux, *novo = malloc(sizeof(No));
    
    if (novo != NULL)
    {
        novo->valor = num;
        
        /* É o primeiro No? */
        if (lista->inicio == NULL)
        {
            novo->proximo = NULL;
            lista->inicio = novo;
        }
        else
        {
            aux = lista->inicio;
            
            while (aux->valor != anterior && aux->proximo != NULL)
            {
                aux = aux->proximo;
            }
            
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
        
        lista->tam++;
    }
    else
    {
        printf("\nErro ao alocar memoria!\n");
    }
}


/* Procedimento para inserir ordenado */
void inserirOrdenado(Lista *lista, int num)
{
    No *aux, *novo = malloc(sizeof(No));
    
    if (novo != NULL)
    {
        novo->valor = num;
        
        if (lista->inicio == NULL)
        {
            novo->proximo = NULL;
            lista->inicio = novo;
        }
        else if (novo->valor < lista->inicio->valor)
        {
            novo->proximo = lista->inicio;
            lista->inicio = novo;
        }
        else
        {
            aux = lista->inicio;
            
            while (aux->proximo != NULL && novo->valor > aux->proximo->valor)
            {
                aux = aux->proximo;
            }
            
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
        
        lista->tam++;
    }
    else
    {
        printf("\nErro ao alocar memoria!\n");
    }
}


/* Procediment para imprimir a lista */
void imprimir(Lista lista)
{
    No *no = lista.inicio;
    
    printf("\n\tLista tam %d: ", lista.tam);
    
    while (no != NULL)
    {
        printf("%d ", no->valor);
        no = no->proximo;
    }
    
    printf("\n\n");
}


int main()
{
    //No *lista = NULL;
    Lista lista;
    
    criarLista(&lista);
    int opcao, valor, anterior;
    
    do
    {
        printf("\n\t0 - Sair\n\t1 - IniserirI\n\t2 - InserirF\n\t3 - InserirM\n\t4 - InserirO\n\t5 - Imprimir\n");
        scanf("%d", &opcao);
        
        switch (opcao)
        {
            case 1:
                printf("Digite um valor: ");
                scanf("%d", &valor);
                inserirNoInicio(&lista, valor);
                break;
            case 2:
                printf("Digite um valor: ");
                scanf("%d", &valor);
                inserirNoFim(&lista, valor);
                break;
            case 3:
                printf("Digite um valor e o valr de referencia: ");
                scanf("%d%d", &valor, &anterior);
                inserirNoMeio(&lista, valor, anterior);
                break;
            case 4:
                printf("Digite um valor: ");
                scanf("%d", &valor);
                inserirOrdenado(&lista, valor);
            case 5:
                imprimir(lista);
                break;
            default:
                
                if (opcao != 0)
                {
                    printf("Opcao invalida!\n");
                }
        }
    }
    while (opcao != 0);
    return(0);
}