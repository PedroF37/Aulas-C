#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

/* Função para empilhar */
No* empilhar(No *pilha, int num)
{
    No *novo = malloc(sizeof(No));
    
    if (novo)
    {
        novo->valor = num;
        novo->proximo = pilha;
        return(novo);
    }
    else
    {
        printf("\nErro ao alocar memoria!\n");
    }
    
    return(NULL);
}


/* Função para desempilhar */
No* desempilhar(No **pilha)
{
    No *remover = NULL;
    
    if (*pilha)
    {
        remover = *pilha;
        *pilha = remover->proximo;
    }
    else
    {
        printf("\nPilha vazia!\n");
    }
    
    return(remover);
}


/* Procedimento para imprimir a pilha */
void imprimir(No *pilha)
{
    printf("\n\tPILHA\n");
    
    while (pilha)
    {
        printf("\t%d\n", pilha->valor);
        pilha = pilha->proximo;
    }
    
    printf("\n");
}
