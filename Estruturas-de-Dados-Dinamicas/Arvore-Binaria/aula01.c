#include <stdio.h>
#include <stdlib.h>

/*

                                                Aula 01: Como inserir em uma Árvore Binária e imprimir?

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
    NoArvore *raiz = NULL;
    int opcao, valor;
    
    do
    {
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Imprimir\n");
        scanf("%d", &opcao);
        
        switch (opcao)
        {
            case 1:
                printf("Digite um valor: ");
                scanf("%d", &valor);
                raiz = inserirVersao1(raiz, valor);
                break;
            case 2:
                printf("\n\tPrimeira impressao:\n");
                imprimirVersao1(raiz);
                printf("\n");
                printf("\n\tSegunda impressao:\n");
                imprimirVersao2(raiz);
                printf("\n");
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