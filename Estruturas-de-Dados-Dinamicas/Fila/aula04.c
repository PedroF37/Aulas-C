#include <stdio.h>
#include <stdlib.h>

/*
                            Aula 04: Como fazer uma FILA com vários tipos de dados?
                            
                            FIFO - First-In, First-Out - Primeiro a Enttrar, Primeiro a Sair
*/


typedef struct
{
    int dia, mes, ano;
}
Data;


typedef struct
{
    char rua[50];
    char bairro[50];
    char cidade[50];
    char pais[50];
    int numero, cep;
}
Endereco;


typedef struct
{
    int codigo;
    Data dataAssinatura;
    char cargo[50];
    float salario;
}
Contrato;

typedef struct
{
    char nome[50];
    Data dataNascimento;
    Endereco endereco;
    Contrato contrato;
}
Pessoa;

typedef struct no
{
    Pessoa pessoa;
    struct no *proximo;
}
No;


/* ----------------------------------- Impressão das informações de uma Pessoa ------------------------------------------------ */


void imprimirData(Data data)
{
    printf("%d/%d/%d\n", data.dia, data.mes, data.ano);
}


void imprimirEndereco(Endereco endereco)
{
    printf("\tEndereço:\n");
    printf("\t\tRua: %s", endereco.rua);
    printf("\t\tBairro: %s", endereco.bairro);
    printf("\t\tCidade: %s", endereco.cidade);
    printf("\t\tPais: %s", endereco.pais);
    printf("\t\tNumero: %d\n", endereco.numero);
    printf("\t\tCEP: %d\n", endereco.cep);
}


void imprimirContrato(Contrato contrato)
{
    printf("\tContrato %d:\n", contrato.codigo);
    printf("\t\tCargo: %s", contrato.cargo);
    printf("\t\tSalario: R$%.2f\n", contrato.salario);
    printf("\t\tData de Admissao: ");
    imprimirData(contrato.dataAssinatura);
}


void imprimirPessoa(Pessoa pessoa)
{
    printf("\n\tNome: %s", pessoa.nome);
    printf("\n\tData de Nascimento: ");
    imprimirData(pessoa.dataNascimento);
    imprimirEndereco(pessoa.endereco);
    imprimirContrato(pessoa.contrato);
}


/* ---------------------------------------- Leitura dos dados de um Pessoa ------------------------------- */


Data lerData()
{
    Data data;
    
    printf("\nDigite a data no formato dd mm aaaa: ");
    scanf("%d%d%d", &data.dia, &data.mes, &data.ano);
    getchar();
    
    return(data);
}


Endereco lerEndereco()
{
    Endereco endereco;
    
    printf("\nRua: ");
    fgets(endereco.rua, 49, stdin);
    
    printf("\nBairro: ");
    fgets(endereco.bairro, 49, stdin);
    
    printf("\nCidade: ");
    fgets(endereco.cidade, 49, stdin);
    
    printf("\nPais: ");
    fgets(endereco.pais, 49, stdin);
    
    printf("\nNumero: ");
    scanf("%d", &endereco.numero);
    
    printf("\nCEP: ");
    scanf("%d", &endereco.cep);
    
    getchar();
    return(endereco);
}


Contrato lerContrato()
{
    Contrato contrato;
    
    printf("\nCodigo do Contrato: ");
    scanf("%d", &contrato.codigo);
    
    printf("\nData de Assinatura: ");
    contrato.dataAssinatura = lerData();
    
    printf("\nCargo ocupado: ");
    fgets(contrato.cargo, 49, stdin);
    
    printf("\nSalario: ");
    scanf("%f", &contrato.salario);
    getchar();
    
    return(contrato);
}


Pessoa lerPessoa()
{
    Pessoa pessoa;
    
    printf("\nNome: ");
    fgets(pessoa.nome, 49, stdin);
    
    printf("\nData de Nascimento: ");
    pessoa.dataNascimento = lerData();
    
    printf("\nContrato: ");
    pessoa.contrato = lerContrato();

    printf("\nEndereco: ");
    pessoa.endereco = lerEndereco();
    
    return(pessoa);
}


/* --------------------------------------------------------------------------------------------------- */


/*
    Procedimento para inserir na fila
*/
void inserirNaFila(No **fila, Pessoa pessoa)
{
    No *aux, *novo = malloc(sizeof(No));
    
    if (novo != NULL)
    {
        novo->pessoa = pessoa;
        novo->proximo = NULL;
        
        if (*fila == NULL)
        {
            *fila = novo;
        }
        else
        {
            aux = *fila;
            
            while (aux->proximo != NULL)
            {
                aux = aux->proximo;
            }
            
            aux->proximo = novo;
        }
    }
    else
    {
        printf("\nErro ao alocar memoria!\n");
    }
}


/*
    Função para remover elemento da fila
*/
No* removerDaFila(No **fila)
{
    No *remover = NULL;
    
    if (*fila != NULL)
    {
        remover = *fila;
        *fila = remover->proximo;
    }
    else
    {
        printf("\nFila vazia!\n");
    }
    
    return(remover);
}


/* Procedimentoo para imprimir a fila */
void imprimir(No *fila)
{
    printf("\t---------- FILA -------------\n\t");
    
    while (fila != NULL)
    {
        imprimirPessoa(fila->pessoa);
        
        /* Enquanto tiver elementos temos que apontar para o proximo*/
        fila = fila->proximo;
        
        if (fila != NULL)
        {
            printf("\t----------------------------\n\t");
        }
    }
    
    printf("\n\t---------- FIM FILA -------------\n");
}


int main()
{
    No *remover, *fila = NULL;
    int opcao;
    Pessoa pessoa;
    
    do
    {
        printf("\t0 - Sair\n\t1 - Inserir\n\t2 - Remover\n\t3 - Imprimir\n");
        scanf("%d", &opcao);
        getchar();
        
        switch (opcao)
        {
            case 1:
                pessoa = lerPessoa();
                inserirNaFila(&fila, pessoa);
                break;
            case 2:
                remover = removerDaFila(&fila);
                
                if (remover != NULL)
                {
                    imprimirPessoa(remover->pessoa);
                    free(remover);
                }
                break;
            case 3:
                imprimir(fila);
                break;
            default:
                
                if (opcao != 0)
                {
                    printf("\nOpção invalida!\n");
                }
        }
    }
    while (opcao != 0);
    
    return(0);
}