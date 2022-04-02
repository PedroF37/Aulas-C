#include <stdio.h>
#include <stdlib.h>

/*
                            Aula 01: Lista Simplesmente Enadeada
                            Como inserir no inicio da lista?
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


int main()
{
    return(0);
}