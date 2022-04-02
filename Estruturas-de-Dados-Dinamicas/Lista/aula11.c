#include <stdio.h>
#include <stdlib.h>


/*
                    Aula11: Lista simplesmente encadeada
                    Gerar uma lista C com os elementos das Listas A e B
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


/* Funçãoo para remover um no da lista */
No* removerDaLista(No **lista, int num)
{
    No* aux, *remover = NULL;
    
    if (*lista != NULL)
    {
        if ((*lista)->valor == num)
        {
            remover = *lista;
            *lista = remover->proximo;
        }
        else
        {
            aux = *lista;
            
            while (aux->proximo != NULL && aux->proximo->valor != num)
            {
                aux = aux->proximo;
            }
            
            if (aux->proximo != NULL)
            {
                remover = aux->proximo;
                aux->proximo = remover->proximo;
            }
        }
    }
    
    return(remover);
}


/* Função para fazer buscas na lista */
No* buscar(No **lista, int num)
{
    No *aux, *no = NULL;
    
    aux = *lista;
    
    while (aux != NULL && aux->valor != num)
    {
        aux = aux->proximo;
    }
    
    if (aux != NULL)
    {
        no = aux;
    }
    
    return(no);
}


/* Procedimento para copiar uma lista para dentro de outra */
void copiarLista(No **listaO, No **listaD)
{
    No *aux = *listaO;
    
    while (aux != NULL)
    {
        inserirNoInicio(listaD, aux->valor);
        aux = aux->proximo;
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
    No *no, *remover, *A, *B, *C;
    int opcao, valor, anterior;
    
    A = NULL;
    B = NULL;
    C = NULL;
    
    do
    {
        printf("\n\t0 - Sair\n\t1 - IniserirI\n\t2 - InserirF\n\t3 - InserirM\n\t4 - InserirO\n\t5 - Remover\n\t6 - Imprimir\n\t7- Buscar\n\t8 - Copiar\n");
        scanf("%d", &opcao);
        
        switch (opcao)
        {
            case 1:
                printf("Digite um valor: ");
                scanf("%d", &valor);
                inserirNoInicio(&A, valor);
                
                printf("Digite um valor: ");
                scanf("%d", &valor);
                inserirNoInicio(&B, valor);
                break;
            case 2:
                printf("Digite um valor: ");
                scanf("%d", &valor);
                inserirNoFim(&A, valor);
                break;
            case 3:
                printf("Digite um valor e o valor de referencia: ");
                scanf("%d%d", &valor, &anterior);
                inserirNoMeio(&B, valor, anterior);
                break;
            case 4:
                printf("Digite um valor: ");
                scanf("%d", &valor);
                inserirOrdenado(&A, valor);
                break;
            case 5:
                printf("Digite um valor para remover: ");
                scanf("%d", &valor);
                remover = removerDaLista(&C, valor);
                
                if (remover!= NULL)
                {
                    printf("Elemento a ser removido: %d\n", remover->valor);
                    free(remover);
                }
                break;
            case 6:
                printf("\nLista A:\n");
                imprimir(A);
                printf("\nLista B:\n");
                imprimir(B);
                printf("\nLista C:\n");
                imprimir(C);
                break;
            case 7:
                printf("Digite um valor para buscar: ");
                scanf("%d", &valor);
                no = buscar(&C, valor);
                
                if (no != NULL)
                {
                    printf("Valor encontrado: %d\n", no->valor);
                }
                else
                {
                    printf("Elemento não encontrado!\n"); 
                }
                
                break;
            case 8:
                copiarLista(&A, &C);
                copiarLista(&B, &C);
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