#include <stdio.h>
#include <stdlib.h>

/*


                                                    Aula 16
                                                    
                                Dado um vetor de inteiros e o seu número de elementos,
                                inverta a posição dos seus elementos usando recursão.

*/

void troca(int vet[], int inicio, int fim)
{
    int auxiliar;
    if (inicio < fim)
    {
        auxiliar = vet[inicio];
        vet[inicio] = vet[fim];
        vet[fim] = auxiliar;
        troca(vet, inicio + 1, fim - 1);
    }
}

void imprimir(int vet[], int tamanho)
{
    if (tamanho == 1)
        printf("%d, ", vet[tamanho - 1]);
    else
    {
        imprimir(vet, tamanho - 1);
        printf("%d, ", vet[tamanho - 1]);
    }
}

int main()
{
    int vet[10] = {11, 258, 13, 445, 58, 67, 700, 8, 9, 10};
    
    imprimir(vet, 10);
    printf("\n");
    
    troca(vet, 0, 9);
    
    imprimir(vet, 10);
    printf("\n");
    
    return(0);
}
