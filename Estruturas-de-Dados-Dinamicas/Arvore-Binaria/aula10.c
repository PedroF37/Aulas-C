#include <stdio.h>
#include <stdlib.h>

/*

                                                Aula 10: Árvore Binária de Busca de Pessoas (struct Pessoa)

*/


typedef struct
{
    char nome[50];
    int cpf;
}
Pessoa;


typedef struct no
{
    Pessoa pessoa;
    struct no *esquerda, *direita;
}
NoArvore;


/* Função para ler os dados de uma pessoa */
Pessoa lerPessoa()
{
    Pessoa pessoa;
    
    printf("\tDigite o nome: ");
    fgets(pessoa.nome, 49, stdin);
    
    printf("\tDigite o cpf: ");
    scanf("%d", &pessoa.cpf);
    
    return(pessoa);
}


/* Prcedimento para imprimir as informações de uma pessoa */
void imprimirPessoa(Pessoa pessoa)
{
    printf("\tNome: %s\tCPF: %d\n", pessoa.nome, pessoa.cpf);
}


/* Função para inserir na Arvore */
NoArvore* inserirVersao1(NoArvore *raiz, Pessoa pessoa)
{
    if (raiz == NULL)
    {
        NoArvore *aux = malloc(sizeof(NoArvore));
        aux->pessoa = pessoa;
        aux->esquerda = NULL;
        aux->direita = NULL;
        return(aux);
    }
    else
    {
        if (pessoa.cpf < raiz->pessoa.cpf)
        {
            raiz->esquerda = inserirVersao1(raiz->esquerda, pessoa);
        }
        else
        {
            raiz->direita = inserirVersao1(raiz->direita, pessoa);
        }
        
        return(raiz);
    }
}


/* procedimento para inserir na Arvore Versão 2, um pouco mais eficiente que a versão 1 */
void inserirVersao2(NoArvore **raiz, Pessoa pessoa)
{
    if (*raiz == NULL)
    {
        *raiz = malloc(sizeof(NoArvore));
        (*raiz)->pessoa = pessoa;
        (*raiz)->esquerda = NULL;
        (*raiz)->direita = NULL;
    }
    else
    {
        if (pessoa.cpf < (*raiz)->pessoa.cpf)
        {
            inserirVersao2(&((*raiz)->esquerda), pessoa);
        }
        else
        {
            inserirVersao2(&((*raiz)->direita), pessoa);
        }
    }
}


/* Terceira versão para inserir na Arvore, versão mais eficiente das tres versões*/
void inserirVersao3(NoArvore **raiz, Pessoa pessoa)
{
    NoArvore *aux = *raiz;
    
    while (aux != NULL)
    {
        if (pessoa.cpf < aux->pessoa.cpf)
        {
            raiz = &aux->esquerda;
        }
        else
        {
            raiz = &aux->direita;
        }
        
        aux = *raiz;
    }
    
    aux = malloc(sizeof(NoArvore));
    aux->pessoa = pessoa;
    aux->esquerda = NULL;
    aux->direita = NULL;
    *raiz = aux;
}


/* Função de busca */
NoArvore* buscarVersao1(NoArvore *raiz, int cpf)
{
    if (raiz != NULL)
    {
        if (cpf == raiz->pessoa.cpf)
        {
            return (raiz);
        }
        else if (cpf < raiz->pessoa.cpf)
        {
            return(buscarVersao1(raiz->esquerda, cpf));
        }
        else
        {
            return(buscarVersao1(raiz->direita, cpf));
        }
    }
    
    return(NULL);
}


/* Função de busca Versão 2 sem recursao */
NoArvore* buscarVersao2(NoArvore *raiz, int cpf)
{
    while (raiz != NULL)
    {
        if (cpf < raiz->pessoa.cpf)
        {
            raiz = raiz->esquerda;
        }
        else if (cpf > raiz->pessoa.cpf)
        {
            raiz = raiz->direita;
        }
        else
        {
            return(raiz);
        }
    }
    
    return(NULL);
}


/* Função para calcular a arltura da árvore */
int altura(NoArvore *raiz)
{
    if (raiz == NULL)
    {
        return(-1);
    }
    else
    {
        int esq = altura(raiz->esquerda);
        int dir = altura(raiz->direita);
        
        if (esq > dir)
        {
            return(esq + 1);
        }
        else
        {
            return(dir + 1);
        }
    }
}


/* Função para contar a quantidade de nos na árvore */
int quantidadeNos(NoArvore *raiz)
{
    if (raiz == NULL)
    {
        return(0);
    }
    else
    {
        return(1 + quantidadeNos(raiz->esquerda) + quantidadeNos(raiz->direita));
    }
    
    /* Operador ternario */
    // return((raiz == NULL)? 0: 1 + quuantidadeNos(raiz->esquerda) + quantidadeNos(raiz->direita));
}


