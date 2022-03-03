#include <stdio.h>
#include <stdlib.h>

/*

                              Aula 03: Organizando nosso código em procedimentos.

*/

void escrever(char f[])
{
    FILE *handle = fopen(f, "w");
    char letra;
    
    if (handle)
    {
        printf("\nDigite um texto e pressione ENTER ao finalizar!\n");
        scanf("%c", &letra);
        
        while (letra != '\n')
        {
            fputc(letra, handle);
            scanf("%c", &letra);
        }
        
        fclose(handle);
    }
    else
        printf("\nErro ao abrir arquivo!\n");
}

void ler(char f[])
{
    FILE *handle = fopen(f, "r");
    char letra;
    
    if (handle)
    {
        printf("\n\tTexto lido do arquivo:\n");
        while (!feof(handle))
        {
            letra = fgetc(handle);
            printf("%c", letra);
        }
        printf("\n");
        
        fclose(handle);
    }
    else
        printf("\nErro ao abrir arquivo!\n");
}

int main()
{
    char nome[] = {"conto.txt"};
    
    escrever(nome);
    ler(nome);
    
    return(0);
}