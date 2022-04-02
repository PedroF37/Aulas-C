#include <stdio.h>
#include <stdlib.h>

/*
    Aula 04: Como descobrir se uma expressão matemática está mal formada?
    
    3 * [(5 - 2) / 5]
    3 * [(5 - 2) / 5
    
    Processo com Pilha:
    
    1 - encontarmos o [, então empilhamos o [
    2 - encontramos o (, então empilhamos o (
    3 - encontramos o ), então DESEMPILHAMOS!! o (
    4 - encontramos o ], então DESEMPILHAMOS o [
    
    Ao desempilhar, o elemento que desempilhamos, tem que coincidir com o elemento de fechamento, ou seja
    quando desempilharmos o (, tem que ser porque encontramos o ), se isso não acontecer, então a expressão está mal formada.
    
    No segundo exemplo:
    
    1 -encontramos o [, entao empilhamos o [
    2 -encontramos o (, então empilhamos o (
    3 -encontramos o ) (fechamento), então DESEMPILHAMOS o ( (abertura)
    4 -NÃO ENCONTRAMOS O ] (fechamento), mas temos na pilha ainda o [ (abertura)
    
    Logo, a expressão está mal formada!!
    
    
*/

typedef struct no
{
    char caracter;
    struct no *proximo;
}
No;


No* empilhar(No *pilha, char valor)
{
    No *novo = malloc(sizeof(No));
    
    if (novo)
    {
        novo->caracter = valor;
        novo->proximo = pilha;
        return(novo);
    }
    else
    {
        printf("\nNão foi possivel alocar memoria!\n");
    }
    
    return(NULL);
}


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

void imprimir(No *pilha)
{
    printf("\tPILHA\n");
    
    while (pilha)
    {
        printf("\t%c\n", pilha->caracter);
        pilha = pilha->proximo;
    }
    
    printf("\tFIM PILHA\n");
}


/*
    return(0) -> mal formada
    return(1) -> bem formada
*/
int formaPar(char f, char d)
{
    switch (f)
    {
        case ')':
            if (d == '(')
            {
                return(1);
            }
            else
            {
                return(0);
            }
            break;
        case ']':
            if (d == '[')
            {
                return(1);
            }
            else
            {
                return(0);
            }
            break;
        case '}':
            if (d == '{')
            {
                return(1);
            }
            else
            {
                return(0);
            }
            break;
        default:
            return(0);
    }
}


int identificaFormacao(char x[])    // 3 * (5 - 2) / 5]
{
    int i = 0;
    No *remover, *pilha = NULL;
    
    while (x[i] != '\0')
    {
        if (x[i] == '[' || x[i] == '(' || x[i] == '{')  // (
        {
            pilha = empilhar(pilha, x[i]);
            imprimir(pilha);
        }
        
        else if (x[i] == ']' || x[i] == ')' || x[i] == '}') // ) ]
        {
            remover = desempilhar(&pilha);
            
            /*
                Na expressão comentada: 3 * (5 - 2) / 5],
                quando chegar no ], a pilha vai estar vazia,
                sendo assim vai dar erro, porque a função formaPar pega
                o caracter de fechamento (o ]) e o caracter de abertura (o [)
                mas neste caso desta expressão, quando chegamos ao ] não tem na pilha o [
                e a pilha está vazia, então nós testamos se o ponteiro remover aponta para algo valido
                ou para nulo e só chamamos a função se ele apontar para algo válido, ou seja se não for NULL. 
            */
            if (remover != NULL)
            {
                /* return(0) == falso, não forma par */
                if (formaPar(x[i], remover->caracter) == 0)
                {
                    printf("\nEXPRESSAO MAL FORMADA!\n");
                
                    /* Expressão mal formada */
                    return(1);
                }
            
                free(remover);
            }
            else
            {
                /*
                    Se remover for nulo, então quer dizer que encontramos caracter de fechamento, mas na pilha nõa tem
                    caracter de abertura porque a pilha está vazia, logo a expressão está mal formada.
                */
                 printf("\nEXPRESSAO MAL FORMADA!\n");
                 return(1);
            }
        }
        
        i++;
    }
    
    imprimir(pilha);
    
    if (pilha)
    {
        printf("\tExpressao mal formada!\n");
        return(1);
    }
    else
    {
        printf("\nEXPRESSAO BEM FORMADA!\n");
        return(0);
    }
}


int main()
{
    char exp[50];
    
    printf("Digite uma expressao: ");
    scanf("%49[^\n]", exp);
    
    printf("\nExpressao: %s\nRetorno: %d\n", exp, identificaFormacao(exp));
    return(0);
} 