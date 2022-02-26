#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
                       Aula 05: Como liberar a memória dinâmicamente alocada com a função free

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
        
        free(vet);
    }
    else
    {
        printf("Erro ao alocar memória!\n");
    }
    return(0);
}   