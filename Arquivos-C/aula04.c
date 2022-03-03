#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*

                              Aula 04: Como escrever linhas de texto com a função fputs?

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
        printf("\nErro ao abrir arquivo!\n");
}


int main()
{
    char nome[] = {"conto.txt"};
    
    escrever(nome);

    
    return(0);
}