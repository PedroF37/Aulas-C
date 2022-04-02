#include <stdio.h>
#include <stdlib.h>

/*
                Aula 01:Estrutura Fila - Primeira versão
                
                FIFO - First-In, First-Out - Primeiro a Entrar, Primeiro a Sair
                
                Insere no fim da fila, remove no inicio da fila.
*/


typedef struct no
{
    int valor;
    struct no *proximo;
}
No;


/*
    Procedimento para inserir na fila
    
    Recebe como parâmetro um ponteiro para ponteiro
    (o endereço na memória do ponteiro que tem o endereço
    na memória do No que está por ultimo na fila), e o valor
    para inserir na fila.
*/
void inserirNaFila(No **fila, int num)
{
    No *aux, *novo = malloc(sizeof(No));
    
    if (novo)
    {
        /*
            Como na fila insere-se no final,
            novo recebe o valor a inserir e o
            elemento proximo (que tem o endereço
            na memória do proximo nó), recebe NULL,
            porque em uma fila o elemento é inserido
            no final e atrás ainda não tem ninguem ou nada
        */
        novo->valor = num;
        novo->proximo = NULL;
        
        /*
            Se o conteúdo (o endereço de memória),
            que é o valor do ponteiro fila for nulo,
            (se não apontar para nada), então a fila
            está vazia e o ponteiro recebe o conteudo de novo
            (o primeiro elemento na fila)
        */
        if (*fila == NULL)
        {
            *fila = novo;
        }
        else
        {
            /*
                 Senão, se a fila já tiver pelo menos
                 um elemento, então ponteiro aux recebe esse elemento
                 do ponteiro *fila. E agora temos que percorrer a fila
                 do inicio ao fim, para inserir no final..
            */
            aux = *fila;
            
            /*
                Enquanto elemento proximo de aux não apontar para NULL
                quer dizer que não chegamos ainda no final da fila
            */
            while (aux->proximo != NULL)
            {
                /* aux vai recebendo o que for apontado por proximo */
                aux = aux->proximo;
            }
            
            /*
                Quando finalmente proximo apontar para Nulo,
                quer dizer que chegamos no final da fila, e então
                o elemento proximo de aux, vai apontar para novo.
                Ou seja, chegamos no fim da fila e então podemos inserir
                o novo dado na fila
            */
            aux->proximo = novo;
        }
    }
    else
    {
        printf("\nErro ao alocar memoria!\n");
    }
}


/*
    Função para remover elemento da fila
    
    Retorna o No (a struct No),que foi removida da fila
    (do INICIO da fila).
    
    Recebe como parâmetro o endereço do ponteiro que tem o
    endereço do No no inicio da fila.
*/
No* removerDaFila(No **fila)
{
    No *remover = NULL;
    
    /*
        Se o ponteiro fila não apontar para NULO,
        (se a fila não estver vazia)
    */
    if (*fila != NULL)
    {
        /*
            remover recerbe o No no inicio da fila, (apontado
            por *fila), e fila, que aponta sempre para o inicio
            aponta agora, (recebe o enderelo na memória), do proximo na fila
            (sai o primeiro, o que era segundo passa a ser primeiro...!!)
        */
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
        
        /* Enquanto tiver elementos temos que apontar para o proximo*/
        fila = fila->proximo;
    }
    
    printf("\n\t---------- FIM FILA -------------\n");
}


int main()
{
    No *remover, *fila = NULL;
    int opcao, valor;
    
    do
    {
        printf("\t0 - Sair\n\t1 - Inserir\n\t2 - Remover\n\t3 - Imprimir\n");
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