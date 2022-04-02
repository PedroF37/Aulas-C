#include <stdio.h>
#include <stdlib.h>

/*
                Aula 03: FILA de Prioridade
*/


typedef struct no
{
    int valor;
    struct no *proximo;
}
No;


/* Procedimento para inserir na fila */
void inserirNaFila(No **fila, int num)
{
    No *aux, *novo = malloc(sizeof(No));
    
    if (novo)
    {
        novo->valor = num;
        novo->proximo = NULL;
        
        if (*fila == NULL)
        {
            *fila = novo;
        }
        else
        {
            aux = *fila;
            
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


/* Função para remover elemento da fila */
No* removerDaFila(No **fila)
{
    No *remover = NULL;
    
    if (*fila != NULL)
    {
        remover = *fila;
        *fila = remover->proximo;
    }
    else
    {
        printf("\nFila vazia!\n");
    }
    
    return(remover);
}


/* Procedimentoo para imprimir a fila */
void imprimir(No *fila)
{
    printf("\t---------- FILA -------------\n\t");
    
    while (fila != NULL)
    {
        printf("%d ", fila->valor);
        fila = fila->proximo;
    }
    
    printf("\n\t---------- FIM FILA -------------\n");
}


/* Procedimento para inserir na fila com prioridade */
void inserircomPrioridade(No **fila, int num)
{
    No *aux, *novo = malloc(sizeof(No));
    
    if (novo)
    {
        novo->valor = num;
        novo->proximo = NULL;
        
        /*
            Se conteud de *fila for nulo (se fila está vazia)
        */
        if (*fila == NULL)
        {
            /* *fila recebe novo, e está feito */
            *fila = novo;
        }
        else
        {
            /*
                Senão, temos que ver se é prioridade
                Aqui neste exemplo prioridade 'maior que 59.
            */
            if (num > 59)
            {
                /*
                    É a primeira Prioridade?
                    
                    Mesmo sendo prioridade, pode já ter alguma prioridade na fila
                    e esta prioridade não ser a primeira.
                    
                    Então, se valor no inicio da fila for menor que 60..
                */
                if ((*fila)->valor < 60)
                {
                    /*
                        o valor no inicio não é prioridade e ponteiro proximo recebe então
                        esse valor, (o que estava no inicio, fica agora em segundo lugar na fila),
                        e novo, que tem o valor passado a função e que é prioridade, fica no inicio da fila
                    */
                    novo->proximo =  *fila;
                    *fila = novo;
                }
                else
                {
                    /*
                        Senão, se valor no inicio já for prioridade (igual ou maior a 60),
                        aux recebe esse valor, e percorremos a fila até que proximo seja nulo e 
                        valor apontado por proximo seja menor que 59.
                    */
                    aux = *fila;
                
                    while (aux->proximo != NULL && aux->proximo->valor > 59)
                    {
                        /* aux vai recebendo então o proximo */
                        aux = aux->proximo;
                    }
                    
                    /*
                        Quando proximo for nulo (dizendo que chegamos no fim da fila), ou valor apontado
                        por proximo for menor que 59 (o que diz que o elemento a seguir não tem prioridade),
                        então pudemos inserir na fila, nesse lugar o elemento prioritário.
                        
                        proximo de novo (que vai ser inserido) aponta para proximo de aux (que ou vai ser nulo, porque chegamos no fim,
                        ou vai ser um elemento sem prioridade).
                        proximo de aux recebe novo. Porque aux, representa o elemento antes deste que estamos inserindo.
                    */
                    novo->proximo = aux->proximo;
                    aux->proximo = novo;
                }
            }
            else
            {
                aux = *fila;
                
                while (aux->proximo != NULL)
                {
                    aux = aux->proximo;
                }
                
                aux->proximo = novo;
            }
        }
    }
    else
    {
        printf("\nErro ao alocar memoria!\n");
    }
}


int main()
{
    No *remover, *fila = NULL;
    int opcao, valor;
    
    do
    {
        printf("\t0 - Sair\n\t1 - Inserir\n\t2 - Remover\n\t3 - Imprimir\n\t4 - Inserir com Prioridade\n");
        scanf("%d", &opcao);
        
        switch (opcao)
        {
            case 1:
                printf("Digite um valor: ");
                scanf("%d", &valor);
                inserirNaFila(&fila, valor);
                break;
            case 2:
                remover = removerDaFila(&fila);
                
                if (remover != NULL)
                {
                    printf("\nRemovido: %d\n", remover->valor);
                    free(remover);
                }
                break;
            case 3:
                imprimir(fila);
                break;
            case 4:
                printf("Digite um valor: ");
                scanf("%d", &valor);
                inserircomPrioridade(&fila, valor);
                break;
            default:
                
                if (opcao != 0)
                {
                    printf("\nOpção invalida!\n");
                }
        }
    }
    while (opcao != 0);
    
    return(0);
}