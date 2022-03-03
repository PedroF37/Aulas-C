#include <stdio.h>
#include <stdlib.h>

/*

                               Aula 01: Como escrever em arquivo de texto com a função fputc?
                               
                               Modos de abertura de arquivos:
                               
                               w -> Escrita
                               r -> Leitura
                               a -> Anexar
                               r+ -> Leitura e Escrita
                               w+ -> Leitura e Escrita (apaga o conteúdo caso o arquivo exista)
                               a+ -> Leitura e Escrita (adiciona no final do arquivo)


*/

int main()
{
    FILE *handle;
    char letra;
    
    handle = fopen("conto.txt", "w");    // ou fopen("/home/pedro/.....txt)
    
    if (handle)     // ou, if (handle != NULL)
    {
        printf("\nDigite um texto e pressione ENTER ao finalizar!");
        scanf("%c", &letra);
        
        while (letra != '\n')
        {
            fputc(letra, handle);
            scanf("%c", &letra);
        }
        
        fclose(handle);
    }
    else
        printf("\n\t--> ERRO ao abrir arquivo!\n");
    return(0);
}