#include <stdio.h>
#include <stdlib.h>

/*
                Aula 01: Estrutura FILA - Segunda versão
                
                FIFO - First-In, First-Out - Primeiro a Entrar, Primeiro a Sair
*/


typedef struct no
{
    int valor;
    struct no *proximo;
}
No;


/*
    Criamos a struct ara a fila
    onde temos um ponteiro que vai
    ter o endereço do primeiro No
    na Fila e um ponteiro com o endereço
    do ultimo No na fila
*/
typedef struct
{
    No *primeiro;
    No *ultimo;
    int tamanho;
}
Fila;


/* Proedimento para criar a Fila, inicia tudo com 0 e Nulo porque fila inicia vazia */
void criarFila(Fila *fila)
{
    fila->primeiro = NULL;
    fila->ultimo = NULL;
    fila->tamanho = 0;
}


/*
    Procedimento para inserir na fila
    
    Recebe como parâmetros o endereço de uma struct Fila
    e o valor a ser inserido no final da fila.
*/
void inserirNaFila(Fila *fila, int num)
{
    No *novo = malloc(sizeof(No));
    
    if (novo)
    {
        /*
            valor em novo recebe o número
            e proximo de novo aponta para nulo, porque
            como inserimos no final, o proximo não tem ninguem atras
        */
        novo->valor = num;
        novo->proximo = NULL;
        
        /*
            Se elemento primeiro  da struct Fila (ponteiro que aponta para o inicio da fila)
            não tiver ninguem atras dele...
        */
        if (fila->primeiro == NULL)
        {
            /*
                primeiro recebe então o novo, porque quer dizer que fila está vazia
                mas como fila está vazia, ponteiro ultimo, que aponta para o final,
                recebe também o novo.
            */
            fila->primeiro = novo;
            fila->ultimo = novo;
        }
        else
        {
            /*
                Senão, se fila tiver já pelo menos um elemento,
                ponteiro proximo recebe novo,
                mas ponteiro ultimo da struct Fila, que aponta para o ultimo elemento
                na fila recebe novo também.
            */
            fila->ultimo->proximo = novo;
            fila->ultimo = novo;
        }
        
        fila->tamanho++;
    }
    else
    {
        printf("\nErro ao alocar memoria!\n");
    }
}


/* 
    Função para remover elemento da fila
    
    Retorna o No (struct No) que estava no primeiro lugar da fila
    
    Recebe como parametro o endereço desse No ( o primeiro lugar na fila)
*/
No* removerDaFila(Fila *fila)
{
    No *remover = NULL;
    
    /*
        Se ponteiro primeiro não apontar para nulo,
        quer dizer que fila não está vazia 
    */
    if (fila->primeiro != NULL)
    {
        /*
            remover recebe a struct apontada por primeiro
            primeiro (que aponta para o inicio) recebe struct apontada
            por próximo, (que era o segundo na fila e agora vai ser o primeiro na fila)
        */
        remover = fila->primeiro;
        fila->primeiro = remover->proximo;
        fila->tamanho--;
    }
    else
    {
        printf("\nFila vazia!\n");
    }
    
    return(remover);
}


/* Procedimentoo para imprimir a fila */
void imprimir(Fila *fila)
{
    No *aux = fila->primeiro;
    
    printf("\t---------- FILA -------------\n\t");
    
    while (aux != NULL)
    {
        printf("%d ", aux->valor);
        aux = aux->proximo;
    }
    
    printf("\n\t---------- FIM FILA -------------\n");
}


int main()
{
    No *remover;
    Fila fila;
    int opcao, valor;
    
    criarFila(&fila);
    
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
                imprimir(&fila);
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