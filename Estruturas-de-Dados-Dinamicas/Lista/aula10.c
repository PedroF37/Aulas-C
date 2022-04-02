#include <stdio.h>
#include <stdlib.h>

/*
                            Aula 04: Lista Simplesmente Enadeada
                            Como buscar COM a estrututa lista?
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


/* Função para remover No da lista */
No* removerDaLista(Lista *lista, int num)
{
    No *aux, *remover = NULL;
    
    if (lista->inicio != NULL)
    {
        if (lista->inicio->valor == num)
        {
            remover = lista->inicio;
            lista->inicio = remover->proximo;
            lista->tam--;
        }
        else
        {
            aux = lista->inicio;
            
            while (aux->proximo != NULL && aux->proximo->valor != num)
            {
                aux = aux->proximo;
            }
            
            if (aux->proximo != NULL)
            {
                remover = aux->proximo;
                aux->proximo = remover->proximo;
                lista->tam--;
            }
        }
    }
    
    return(remover);
}


/* Função para buscar na lista */
No* buscar(Lista *lista, int num)
{
    No *aux, *no = NULL;
    
    aux = lista->inicio;
    
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
    No *no, *remover = NULL;
    //No *lista = NULL;
    Lista lista;
    
    criarLista(&lista);
    int opcao, valor, anterior;
    
    do
    {
        printf("\n\t0 - Sair\n\t1 - IniserirI\n\t2 - InserirF\n\t3 - InserirM\n\t4 - InserirO\n\t5 - Remover\n\t6 - Imprimir\n\t7 - Buscar\n");
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
                
                if (remover != NULL)
                {
                    printf("Elemento removido: %d\n", remover->valor);
                    free(remover);
                }
                else
                {
                    printf("Elemento inexistente!\n");
                }
                
                break;
            case 6:
                imprimir(lista);
                break;
            case 7:
                printf("Digite um valor para buscar: ");
                scanf("%d", &valor);
                no = buscar(&lista, valor);
                
                if (no != NULL)
                {
                    printf("Elemento encontrado: %d\n", no->valor);
                }
                else
                {
                    printf("Elemento não encontrado!\n");
                }
                
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