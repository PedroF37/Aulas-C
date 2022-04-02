#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
                                       Aula 04: Tabela Hash com STRING
*/


#define TAM 11


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
    char nome[50];  // Vai ser a chave nesta tabela
    int cpf;
    Data dataNascimento;
    Endereco endereco;
    Contrato contrato;
}
Pessoa;


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
    printf("\tCPF: %d\n", pessoa.cpf);
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
    
    printf("\nCPF: ");
    scanf("%d", &pessoa.cpf);
    
    printf("\nData de Nascimento: ");
    pessoa.dataNascimento = lerData();
    
    printf("\nContrato: ");
    pessoa.contrato = lerContrato();

    printf("\nEndereco: ");
    pessoa.endereco = lerEndereco();
    
    return(pessoa);
}


/* ------------------------------ Funções e Procedimentos para a tabela hash ----------------------------------- */



void inicializarTabela(Pessoa t[])
{
    int i;
    
    for (i = 0; i < TAM; i++)
    {
        strcpy(t[i].nome, "");  // nome que vai ser a chave vai iniciar com vazio
    }
}


/* Função Hash ou de espalhamento para as colisões*/
int funcaoHash(int chave)
{
    return(chave % TAM);
}


/* Função para transformar os caracteres em números para as inserções */
int funcaoHashString(char str[])    // Amanda
{
    int i, tamStr = strlen(str);
    unsigned int hash = 0;
    
    for (i = 0; i < tamStr; i++)
    {
        hash += str[i] * (i + 1);
    }
    
    return(hash % TAM);
}


/* Procedimento para inserir na tabela */
void inserir(Pessoa t[])
{
    /*
        Vai retornar uma Pessoa, já com o CPF
        O cpf vamos enviar para a função hash
    */
    Pessoa p = lerPessoa();
    int id = funcaoHashString(p.nome);  // esta gera o id para a Pessoa a partir do nome (caracteres, transforma os caracteres em números
                                        // para gerar o id
    
    while (strlen(t[id].nome) > 0)  // Deu colisão, já tem alguém na posição
    {
        id = funcaoHash(id + 1); // Esta serve para isto, se já tem algém na posição esta vai colocar na proxima vaga
    }
    
    t[id] = p;
}


/* Fução para buscar na tabela */
Pessoa* busca(Pessoa t[], char chave[])
{
    /*
        Retorna um ponteiro para Pessoa,
        assim, se acharmos o valor, retornamos o endereço
        na memória para essa Pessoa com o valor (&t[id].nome),
        e se o loop while terminar e não achar nada, então retornamos
        NULL.
    */
    int id = funcaoHashString(chave);
    printf("\nIndice Gerado: %d\n", id);
    
    while (strlen(t[id].nome) > 0)
    {
        /*
            strcmp retorno:
            
            numero negativo -> primeiro nome ocorre primeiro
            numero positivo -> segundo nome ocorre primeiro
            retorno zero (0) -> os nomes são iguais
        */
        if (strcmp(t[id].nome, chave) == 0)
        {
            return(&t[id]);
        }
        else
        {
            id = funcaoHash(id + 1);
        }
    }
    
    return(NULL);
}


/* Procedimento para imprimir a tabela */
void imprimir(Pessoa t[])
{
    int i;
    
    for (i = 0; i < TAM; i++)
    {
        printf("%d\n", i);
        
        if (strlen(t[i].nome) > 0)
        {
            imprimirPessoa(t[i]);
        }
        
        printf("\n-------------------------------------\n");
    }
}


int main()
{
    int opcao;
    Pessoa *buscar, tabela[TAM];
    char nome[50];
    
    inicializarTabela(tabela);
    
    do
    {
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Buscar\n\t3 - Imprimir\n");
        scanf("%d", &opcao);
        getchar();
        
        switch (opcao)
        {
            case 1:
                
                inserir(tabela);
                break;
            case 2:
                printf("\tDigite o nome para buscar: ");
                fgets(nome, 49, stdin);
                buscar = busca(tabela, nome);
                
                if (buscar != NULL)
                {
                    printf("\nCPF encontrado:\n");
                    imprimirPessoa(*buscar);
                }
                else
                {
                    printf("\tCPF não encontrado\n");
                }
                break;
            case 3:
                imprimir(tabela);
                break;
            default:
                if (opcao != 0)
                {
                    printf("\nOpçao invalida!\n");
                }
        }
    }
    while (opcao != 0);
    return(0);
}