/*                                    AGENDA DE ANIVERSÁRIO (suporte binario    )                               */


#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    char nome[50];
    int dia, mes, ano;
}
Contato;


/*
    Procedimento para impprimir na tela os contatos
    inseridos até ao momento na agenda.
    
    Recebe a agenda e a quantidade de contatos que estão
    na agenda até ao momento.
*/
void imprimir(Contato **c, int quant)
{
    int i;
    
    printf("\n\t\t\t\tAGENDA DE ANIVERSARIO\n");
    printf("\n\t\t--------------------------------------------------\n");
    
    for (i = 0; i < quant; i++)
    { 
        printf("\t\t%d - %2d/%2d/%4d\t%s\n",
        i + 1, c[i]->dia, c[i]->mes, c[i]->ano, c[i]->nome);
    }
    
    printf("\n\t\t--------------------------------------------------\n");
}


/*
    Função Cadastrar, que vai inserir os contatos na agenda.
    
    Recebe como parâmetros, a agenda, o tamanho do vetor e
    a quantidade de contatos cadastrados até ao momento.
    
    Só cadastra um novo contato se a quantidade de contatos
    já cadastrados for menor que o tamanho do vetor.
    
    Retorna 1 caso tenha sucesso ao cadastrar, ou 0 se
    não conseguir cadastrar.
*/
int cadastrar(Contato **c, int tam, int quant)
{
    if (quant < tam)
    {
        Contato *novo = malloc(sizeof(Contato));

        printf("Digite o nome e data de nascimento no formato dd mm aaaa: ");
        scanf("%50[^\n]%d%d%d", novo->nome, &novo->dia, &novo->mes, &novo->ano);
        
        c[quant] = novo;
        return(1);
    }
    else
    {
        printf("\nNão é possivel cadastrar novo contato! Agenda está cheia!\n");
        return(0);
    }
}


/*
    Procedimento para alterar dados dos contatos
    
    Recebe como parâmetros a agenda e a quantidade
    de registros até ao momento, para validar o valor
    digitado pelo usuário.
*/
void alterarContato(Contato **c, int quant)
{
    int id;
    
    imprimir(c, quant);
    
    printf("\nDigite o id do contato a alterar: ");
    scanf("%d", &id);
    getchar();
    
    id--;
    
    if (id >= 0 && id < quant)
    {
        printf("Digite o novo nome e data de nascimento no formato dd mm aaaa: ");
        scanf("%49[^\n]%d%d%d", c[id]->nome, &c[id]->dia, &c[id]->mes, &c[id]->ano);
    }
    else
    {
        printf("\nId digitado é inválido!\n");
    }
}


/*
    Procedimento para salvar registros em arquivo de texto.
    
    Recebe como parâmetros a agenda, o arquivo alvo e a
    quantidade de registros até ao momento.
    
    Não precisa retornar nada, pois vai apenas gravar no arquivo,
    mas todas as leituras e manipulações na agenda são feitas em
    memória.
*/
void salvar(Contato **c, int quant, char arq[])
{
    FILE *handle = fopen(arq, "w");
    int i;
    
    if (handle)
    {
        fprintf(handle, "%d\n", quant);
        
        for (i = 0; i < quant; i++)
        {
            fputs(c[i]->nome, handle);
            fputc('\n', handle);
            fprintf(handle, "%d %d %d\n", c[i]->dia, c[i]->mes, c[i]->ano);
        }
        
        fclose(handle);
    }
    else
    {
        printf("Não foi possivel criar/abrir arquivo!\n");
    }
    
}


/*
    Função para carregar arquivo para vetor de Contatos
    (ponteiros para Contatos...)
    
    Recebe como parâmetros o vetor (agenda), e o arquivo
    de onde vai pegar os registros para carregar para a memória.
    
    Retorna a quantidade de registros carregados do arquivo, para
    depois puder imprimir e manipular os registros na memória
*/
int ler(Contato **c, char arq[])
{
    FILE *handle = fopen(arq, "r");
    int i, quant = 0;
    
    if (handle)
    {
        /* Só declara, mas aloca apenas se for necessário no loop for */
        Contato *novo;
        fscanf(handle, "%d\n", &quant);
        
        for (i = 0; i < quant; i++)
        {
            /* Vai alocar apenas se i for menor que quant */
            novo = malloc(sizeof(Contato));
            
            fscanf(handle, "%49[^\n]", novo->nome);
            fscanf(handle, "%d%d%d\n", &novo->dia, &novo->mes, &novo->ano);
            c[i] = novo;
        }
        
        fclose(handle);
        
    }
    else
    {
        printf("\nNão foi possivel abrir arquivo!\n");
    }
    
    return(quant);
}


