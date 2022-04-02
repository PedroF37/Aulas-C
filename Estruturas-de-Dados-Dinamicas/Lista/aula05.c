#include <stdio.h>
#include <stdlib.h>


/*
                    Aula05: Lista simplesmente encadeada
                    Como inserir de forma ordenada SEM a estrutura (struct) lista?
*/


typedef struct no
{
    int valor;
    struct no *proximo;
}
No;


/* Procedimento para inserir no inicio */
void inserirNoInicio(No **lista, int num)
{
    No *novo = malloc(sizeof(No));
    
    if (novo != NULL)
    {
        novo->valor = num;
        novo->proximo = *lista;
        *lista = novo;
    }
    else
    {
        printf("\nErro ao alocar memoria!\n");
    }
}


/* Procedimento ppara inserir no final da lista */
void inserirNoFim(No **lista, int num)
{
    No *aux, *novo = malloc(sizeof(No));
    
    if (novo != NULL)
    {
        novo->valor = num;
        novo->proximo = NULL;
        
        /* É o primeiro No?*/
        if (*lista == NULL)
        {
            *lista = novo;
        }
        else
        {
            aux = *lista;
            
            while (aux->proximo != NULL)
            {
                aux = aux->proximo;
            }
            
            aux->proximo = novo;
        }
    }
    else
    {
        printf("\nErro ao alocar memoria!\n");
    }
}


/* Procedimento para inserir no meio da lista */
void inserirNoMeio(No **lista, int num, int anterior)
{
    No *aux, *novo = malloc(sizeof(No));
    
    if (novo != NULL)
    {
        novo->valor = num;
        
        /* É o primeiro No? */
        if (*lista == NULL)
        {
            novo->proximo = NULL;
            *lista = novo;
        }
        else
        {
            aux = *lista;
            
            while (aux->valor != anterior && aux->proximo != NULL)
            {
                aux = aux->proximo;
            }
            
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
    }
    else
    {
        printf("\nErro ao alocar memoria!\n");
    }
}


/* Procedimento para inserir de forma ordenada na lista */
void inserirOrdenado(No **lista, int num)
{
    No *aux, *novo = malloc(sizeof(No));
    
    if (novo != NULL)
    {
        novo->valor = num;
        
        /* A lista está vazia? */
        if (*lista == NULL)
        {
            novo->proximo = NULL;
            *lista = novo;
        }
        
        /* O elemento a inserir é o menor elemento? */
        else if (novo->valor < (*lista)->valor)
        {
            novo->proximo = *lista;
            *lista = novo;
        }
        
        /* Lista não está vazia e o elemento a inserir não é o menor */
        else
        {
            aux = *lista;
            
            /*
                Enquanto proximo não for nulo e enquanto valor a ser inserido
                for maior que valor do proximo.
            */
            while (aux->proximo != NULL && novo->valor > aux->proximo->valor)
            {
                aux = aux->proximo;
            }
            
            /* Aqui, ou o proximo é nulo ou o valor que queremoos inserir (novo->valor) NÃO é maior que o valor do proximo */
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
    }
    else
    {
        printf("\nErro ao alocar memoria!\n");
    }
}


/* Procediment para imprimir a lista */
void imprimir(No *lista)
{
    printf("\n\tLista: ");
    
    while (lista != NULL)
    {
        printf("%d ", lista->valor);
        lista = lista->proximo;
    }
    
    printf("\n\n");
}


int main()
{
    No *lista = NULL;
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