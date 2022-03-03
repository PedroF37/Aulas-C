#include <stdio.h>
#include <stdlib.h>

/*                                 Aula 09: Como remover arquivo com a função remove() */

int main()
{
    char nome[] = {"conto.txt"};
    
    FILE *handle = fopen(nome, "r");
    
    if (handle)
    {
        printf("\nArquivo aberto com sucesso!\n");
        fclose(handle);
        
        /* Retorna 0 se teve sucesso ou -1 se não teve */
        if (!remove(nome))  // nega porque para o C 0 é falso, ou pudia fazer if (remove(nome) == 0)
        {
            printf("\nArquivo deletado com sucesso!\n");
        }
        else
        {
            printf("\nErro ao deletar arquivo!\n");
        }
    }
    else
    {
        printf("\nErro ao abrir arquivo!\n");
    }
    
    return(0);
}