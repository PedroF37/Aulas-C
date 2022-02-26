#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*

                       Aula 04: Alocação dinâmica de memória com a função realloc.
                       
                       -> Retorna um ponteiro para a nova regiao de memória.
                       -> Se o ponteiro for nulo ela aloca a memória.
                       -> Se o novo tamanho for zero a memória é liberada.
                       -> Se não houver memória suficiente retorna null.

*/

int main()
{
    int tam, i, *vet;
    
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tam);
    
    srand(time(NULL));
    
    vet = malloc(tam * sizeof(int));
    
    if (vet)
    {
        for (i = 0; i < tam; i++)
            *(vet + i) = rand() % 100;
        
        for (i = 0; i < tam; i++)
            printf("%d ", *(vet + i));
        
        printf("\n");
        
        printf("Digite o novo tamanho do vetor: ");
        scanf("%d", &tam);
        
        vet = realloc(vet, tam);
        
        printf("\nVetor realocado:\n");
        for (i = 0; i < tam; i++)
            printf("%d ", *(vet + i));
        
        printf("\n");
    }
    else
    {
        printf("Erro ao alocar memória!\n");
    }
    return(0);
}   