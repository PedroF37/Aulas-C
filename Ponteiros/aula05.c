#include <stdio.h>
#include <stdlib.h>

/*

                            Aula 05: Vetor é sempre um ponteiro?

*/

void teste(int vet[], int tam)
{
    int i;
    
    for (i = 0; i < tam; i++)
        vet[i] = vet[i] * 2;
    
    printf("\n");
}


void imprimir(int vet[], int tam)
{
    int i;
    
    for (i = 0; i < tam; i++)
        printf("%d ", vet[i]);
    
    printf("\n");
}

int main()
{
    int vet[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    imprimir(vet, 10);
    teste(vet, 10);
    imprimir(vet, 10);
    return(0);
}