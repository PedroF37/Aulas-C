#include <stdio.h>
#include <stdlib.h>

/*
                            Aula 02: Lista Simplesmente Enadeada
                            Como inserir no fim da lista?
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
void inserirNofim(No **lista, int num)
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


int main()
{
    return(0);
}