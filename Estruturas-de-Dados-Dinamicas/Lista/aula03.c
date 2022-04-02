#include <stdio.h>
#include <stdlib.h>

/*
                            Aula 03: Lista Simplesmente Enadeada
                            Como inserir no meio da lista?
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
        printf("\n\t0 - Sair\n\t1 - IniserirI\n\t2 - InserirF\n\t3 - InserirM\n\t4 - Imprimir\n");
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