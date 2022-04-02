#include <stdio.h>
#include <stdlib.h>


/*
                    Aula09: Lista simplesmente encadeada
                    Como fazer buscas sem a estrutura lista?
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


/* Procedimento para dividir lista em lista Par e lista Impar */
void dividir(No **listaO, No **listaP, No **listaI)
{
    No *aux;
    
    aux = *listaO;
    
    while (aux != NULL)
    {
        if (aux->valor > 0)
        {
            if (aux->valor % 2 == 0)
            {
                inserirNoInicio(listaP, aux->valor);
            }
            else
            {
                inserirNoInicio(listaI, aux->valor);
            }
        }
        
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
    No *no, *remover, *lista = NULL;
    No *Par = NULL, *Impar = NULL;
    int opcao, valor, anterior;
    
    do
    {
        printf("\n\t0 - Sair\n\t1 - IniserirI\n\t2 - InserirF\n\t3 - InserirM\n\t4 - InserirO\n\t5 - Remover\n\t6 - Imprimir\n\t7- Buscar\n\t8 - Dividir\n");
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
                break;
            case 5:
                printf("Digite um valor para remover: ");
                scanf("%d", &valor);
                remover = removerDaLista(&lista, valor);
                
                if (remover!= NULL)
                {
                    printf("Elemento a ser removido: %d\n", remover->valor);
                    free(remover);
                }
                break;
            case 6:
                printf("\nLista Original:\n");
                imprimir(lista);
                printf("\nLista Par:\n");
                imprimir(Par);
                printf("\nLista Impar:\n");
                imprimir(Impar);
                break;
            case 7:
                printf("Digite um valor para buscar: ");
                scanf("%d", &valor);
                no = buscar(&lista, valor);
                
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
                dividir(&lista, &Par, &Impar);
                printf("\nDivisão realizada com sucesso!\n");
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