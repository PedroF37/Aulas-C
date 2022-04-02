#include <stdio.h>
#include <stdlib.h>

/*
                             Aula 02: Estruturas  de dados dinâmicas (Pilha)
                             Versão 2 -> sem ponteiro para ponteiro
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
    Struct No, com apelido no;
    
    Tem como elementos internos a variável p (struct tipo de  dado Pessoa)
    e o ponteiro proximo com o endereço na memoria da próxima struct No
*/
typedef struct no
{
    Pessoa p;
    struct no *proximo;
}
No;


/*
    Struct Pilha com elementos internos sendo
    o ponteiro topo, com o endereço na memória do No (struct No) que está
    no topo da Pilha, e  tamanho da pilha.
*/
typedef struct
{
    No *topo;
    int tam;
}
Pilha;


/*
    Procedimento para Criar (ou inicializar) a Pilha.
    
    Recebe como parâmetro o ponteiro p do tipo Pilha (struct)
    O ponteiro p tem o endereço na memória da struct Pilha.
*/
void criarPilha(Pilha *p)
{
    /*
        Ao principio, a Pilha (o ponteiro topo com o endereço na memoria
        de uma struct No, não aponta para nada porque a pilha começa vazia
        e a variavel tam, então terá tamanho 0)
    */
    p->topo = NULL;
    p->tam = 0;
}


Pessoa lerPessoa()
{
    Pessoa p;
    
    printf("\nDigite o nome e data de nascimento dd mm aaaa:\n");
    scanf("%49[^\n]%d%d%d", p.nome, &p.data.dia, &p.data.mes, &p.data.ano);
    
    return(p);
}


void imprimirPessoa(Pessoa p)
{
    printf("\nNome: %s\nData: %2d/%2d/%4d\n", p.nome, p.data.dia, p.data.mes, p.data.ano);
}


/*
    Procedimento para a operação push (empilhar)
    
    Recebe como parâmetro um ponteiro com o endereço na memoria
    de uma struct Pilha.
*/
void empilhar(Pilha *p)
{
    /*
        Alocamos memória para o ponteiro novo
        Ponteiro novo terá o endereço na memóris de uma struct No
    */
    No *novo = malloc(sizeof(No));
    
    if (novo)
    {
        /*
            A struct No, no elemento interno p do Tipo Pessoa (struct)
            recebe o retorno de lerPessoa.
            
            Depois o elemento interno proximo (ponteiro) da struct No que aponta para
            a proxima struct No recebe o conteudo do ponteiro topo que tem o endereço da antiga
            struct No que estava no topo da Pilha.
            
            Depois, o ponteiro topo, que apontava (tinha o endereço na memoria) para a struct No que estava
            no topo da pilha, recebeo conteud o apontado (endereço de memória) do ponteiro novo. Porque agora
            novo está no topo da pilha e é para onde *topo tem que apontar
        */
        novo->p = lerPessoa();
        novo->proximo = p->topo;
        p->topo = novo;
        p->tam++;
    }
    else
    {
        printf("\nErro ao alocar memoria!\n");
    }
}


/*
    Função para desempilhar (pop)
    
    Retorna o No (a struct) que foi removida (desempilhada)
    
    Recebe como parâmetro um ponteiro com o endereço na memória de uma struct Pilha
     
*/
No* desempilhar(Pilha *p)
{
    /*
        Se o ponteiro topo na pilha não for nulo
        ponteiro remover recebe o endereço na memória
        do conteúdo de topo (uma struct que está no topo da pilha)
        
        Depois, o ponteiro topo, que tinha o endereço da struct no topo da pilha,
        recebe o endereço na memória armazenado em proximo, que aponta para struct que
        estava em segundo lugar na pilha, e qua agora vai ppassar a ser o top da pilha.
        
        E retornamos o endereço na memória da struct que tiramos do topo (ponteiro remover)
        
    */
    if (p->topo != NULL)
    {
        No *remover = p->topo;
        p->topo = remover->proximo;
        p->tam--;
        return(remover);
    }
    else
    {
        printf("\nPilha vazia!\n");
    }
    
    return(NULL);
}


void imprimirPilha(Pilha *p)
{
    No *aux = p->topo;
    printf("\n-------------------- PILHA Tam: %d ------------------------\n", p->tam);
    
    while (aux)    // ou while (topo)
    {
        imprimirPessoa(aux->p);
        aux = aux->proximo;
    }
    printf("\n-------------------- FIM PILHA --------------------\n");
}


int main()
{
    No *remover;
    Pilha p;
    int opcao;
    
    criarPilha(&p);
    
    do
    {
        printf("\n0 - Sair\n1 - Empilhar\n2 - Desempilhar\n3 - Imprimir\n");
        scanf("%d", &opcao);
        getchar();
        
        switch (opcao)
        {
            case 1:
                empilhar(&p);
                break;
            case 2:
                remover = desempilhar(&p);
                
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
                imprimirPilha(&p);
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