#include <stdio.h>
#include <stdlib.h>


/*

                                     Exercicio 1:
                                     
                                     Escreva um procedimento que receba um vetor inteiro, o seu tamanho e os endereços de duas
                                     variaveis inteiras, menor e maior, salve nestas variaveis o menor e o maior valor do vetor.


*/

void maiorMenor(int vet[], int tam, int *Maior, int *Menor)
{
    int i;
    *Maior = *vet;
    *Menor = *vet;
    
    for (i = 1; i < tam; i++)
    {
        if (*(vet + i) > *Maior)
            *Maior = *(vet + i);
        
        if (*(vet + i) < *Menor)
            *Menor =  *(vet + i);
    }
    
}

int main()
{
    int vet[6] = {10, 5, 1, 15, 37, 2}, maior, menor;
    
    maiorMenor(vet, 6, &maior, &menor);
    
    printf("\nO maior elemento no vetor: %d\n", maior);
    printf("\nO menor elemento no vetor: %d\n", menor);
    return(0);
}