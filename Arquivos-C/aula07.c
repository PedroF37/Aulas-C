#include <stdio.h>
#include <stdlib.h>


/*

                                  Aula 07: Como lêr um arquivo de texto com a função fscanf?

*/

void escrever(char f[])
{
    FILE *handle = fopen(f, "w");
    char nome[100];
    int opcao, idade;
    float altura;
    
    if (handle)
    {
        do
        {
            printf("Digite nome, idade e altura: ");
            scanf("%100[^\n]%d%f", nome, &idade, &altura);
            
            fprintf(handle, "%s %d %.2f\n", nome, idade, altura);
            
            printf("\nDigite 1 para inserir outro registro: ");
            scanf("%d", &opcao);
            getchar();
        }
        while (opcao == 1);
        
        fclose(handle);
    }
    else
        printf("\nERRO ao abrir arquivo!\n");
}


void ler(char f[])
{
    FILE *handle = fopen(f, "r");
    
    char nome[100];
    int idade;
    float altura;
    
    if (handle)
    {
        printf("\tDados lidos do arquivo:\n");
        
        while(fscanf(handle, "%s%d%f", nome, &idade, &altura) != -1)    // quando não consegue lêr mais nada no arquivo a função fscanf retorna -1, de resto vai retornando o número de registros lidos.
            printf("\n\tNome: %s\n\tIdade: %d\n\tAltura: %.2f\n", nome, idade, altura);
        
        fclose(handle);
    }
    else
        printf("\nERRO ao abrir arquivo!\n");
}


int main()
{
    char nome[] = {"conto.txt"};
    
    escrever(nome);
    ler(nome);
    
    return(0);
}