/* Função para contar as folhas na arvore */
int quantidadeFolhas(NoArvore *raiz)
{
    if (raiz == NULL)
    {
        return(0);
    }
    else if (raiz->esquerda == NULL && raiz->direita == NULL)
    {
        return(1);
    }
    else
    {
        return(quantidadeFolhas(raiz->esquerda) + quantidadeFolhas(raiz->direita));
    }
}


/* Função ppara remover nós de arvore binária */
NoArvore* remover(NoArvore *raiz, int chave)
{
    if (raiz == NULL)
    {
        printf("Valor não encontrado!\n");
        return(NULL);
    }
    else
    {
        /* Procura o no a remover */
        if (raiz->pessoa.cpf == chave)
        {
            /* Remove nós folhas (nós sem filhos)*/
            if (raiz->esquerda == NULL && raiz->direita == NULL)
            {
                free(raiz);
                printf("Elemento folha removido: %d\n", chave);
                return(NULL);
            }
            else
            {
                /* Remove nós que tenham 2 filhos*/
                if (raiz->esquerda != NULL && raiz->direita != NULL)
                {
                    Pessoa pessoa;
                    NoArvore *aux = raiz->esquerda;
                    
                    while (aux->direita != NULL)
                    {
                        aux = aux->direita;
                    }
                    
                    pessoa = raiz->pessoa;
                    
                    raiz->pessoa = aux->pessoa;
                    aux->pessoa = pessoa;
                    printf("Elemento trocado: %d\n", chave);
                    raiz->esquerda = remover(raiz->esquerda, chave);
                    return(raiz);
                    
                }
                else
                {
                    /* Remove nós que só tenham  1 filho */
                    NoArvore *aux;
                    
                    if (raiz->esquerda != NULL)
                    {
                        aux = raiz->esquerda;
                    }
                    else
                    {
                        aux = raiz->direita;
                    }
                    
                    free(raiz);
                    printf("Elemento om 1 filho removido: %d\n", chave);
                    return(aux);
                }
            }
        }
        else
        {
            if (chave < raiz->pessoa.cpf)
            {
                raiz->esquerda = remover(raiz->esquerda, chave);
            }
            else
            {
                raiz->direita = remover(raiz->direita, chave);
            }
            
            return(raiz);
        }
    }
}


/* Procedimento para imprimir a Arvore  versáo 1*/
void imprimirVersao1(NoArvore *raiz)
{
    if (raiz != NULL)
    {
        imprimirPessoa(raiz->pessoa);
        imprimirVersao1(raiz->esquerda);
        imprimirVersao1(raiz->direita);
    }
}

/* Procedimento para imprimir a Arvore ordenada */
void imprimirVersao2(NoArvore *raiz)
{
    if (raiz != NULL)
    {
        imprimirVersao2(raiz->esquerda);
        imprimirPessoa(raiz->pessoa);
        imprimirVersao2(raiz->direita);
    }
}

int main()
{
    NoArvore *raiz = NULL, *busca;
    int opcao, valor;
    
    do
    {
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Imprimir\n\t3 - Buscar\n\t"
            "4 - Altura\n\t5 - Tamanho\n\t6 - Folhas\n\t7 - Remover\n");
        scanf("%d", &opcao);
        getchar();
        
        switch (opcao)
        {
            case 1:
                //printf("Digite um valor: ");
                //scanf("%d", &valor);
                //raiz = inserirVersao1(raiz, valor);
                //inserirVersao2(&raiz, valor);
                inserirVersao3(&raiz, lerPessoa());
                break;
            case 2:
                printf("\n\tPrimeira impressao:\n\t");
                imprimirVersao1(raiz);
                printf("\n");
                printf("\n\tSegunda impressao:\n\t");
                imprimirVersao2(raiz);
                printf("\n");
                break;
            case 3:
                printf("Digite cpf :");
                scanf("%d", &valor);
                //busca = buscarVersao1(raiz, valor);
                busca = buscarVersao2(raiz, valor);
                if (busca != NULL)
                {
                    printf("\n\tValor encontrado: %d\n", busca->pessoa.cpf);
                }
                else
                {
                    printf("\n\tValor nao encontrado\n");
                }
                break;
            case 4:
                printf("\n\tAltura da arvore: %d\n\n", altura(raiz));
                break;
            case 5:
                printf("\nQuantidade de nos: %d\n", quantidadeNos(raiz));
                break;
            case 6:
                printf("\n\tQuantidade de folhas: %d\n", quantidadeFolhas(raiz));
                break;
            case 7:
                printf("\t");
                imprimirVersao2(raiz);
                printf("\n\tDigite o cpf a ser removido: ");
                scanf("%d", &valor);
                raiz = remover(raiz, valor);
                break;
            default:
                if (opcao != 0)
                {
                    printf("\nOpçao invalida.\n");
                }
        }
    }
    while (opcao != 0);
    return(0);
}
