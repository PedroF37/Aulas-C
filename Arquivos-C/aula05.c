#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*

                              Aula 05: Como ler linhas de texto com a função fgets?

*/

void escrever(char f[])
{
    FILE *handle = fopen(f, "w");
    char texto[500];
    
    if (handle)
    {
        printf("Digite uma fraseou 1 caracter para finalizar:\n");
        scanf("%500[^\n]", texto);
        getchar();  // em vez da scanf pudemos usar a fgets(), e ai não temos problema do buffer do teclado
        
        while (strlen(texto) > 1)
        {
            fputs(texto, handle);   // aqui as linhas vão ficar coladas sem quebra de linha, porque o scanf não lê o enter.
            fputc('\n', handle);     // em vez disto podemos usar o fgets(), porque ele lê o enter (\n)
            scanf("%500[^\n]", texto);
            getchar();

        }
        fclose(handle);
    }
    else
        printf("\nERRO ao abrir arquivo!\n");
}

void ler(char f[])
{
    FILE *handle = fopen(f, "r");
    char texto[500];
    
    if (handle)
    {
        printf("\n\tTexto lido do arquivo:\n");
        
        while (!feof(handle))
        {
            if (fgets(texto, 500, handle) != 0)     // ou, if (fgets(texto, 500, handle))   -> quando não tem mais nada para ler o fgets retorna 0
                printf("\n --> %s", texto);         // por isso, enquanto retornar diferente de 0
        }
        
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