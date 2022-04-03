#include <stdio.h>
#include <stdlib.h>

/*                                  Aula 06: O que faz o modifiador static? */



/* Função recursiva sem o modificador static*/
/*
float mediaPares(int vet[], int tam, float soma, int quantidade)
{
    if (tam == 0)
    {
        return(soma / quantidade);
    }
    else
    {
        if (vet[tam - 1] % 2 == 0)
        {
            soma += vet[tam - 1];
            quantidade += 1;
            return(mediaPares(vet, tam - 1, soma, quantidade));
        }

        else
        {
            return(mediaPares(vet, tam - 1, soma, quantidade));
        }
    }
}
*/

// int valor = 50; Global neste arquivo e em qualquer outro que faça parte deste programa
// static int valor = 50;  Global dentro deste arquivo apenas

/* Com o modificador static*/
float mediaPares(int vet[], int tam)
{
    static int soma = 0, quantidade = 0;
    
    if (tam == 0)
    {
        //printf("%d\n\n", valor);
        return((soma * 1.0) / quantidade);
    }
    else
    {
        if (vet[tam - 1] % 2 == 0)
        {
            soma += vet[tam - 1];
            quantidade += 1;
            return(mediaPares(vet, tam - 1));
        }

        else
        {
            return(mediaPares(vet, tam - 1));
        }
    }
}



int main()
{
    int vet[6] = {2, 4, 38, 7, 11, 9};
    
    //printf("Media dos pares: %.2f\n", mediaPares(vet, 6, 0, 0)); -> sem o modificador static
    
    /* Com o modificador static */
    printf("Media dos pares: %.2f\n", mediaPares(vet, 6));
    //printf("\n%d\n", valor);
    return(0);
}
