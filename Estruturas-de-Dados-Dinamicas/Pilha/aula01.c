#include <stdio.h>
#include <stdlib.h>

/*
                             Aula 01: Estruturas  de dados dinâmicas (Pilha)
*/


typedef struct
{
    int dia, mes, ano;
}
Data;


typedef struct
{
    char nome[50];
    Data data;
}
Pessoa;


/*
    Criamos o tipo No, com o apelido no, que tem como dados internos
    a variável p do tipo Pessoa, e o ponteiro proximo
    com o endereço na memória (apontando) para a struct apelidada de no
    (que é simplesmente a struct ou tipo de dado NO);
    Ou seja, *proximo vai apontar para a proxima struct no.
*/
typedef struct no
{
    Pessoa p;
    struct no *proximo;
}
No;


/*
    Função lerPessoa, que registra os dados da pessoa (nome e nascimento)
    
    Retorna tipo de dado Pessoa (struct).
*/
Pessoa lerPessoa()
{
    Pessoa p;
    
    printf("\nDigite o nome e data de nascimento dd mm aaaa:\n");
    scanf("%49[^\n]%d%d%d", p.nome, &p.data.dia, &p.data.mes, &p.data.ano);
    
    return(p);
}


/*
    Procedimento para imprimir na tela a pessoa.
    
    Recebe como parâmetro variavel tipo Pessoa (struct)
*/
void imprimirPessoa(Pessoa p)
{
    printf("\nNome: %s\nData: %2d/%2d/%4d\n", p.nome, p.data.dia, p.data.mes, p.data.ano);
}


/*
    Função para a operação push (empilhar)
    
    Retorna um ponteiro (endereço) de um tipo de dado No (struct);
    o no (os dados) que foram empilhados no topo da Pilha.
    
    Recebe como parâmetro um ponteiro (endereço) para um tipo de dado
    No; Tipo de dado esse que estava no topo da pilha quando a função é
    chamada.
    
*/
No* empilhar(No *topo)
{
    /*
        Aloca a memória para o novo No (novo topo)
        Abaixo, no if (), preenche com os dados o novo topo
        e aponta o ponteiro proximo para o antigo topo,
        (que foi o parâmetro recebido pela função).
        Depois retorna o novo topo, que passa agora a ser
        o topo da Pilha.
    */
    No *novo = malloc(sizeof(No));
    
    if (novo)
    {
        novo->p = lerPessoa();
        novo->proximo = topo;
        return(novo);
    }
    else
    {
        printf("\nErro ao alocar memoria!\n");
    }
    
    return(NULL);
}


/*
    Função para desempilhar (pop)
    
    Retorna um ponteiro (endereço) de um tipo de dado No (struct);
    o no (os dados) que foram removidos (desempilhados) do topo da Pilha
    
    Recebe como parâmetro um ponteiro para ponteiro: Um ponteiro que aponta
    para um ponteiro que por sua vez aponta (tem o endereço) de um tipo de dado No
    (struct). Temos que passar ponteiro para ponteiro, porque no main(), o ponteiro
    *topo aponta (tem o endereço) do No topo da Pilha. Quando passamos apenas o *topo
    estamos passando uma cópia desse endereço (do topo da pilha), mas quando removemos,
    (desempilhamos) o No abaixo passa a ser o topo da Pilha. Mas como passamos apenas
    uma cópia para a função, no retorno vamos ter dois topos de pilha; o novo topo
    e o topo que não foi alterado no main().
    Por isso passamos ponteiro para ponteiro, ou seja passamos não o endereço do No mas sim o 
    endereço do ponteiro que tem o endereço do No. Assim quando sairmos da função (tendo sucesso),
    desempilhamos o antigo topo, e o ponteiro na função main vai apontar para o novo topo, porque como
    passamos o endereço de memoria para esse ponteiro, na função manipulamos o ponteiro e através dele
    o conteúdo para onde aponta.
*/
No* desempilhar(No **topo)
{
    if (*topo != NULL)
    {
        No *remover = *topo;
        *topo = remover->proximo;
        return(remover);
    }
    else
    {
        printf("\nPilha vazia!\n");
    }
    
    return(NULL);
}


void imprimirPilha(No *topo)
{
    printf("\n-------------------- PILHA ------------------------\n");
    
    while (topo != NULL)    // ou while (topo)
    {
        imprimirPessoa(topo->p);
        topo = topo->proximo;
    }
    printf("\n-------------------- FIM PILHA --------------------\n");
}


int main()
{
    No *remover, *topo = NULL;
    int opcao;
    
    do
    {
        printf("\n0 - Sair\n1 - Empilhar\n2 - Desempilhar\n3 - Imprimir\n");
        scanf("%d", &opcao);
        getchar();
        
        switch (opcao)
        {
            case 1:
                topo = empilhar(topo);
                break;
            case 2:
                remover = desempilhar(&topo);
                
                if (remover != NULL)
                {
                    printf("\nElemento removido com sucesso!\n");
                    imprimirPessoa(remover->p);
                    
                    free(remover);
                }
                else
                {
                    printf("\nSem no a remover\n");
                }
                break;
            case 3:
                imprimirPilha(topo);
                break;
            default:
                if (opcao != 0)
                {
                    printf("\nOpcao inválida!\n");
                }
        }
    }
    while (opcao != 0);
    
    return(0);
}