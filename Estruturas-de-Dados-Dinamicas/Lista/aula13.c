#include <stdio.h>
#include <stdlib.h>

/*
                                                        Aula 13: Lista Duplamentte Encadeada
*/


/*
    Tipo de dado (struct) No, com apelido no.
    
    Tem como membros internos um inteiro valor,
    e dois ponteiros para structs iguais.
    Tem dois ponteiros porque estamos a construir
    uma lista duplamente encadeada, onde temos duas ligações;
    a ligação para o proximo membro da lista e a ligação para o membro anterior na lista.
*/
typedef struct no
{
    int valor;
    struct no *proximo;
    struct no *anterior;
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
        
        /* 
            Como aqui estamos a inserir no inicio da lista, o ponteiro anterior é Nulo
            porque antes deste Nó que estamos a inserir não tem nada.
        */
        novo->anterior = NULL;
        
        /*
            Mas se a lista não estava vazia, então o ponteiro *anterior,
            do Nó que já estava na lista e que passou agora a ser o segundo da lista,
            antes apontava para NULL, mas como agora é o segundo No na lista, vai apontar para novo */
        if (*lista != NULL)
        {
            (*lista)->anterior = novo;
        }
        *lista = novo;
    }
    else
    {
        printf("\nErro ao alocar memoria!\n");
    }
}


/* Procedimento para inserir no final da lista */
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
            
            /*
                Aqui, embora  gente esteja inserindo no final da lista, se a lista
                estiver vazia, então o No que estamos a inserir vai ser o único na lista,
                por isso o ponteiro anterior aponta para NULL e não para o membro anterior.
            */
            novo->anterior = NULL;
        }
        else
        {
            aux = *lista;
            
            while (aux->proximo != NULL)
            {
                aux = aux->proximo;
            }
            
            aux->proximo = novo;
            novo->anterior = aux;
        }
    }
    else
    {
        printf("\nErro ao alocar memoria!\n");
    }
}


/* Procedimento para inserir no meio da lista */
void inserirNoMeio(No **lista, int num, int ant)
{
    No *aux, *novo = malloc(sizeof(No));
    
    if (novo != NULL)
    {
        novo->valor = num;
        
        /* É o primeiro No? */
        if (*lista == NULL)
        {
            novo->proximo = NULL;
            novo->anterior = NULL;
            *lista = novo;
        }
        else
        {
            aux = *lista;
            
            while (aux->valor != ant && aux->proximo != NULL)
            {
                aux = aux->proximo;
            }
            
            novo->proximo = aux->proximo;
            
            if (aux->proximo != NULL)
            {
                aux->proximo->anterior = novo;  // [aux com valor de referencia]  [novo]  [proximo (aux->proximo apontava para aqui)]
            }                                   // o ponteiro anterior do proximo nó para onde o aux apontava agora aponta para o novo no
            
            novo->anterior = aux;
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
            novo->anterior = NULL;
            *lista = novo;
        }
        
        /* O elemento a inserir é o menor elemento? */
        else if (novo->valor < (*lista)->valor)
        {
            novo->proximo = *lista;
            (*lista)->anterior = novo;
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
            
            if (aux->proximo != NULL)
            {
                aux->proximo->anterior = novo;
            }
            
            novo->anterior = aux;
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
            
            if (*lista != NULL)
            {
                (*lista)->anterior = NULL;
            }
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
                
                if (aux->proximo != NULL)
                {
                    aux->proximo->anterior = aux;
                }
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


/* Função que retorna um ponteiro para o último No da lista */
No* ultimoNo(No **lista)
{
    No *aux = *lista;
    
    while (aux->proximo != NULL)
    {
        aux = aux->proximo;
    }
    
    return(aux);
}


/* Procedimento para imprimir a lista do final para o inicio */
void imprimirContrario(No *no)
{
    printf("\n\tLista: ");
    
    while (no != NULL)
    {
        printf("%d ", no->valor);
        no = no->anterior;
    }
    
    printf("\n\n");
}


int main()
{
    No *no, *remover, *lista = NULL;
    No *Par = NULL, *Impar = NULL;
    int opcao, valor, ant;
    
    do
    {
        printf("\n\t0 - Sair\n\t1 - IniserirI\n\t2 - InserirF\n\t3 - InserirM\n\t4 - InserirO\n\t5 - Remover\n\t6 - Imprimir\n\t7- Buscar\n\t8 - ImprimirC\n");
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
                printf("Digite um valor e o valor de referencia: ");
                scanf("%d%d", &valor, &ant);
                inserirNoMeio(&lista, valor, ant);
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
                imprimirContrario(ultimoNo(&lista));
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