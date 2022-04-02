#include <stdio.h>
#include <stdlib.h>

/*

                                                Aula 05: Como BUSCAR em uma Aŕvore Binária de Busca?
                                                Versão Iterativa

*/


typedef struct no
{
    int valor;
    struct no *esquerda, *direita;
}
NoArvore;


/* Função para inserir na Arvore */
NoArvore* inserirVersao1(NoArvore *raiz, int num)
{
    if (raiz == NULL)
    {
        /*
            A arvore é pequena, então descartamos
            a verificação da alocação, apenas porque a arvore
            é pequena e porque estamos a praticar apenas 
        */
        NoArvore *aux = malloc(sizeof(NoArvore));
        aux->valor = num;
        aux->esquerda = NULL;
        aux->direita = NULL;
        return(aux);
    }
    else
    {
        if (num < raiz->valor)
        {
            raiz->esquerda = inserirVersao1(raiz->esquerda, num);
        }
        else
        {
            raiz->direita = inserirVersao1(raiz->direita, num);
        }
        
        return(raiz);
    }
}


/* procedimento para inserir na Arvore Versão 2, um pouco mais eficiente que a versão 1 */
void inserirVersao2(NoArvore **raiz, int num)
{
    if (*raiz == NULL)
    {
        *raiz = malloc(sizeof(NoArvore));
        (*raiz)->valor = num;
        (*raiz)->esquerda = NULL;
        (*raiz)->direita = NULL;
    }
    else
    {
        if (num < (*raiz)->valor)
        {
            inserirVersao2(&((*raiz)->esquerda), num);
        }
        else
        {
            inserirVersao2(&((*raiz)->direita), num);
        }
    }
}


/* Terceira versão para inserir na Arvore, versão mais eficiente das tres versões*/
void inserirVersao3(NoArvore **raiz, int num)
{
    NoArvore *aux = *raiz;
    
    while (aux != NULL)
    {
        if (num < aux->valor)
        {
            raiz = &aux->esquerda;
        }
        else
        {
            raiz = &aux->direita;
        }
        
        aux = *raiz;
    }
    
    aux = malloc(sizeof(NoArvore));
    aux->valor = num;
    aux->esquerda = NULL;
    aux->direita = NULL;
    *raiz = aux;
}


/* Função de busca */
NoArvore* buscarVersao1(NoArvore *raiz, int num)
{
    if (raiz != NULL)
    {
        if (num == raiz->valor)
        {
            return (raiz);
        }
        else if (num < raiz->valor)
        {
            return(buscarVersao1(raiz->esquerda, num));
        }
        else
        {
            return(buscarVersao1(raiz->direita, num));
        }
    }
    
    return(NULL);
}


/* Função de busca Versão 2 sem recursao */
NoArvore* buscarVersao2(NoArvore *raiz, int num)
{
    while (raiz != NULL)
    {
        if (num < raiz->valor)
        {
            raiz = raiz->esquerda;
        }
        else if (num > raiz->valor)
        {
            raiz = raiz->direita;
        }
        else
        {
            return(raiz);
        }
    }
    
    return(NULL);
}


/* Procedimento para imprimir a Arvore  versáo 1*/
void imprimirVersao1(NoArvore *raiz)
{
    if (raiz != NULL)
    {
        printf("%d ", raiz->valor);
        imprimirVersao1(raiz->esquerda);
        imprimirVersao1(raiz->direita);
    }
}

/* Procedimento para imprimir a Arvore ordenada */
void imprimirVersao2(NoArvore *raiz)
{
    if (raiz != NULL)
    {
        imprimirVersao2(raiz->esquerda);
        printf("%d ", raiz->valor);
        imprimirVersao2(raiz->direita);
    }
}

int main()
{
    NoArvore *raiz = NULL, *busca;
    int opcao, valor;
    
    do
    {
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Imprimir\n\t3 - Buscar\n");
        scanf("%d", &opcao);
        
        switch (opcao)
        {
            case 1:
                printf("Digite um valor: ");
                scanf("%d", &valor);
                //raiz = inserirVersao1(raiz, valor);
                //inserirVersao2(&raiz, valor);
                inserirVersao3(&raiz, valor);
                break;
            case 2:
                printf("\n\tPrimeira impressao:\n\t");
                imprimirVersao1(raiz);
                printf("\n");
                printf("\n\tSegunda impressao:\n\t");
                imprimirVersao2(raiz);
                printf("\n");
                break;
            case 3:
                printf("Digite um valor: ");
                scanf("%d", &valor);
                //busca = buscarVersao1(raiz, valor);
                busca = buscarVersao2(raiz, valor);
                if (busca != NULL)
                {
                    printf("\n\tValor encontrado: %d\n", busca->valor);
                }
                else
                {
                    printf("\n\tValor nao encontrado\n");
                }
                break;
            default:
                if (opcao != 0)
                {
                    printf("\nOpçao invalida.\n");
                }
        }
    }
    while (opcao != 0);
    return(0);
}