/*
    Procedimento para salvar a agenda em arquivo binário
    
    Recebe como parâmetros o arquivo alvo, a agenda (vetor de ponteiros)
    e a quantidade de registros na agenda até ao momento.
*/
void salvarB(char arq[], Contato **c, int quant)
{
    FILE *handle = fopen(arq, "wb");
    int i;
    
    if (handle)
    {
        for (i = 0; i < quant; i++)
        {
            fwrite(c[i], sizeof(Contato), 1, handle);
        }
        
        fclose(handle);
    }
    else
    {
        printf("\nErro ao abrir arquivo!\n");
    }
}


/*
    Função para lêr do arquivo binário.
    
    Recebe como parâmetros o arquivo alvo, e o vetor
    de ponteiros para salvar na memória.
    
    Retorna a quantidade de registros que foram lidos
    do arquivo.
*/
int lerB(char arq[], Contato **c)
{
    int quant = 0;
    Contato *novo = malloc(sizeof(Contato));
    FILE *handle = fopen(arq, "rb");
    
    if (handle)
    {
        while (fread(novo, sizeof(Contato), 1, handle))
        {
            c[quant] = novo;
            quant++;
            novo = malloc(sizeof(Contato));
        }
        
        fclose(handle);
    
    }
    else
    {
        printf("\nErro ao abrir arquivo!\n");
    }
    
    return(quant);
}


/* Procedimento para alterear registro no arquivo binário */
void alterarB(char arq[])
{
    /*
        Temos que carregar o arquivo, para descobrir qual registro
        vamos alterar. Então, o modo de abertuura é para ler (r),
        binário (b) e vamos escrever também, pois vamos alterar algum registro,
        então (+);
    */
    FILE *handle = fopen(arq, "rb+");
    Contato c;
    int id, i = 1;
    
    if (handle)
    {
        printf("\tLista de Contatos:\n");
        printf("\t------------------------------------\n");
        
        while (fread(&c, sizeof(Contato), 1, handle))
        {
            printf("\t%d - %2d/%2d/%4d\t%s\n",
            i, c.dia, c.mes, c.ano, c.nome);
            i++;
        }
        printf("\t------------------------------------\n");
        
        printf("\n\tDigite o indice do contato que quer alterar:\n\n");
        scanf("%d", &id);
        
        getchar();
        
        /* id-- porque o usuário vai digitar 1 mas para o pc o 1 é zero, tal como em vetor */
        id--;
        
        /*
            id < i - 1, porque no while acima vai chegar o momento
            e que o teste dá falso, mas o i foi já incrementado em 1.
        */
        if (id >= 0 && id < i - 1)
        {
            printf("\tDigite nome e data de nascimento no formato dd mm aaaa: ");
            scanf("%49[^\n]%d%d%d", c.nome, &c.dia, &c.mes, &c.ano);
            
            /*
                fseek: para mover o ponteiro (handle) para um determinado ponto
                no arquivo.
                
                fseek(ponteiro-que-queremos mover, deslocamento-que queremos (bytes), a-partir-de-qual-local);
                
                Neste caso o ponteiro (handle), vai estar apontado para o final do arquivo,
                porque nós percorremos o arquivo todo no while acima.:
                
                Aqui, se o usuário digitar 1, a variável id é decrementada, então 1 passa a ser 0.
                0 vezes a quantidade de memória que ocupa o tipo Contato, fazemos o deslocamento a partir
                do inicio do arquivo (SEEK_SET).
                
                SEEK_CUR -> a partir do local atual do ponteiro
                SEEK_END -> a partir do final do arquivo
                SEEK_SET -> a partir do inicio do arquivo
            */
            fseek(handle, id * sizeof(Contato), SEEK_SET);
            fwrite(&c, sizeof(Contato), 1, handle);
        }
        
        fclose(handle);
    }
    else
    {
        printf("\nErro ao abrir arquivo!\n");
    }
}


int main()
{
    Contato *agenda[50];
    char arquivo[] = {"agenda.txt"};
    char arquivo2[] = {"agenda.dat"};
    int opcao, tam = 50;
    int quant = 0;
    
    do
    {
        printf("\n0 - Sair\n1 - Cadastrar\n2 - Alterar\n3 - Imprimir\n"
        "4 - Salvar\n5 - Ler\n6 - SalvarB\n7 - LerB\n8 - AlterarB\n");
        scanf("%d", &opcao);
        getchar();
        
        switch (opcao)
        {
            case 0:
                break;
            case 1:
                quant += cadastrar(agenda, tam, quant);
                break;
            case 2:
                alterarContato(agenda, quant);
                break;
            case 3:
                imprimir(agenda, quant);
                break;
            case 4:
                salvar(agenda, quant, arquivo);
                break;
            case 5:
                quant = ler(agenda, arquivo);
                break;
            case 6:
                salvarB(arquivo2, agenda, quant);
                break;
            case 7:
                quant = lerB(arquivo2, agenda);
                break;
            case 8:
                alterarB(arquivo2);
                break;
            default:
                printf("\nInput invalido!\n");
        }
    }
    while (opcao != 0);
    
    return(0);
}