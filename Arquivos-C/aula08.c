#include <stdio.h>
#include <stdlib.h>


/*

                             Aula 08: Escrevendo em arquivo binário com a função fwrite()
                                      Lendo o arquivo com fread()
                             
                             Modos de abertura de arquivos:
                             
                             wb -> Escrita
                             rb -> Leitura
                             ab -> Anexar
                             rb+ -> Leitura e Escrita
                             wb+ -> Leitura e Escrita (apaga o conteúdo caso o arquivo exista)
                             ab+ -> Leitura e Escrita (adiciona no final do arquivo)


*/

typedef struct
{
    char nome[50];
    int dia, mes, ano;
}
Contato;


void escrever(char arq[])
{
    Contato c;
    FILE *handle = fopen(arq, "ab");
    
    if (handle)
    {
        printf("Digite o nome e data de nascimento no formato dd mm aaaa: ");
        scanf("%49[^\n]%d%d%d", c.nome, &c.dia, &c.mes, &c.ano);
        
        fwrite(&c, sizeof(Contato), 1, handle);
        fclose(handle);
    }
    else
    {
        printf("\nErro ao abrir arquivo!\n");
    }
}


void ler(char arq[])
{
    Contato c;
    FILE *handle = fopen(arq, "rb");
    
    if (handle)
    {
        while (!feof(handle))
        {
            if (fread(&c, sizeof(Contato), 1, handle) != 0)     // ou if (fread(&c, sizeof(Contato), 1, handle))
                printf("\nNome: %s\nData: %d/%d/%d\n", c.nome, c.dia, c.mes, c.ano);
        }
        
        fclose(handle);
    }
    else
    {
        printf("\nErro ao abrir arquivo\n");
    }
}


int main()
{
    char arquivo[] = {"agenda.dat"};
    escrever(arquivo);
    ler(arquivo);
    
    return(0);
}