#include <stdio.h>
#include <stdlib.h>

/*
                        Aula 05:
                        
                        Escreva um algoritmo para inverter a ordem das letras de cada palavra de uma string,
                        preservando a ordem das palavras. Por exemplo, dado o texto:
                        
                        ABRA A PORTA MARIQUINHA
                        
                        deve mostrar
                        
                        ARBA A ATROP ANHIUQIRAM
                        
                        0 1 2 3 4  5 6  7 8 9 10 11
                        A B R A '' A '' P O R T  A
                       
                        PILHA:
                        A                         ARBA
                        R
                        B
                        A
*/

typedef struct no
{
    char caracter;
    struct no *proximo; 
}
No;


/* Função para empilhar */
No* empilhar(No *topo, char caracter)
{
    No *novo = malloc(sizeof(No));
    
    if (novo != NULL)
    {
        novo->caracter = caracter;
        novo->proximo = topo;
        return(novo);
    }
    else
    {
        printf("\nErro ao alocar memoria!\n");
    }
    
    return(NULL);
}


/* Função para desempilhar */
No* desempilhar(No **topo)
{
    No *remover = NULL;
    
    if (*topo != NULL)
    {
        remover = *topo;
        *topo = remover->proximo;
    }
    else
    {
        printf("\nPilha vazia!\n");
    }
    
    return(remover);
}

void inverter(char frase[])
{
    No *remover, *topo = NULL;
    int i = 0;
    
    while (frase[i] != '\0')
    {
        if (frase[i] != ' ')
        {
            topo = empilhar(topo, frase[i]);
        }
        else
        {   
            while (topo != NULL)
            {
                remover = desempilhar(&topo);
                printf("%c", remover->caracter);
                free(remover);
            }
            
            printf("%c", frase[i]);
        }
        
        i++;
    }
    
    while (topo != NULL)
    {
        remover = desempilhar(&topo);
        printf("%c", remover->caracter);
        free(remover);
    }
            
    printf("%c\n", frase[i]);
}


int main()
{
    char frase[50];
    
    printf("\nDigite uma frase: ");
    scanf("%49[^\n]", frase);
    
    inverter(frase);
    
    return(0);
}