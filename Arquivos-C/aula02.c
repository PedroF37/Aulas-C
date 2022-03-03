#include <stdio.h>
#include <stdlib.h>

/*

                     Aula 02: Como lêr em arquivo de texto com a função fgetc?

*/

int main()
{
    FILE *handle;
    char letra;
    
    handle = fopen("conto.txt", "w+");    // ou fopen("/home/pedro/.....txt), e "w+" escreve e lê
    
    if (handle)     // ou, if (handle != NULL)
    {
        printf("\nDigite um texto e pressione ENTER ao finalizar! ");
        scanf("%c", &letra);
        
        while (letra != '\n')
        {
            fputc(letra, handle);
            scanf("%c", &letra);
        }
        
        rewind(handle); // rewind, rebobina, volta  atrás; como vamos colocando caracter atrás de caracter, no final o handle (o ponteiro) aponta para o final do arquivo,
                        // e como queremos ler então usamos o rewind para voltar para o inicio do arquivo.
        
        printf("\n\tTexto lido do arquivo:\n");
        while (!feof(handle))   // feof -> end of file. esta função retorna verdade se tiver chegado no fim do arquivo, por isso usamos a negação: !feof, assim estamos a dizer:
        {                       // enquanto nõa chegarmos no fim do arquivo, faz o que vem a seguir
            letra = fgetc(handle);
            printf("%c", letra);
        }
        printf("\n");
        
        fclose(handle);
    }
    else
        printf("\n\t--> ERRO ao abrir arquivo!\n");
    return(0);
}