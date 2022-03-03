#include <stdio.h>
#include <stdlib.h>


/*

                                  Aula 06: Como escrever em um arquivo texto com a função fprintf?

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

int main()
{
    char nome[] = {"conto.txt"};
    
    escrever(nome);
    return(0);
}