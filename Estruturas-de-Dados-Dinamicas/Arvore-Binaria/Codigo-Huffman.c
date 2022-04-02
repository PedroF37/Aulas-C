#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>


/*
                                                            Código de Huffman
                                                            
                                                    Dá um monte de warnings ao compilar que ainda não olhei como resolver
                                                    mas compila e executa.
                                                            
*/


#define TAM 256


/* No para a lista ordenada e para a Arvore */
typedef struct no
{
   unsigned char caracter;
   int frequencia;
   struct no *esq, *dir, *proximo; 
}
No;


/* Lista que representa a lista ordenada*/
typedef struct
{
    /* Ponteiro para o primeiro no da lista*/
    No *inicio;
    int tam;
}
Lista;


/* ------------------------------------------------ Parte 1: Tabela de Frequência ----------------------------------------------------------- */


/* Procedimento para inicializar a tabela de frequencia */
void inicializarTabelaComZero(unsigned int tabela[])
{
    int i;
    
    for (i = 0; i < TAM; i++)
    {
        tabela[i] = 0;
    }
}


/* Procedimento para contar a frequência dos caracteres */
void preencherTabelaFrequencia(unsigned char texto[], unsigned int tabela[])
{
    int i = 0;
    
    while (texto[i] != '\0')
    {
        /*
            Enquanto não chegar no fim da string, a tabela na posição
            do caracter é incrementada. Se achou o 'a' o codigo é 97, então
            tabela no indice 97 recebe +1 se tinha 1 ocorrencia agora tem duas.
        */
        tabela[texto[i]]++;
        i++;
    }
}


/* Procedimento para imprimir a tabela de frequência */
void imprimirTabelaFrequencia(unsigned int tabela[])
{
    int i;
    
    printf("\tTABELA DE FREQUENCIA\n");
    for (i = 0; i < TAM; i++)
    {
        if (tabela[i] > 0)
        {
            printf("\t%d = %u = %c\n", i, tabela[i], i);
        }
    }
}


/* ------------------------------------------------- Parte 2: Lista Encadeada Ordenada ------------------------------------------------------------ */


/* Procedimento para criar a Lista */
void criarLista(Lista *lista)
{
    lista->inicio = NULL;
    lista->tam = 0;
}


/* Procedimento para inserir ordenado */
void inserirOrdenado(Lista *lista, No *no)
{
    No *aux;
    
    /* A lista está vazia? */
    if (lista->inicio == NULL)
    {
        lista->inicio = no;
    }
    /* 
        Lista não está vazia, mas, o elemento a inserir tem uma
        frequencia menor do que o elemento na lista? 
    */
    else if (no->frequencia < lista->inicio->frequencia)
    {
        no->proximo = lista->inicio;
        lista->inicio = no; 
    }
    /*
        Lista não está vazia, mas, a frequencia do no a inserir
        não é menor que o elemento no inicio da lista
    */
    else
    {
        /* Neste caso, temos que percorrer a lista para ver onde colocar o elemento*/
        aux = lista->inicio;
        
        while (aux->proximo != NULL && aux->proximo->frequencia <= no->frequencia)
        {
            aux = aux->proximo;
        }
        
        no->proximo = aux->proximo;
        aux->proximo = no;
    }
    
    lista->tam++;
}


/* Procedimento para preencher a lista */
void preencherLista(unsigned int tabela[], Lista *lista)
{
    int i;
    No *novo;
    
    /*
        Percorremos a tabela, e para cada elemento que seja maior que zero,
        ou seja, para cada elemento que apareca pelo menos uma vez, criamos
        um no e passamos para o procedimento inserirOrdenado.
    */
    for (i = 0; i < TAM; i++)
    {
        if (tabela[i] > 0)
        {
            novo = malloc(sizeof(No));
            
            /*
                Se a memória foi alocada com sucesso, então preenchemos o no
                com os dados do caracter, a frequencia etc.. para depois enviar
                o nó para o inserirOrdenado
            */
            if (novo != NULL)
            {
                novo->caracter = i;
                novo->frequencia = tabela[i];
                novo->dir = NULL;
                novo->esq = NULL;
                novo->proximo = NULL;
                
                inserirOrdenado(lista, novo);
            }
            else
            {
                printf("ERRO ao alocar memoria em preencherLista().\n");
                break;
            }
        }
    }
}


/* Procedimento para imprimir a Lista */
void imprimirLista(Lista *lista)
{
    No *aux = lista->inicio;
    
    printf("\n\tLista Ordenada: Tamanho: %d\n", lista->tam);
    while (aux != NULL)
    {
        printf("\tCaracter: %c Frequência: %d\n", aux->caracter, aux->frequencia);
        aux = aux->proximo;
    }
}


/* ----------------------------------------------- Parte 3: Montar a Árvore de Huffman --------------------------------------------------- */


/*
    Função para remover no do inicio da lista
    Removemos do inicio, porque a lista está ordenada
    do no com menor frequencia para o no com maior frequencia
*/
No* removerNoInicio(Lista *lista)
{
    No *aux = NULL;
    
    if (lista->inicio != NULL)
    {
        aux = lista->inicio;
        lista->inicio = aux->proximo;
        
        /*
            aux é o no que vai ser removido,
            logo proximo não aponta para nada
        */
        aux->proximo = NULL;
        lista->tam--;
    }
    
    return(aux);
}


/* Função para montar a Árvore */
No* montarArvore(Lista *lista)
{
    /*
        Como removemos sempre de dois em dois, (os dois com menor frequencia),
        primeiro pega um e segundo pega outro, e novo é o No que retornamos
    */
    No *primeiro, *segundo, *novo;
    
    /* Executa enquanto a lista tiver mais que um no */
    while (lista->tam > 1)
    {
        primeiro = removerNoInicio(lista);
        segundo = removerNoInicio(lista);
        
        novo = malloc(sizeof(No));
        
        /*
            Agora novo pega o primeiro e o segundo:
            [novo: freq = primeiro + segunndo]
            
        */
        if (novo != NULL)
        {
            /*
                novo vai ser um nó intermediário e não um no folha,
                então novo->caracter não precisa preencher se não quiser.
            */
            novo->caracter = '+';
            novo->frequencia = primeiro->frequencia + segundo->frequencia;
            novo->esq = primeiro;
            novo->dir = segundo;
            novo->proximo = NULL;
            
            /*
                Aqui agora, colocamos de novo na lista ordenada o no.
                Neste caso o no novo ao qual foram conetados dois nos
                que tinhamos removido da lista. 
            */
            inserirOrdenado(lista, novo);
        }
        else
        {
            printf("\n\tERRO ao alocar memoria em montarArvore().");
            
            /* Ou, como esta função tem retorno, em vez do break, podia ser return(NULL) */
            break;
        }
    }
    
    return(lista->inicio);
}


/* Procedimento para imprimir a Árvore */
void imprimirArvore(No *raiz, int tam)
{
    /* Só imprimimos os nos folha, os nos intermediarios não tem caracter válido */
    if (raiz->esq == NULL && raiz->dir == NULL)
    {
        printf("\tFolha: %c\tAltura: %d\n", raiz->caracter, tam);
    }
    else
    {
        imprimirArvore(raiz->esq, tam + 1);
        imprimirArvore(raiz->dir, tam + 1);
    }
}


/* ----------------------------------------------- Parte 4: Montar o dicionário ------------------------------------------------------ */


/*
    Função para calcular a altura da Árvore
    Altura da Árvore é o maior caminho da raiz
    da Árvore até ao no folha mais distante
*/
int alturaArvore(No *raiz)
{
    int esq, dir;
    
    
    if (raiz == NULL)
    {
        return(-1);
    }
    else
    {
        /*
            É + 1 porque para ir da raiz até a subarvore
            á esquerda ou á direita já temos um caminho.
        */
        esq = alturaArvore(raiz->esq) + 1;
        dir = alturaArvore(raiz->dir) + 1;
        
        /* Retorna o maior */
        if (esq > dir)
        {
            return(esq);
        }
        else
        {
            return(dir);
        }
    }
}


/* Função para alocar a memória para a matriz (o dicionario) */
char** alocaDicionario(int colunas)
{
    int i;
    char **dicionario;
    
    dicionario = malloc(sizeof(char*) * TAM);
    
    for (i = 0; i < TAM; i++)
    {
          dicionario[i] = calloc(colunas, sizeof(char));
    }
    
    return(dicionario);
}


/*
    Procedimento para gerar o dicionario
    *caminho é o código dos caracteres 0110... ex: 'a' '97' -> 00 V -> 11100..
    colunas são as colunas da nossa matriz
*/
void gerarDicionario(char **dicionario, No *raiz, char *caminho, int colunas)
{
    char esquerda[colunas], direita[colunas];
    
    /* Se é no folha */
    if (raiz->esq == NULL && raiz->dir == NULL)
    {
        /*
            Se é um no folha, então, temos que pegar no caminho
            (o código: esquerda 0 direita 1 etc) e colocar em uma
            linha do dicionario (matriz)
            A linha é a linha raiz->caracter:
            dicionario[raiz->caracter] = caminho
            Mas em C ão conseguimos copiar uma string desta forma,
            então, o código abaixo.
        */
        strcpy(dicionario[raiz->caracter], caminho);

    }
    else
    {
        /*
            Se não é no folha, então, vamos montando o caminho.
            esquerda e direita recebem o caminho (10011...)
            depois concatenams co 0 ou 1 dependendo se vamos para a direita
            ou esquerda.
            E depois fazemos a chamadas recursivas, passando os nos esquerdas e direita,
            e os vetores esquerda e direita que tem o caminho (os 0 e 1).
            Vai chegar uma altura em que finalmente chegamos a um no folha e aí
            o codigo acima é executado.
        */
        strcpy(esquerda, caminho);
        strcpy(direita, caminho);
        
        strcat(esquerda, "0");
        strcat(direita, "1");
        
        gerarDicionario(dicionario, raiz->esq, esquerda, colunas);
        gerarDicionario(dicionario, raiz->dir, direita, colunas);
    }
}


/* Procedimento para imprimir o dicionario */
void imprimirDicionario(char **dicionario)
{
    int i;
    
    printf("\n\tDicionario:\n"); 
    for (i = 0; i < TAM; i++)
    {
        if (strlen(dicionario[i]) > 0)
        {
            printf("\t%3d: %s\n", i, dicionario[i]);
        }
    }
}



/* -------------------------------------------------------- Parte 5: Codificar --------------------------------------------------------- */


/* Função para calcular o tamanho da string passada para a função abaixo */
int calcularTamanhoString(char **dicionario, unsigned char *texto)
{
    int i = 0, tam = 0;
    
    while (texto[i] != '\0')
    {
        tam = tam + strlen(dicionario[texto[i]]);
        i++;
    }
    
    return(tam + 1);    // o + 1 é para incluir o caracter de fim de string '\0'
}


/* Funçao para codificar o texto. */
char* codificar(char **dicionario, unsigned char *texto)
{
    int i = 0, tam = calcularTamanhoString(dicionario, texto);
    char *codigo = calloc(tam, sizeof(char));
    
    while (texto[i] != '\0')
    {
        strcat(codigo, dicionario[texto[i]]);
        i++;
    }
    
    return(codigo);
}


/* ------------------------------------------------ Parte 6: Decodificação ----------------------------------------------------------- */


/* Função para decodificar a string */

char* decodificar(unsigned char texto[], No *raiz)
{
    int i = 0;
    No *aux  = raiz;
    char temp[2];
    char *decodificado = calloc(strlen(texto), sizeof(char));

    
    while (texto[i] != '\0')
    {
        if (texto[i] == '0')    // '0' -> entre aspas simples porque é caracter
        {
            aux = aux->esq;
        }
        else
        {
            aux= aux->dir;
        }
        
        /* Se for no folha.. */
        if (aux->esq == NULL && aux->dir == NULL)
        {
            /*
                Função strcat() concatena string, não caracter
                então, criamos um vetor, temp com duas posições
                a primeira, temp[0] recebe o caracter e a segunda,
                temp[1] recebe o caracter de fim de string '\0', transformando então
                em uma string, que vai então puder ser concatenada pela strcat().
            */
            temp[0] = aux->caracter;
            temp[1] = '\0';
            strcat(decodificado, temp);
            
            /* Como estamos a decodigficar, aux tem que retornar para a raiz para pegar o proximo caracter */
            aux = raiz;
        }
        
        i++;
    }
    
    return(decodificado);
} 


/* --------------------------------------------- MAIN ------------------------------------------------------------------------------- */


int main()
{
    unsigned char texto[] = "Vamos aprender programação";
    
    /*
        Tabela de Frequência vai ser um vetor de inteiros, que tem o tamanho
        da tabela ascii estendido. Assim, vamos puder acessar diretamente.
        Exemplo:
        Se achamos a letra 'a', pudemos ir no vetor e dizer que no indice 'a' (97 na tabela ascii),
        tem uma ocorrenca:
        
        tabela[texto[i]]++; -> tabela -> indice correspondente a 'a' (97) era zero agora é incrementado em um.
    */
    unsigned int tabelaFrequencia[TAM];
    Lista lista;
    No *arvore;
    int colunas;    // colunas é a altura da arvore (quantos nos da raiz até á folha mais distante).
    char **dicionario;
    unsigned char *codificado, *decodificado;
    
    setlocale(LC_ALL, "Portuguese");
    
    /* ------------------------ Tabela de Frequência ------------------------ */
    inicializarTabelaComZero(tabelaFrequencia);
    preencherTabelaFrequencia(texto, tabelaFrequencia);
    imprimirTabelaFrequencia(tabelaFrequencia);
    
    /* -------------------------Lista Encadeada Ordenada -------------------- */
    criarLista(&lista);
    preencherLista(tabelaFrequencia, &lista);
    imprimirLista(&lista);
    
    /* -------------------------- Montar a Árvore de Huffman ------------------ */
    arvore = montarArvore(&lista);
    printf("\n\tÁrvore de Huffman\n");
    imprimirArvore(arvore, 0);
    
    /* -------------------------- Montar o Dicionario ------------------------- */
    colunas = alturaArvore(arvore) + 1; // + 1 aqui é porque temos que contar com o fim de string '\0'
    dicionario = alocaDicionario(colunas);
    gerarDicionario(dicionario, arvore, "", colunas);   // aqui, o caminho é uma string vazia (""), porque estamos a chamar esta função para a raiz da arvore.
    imprimirDicionario(dicionario);
    
    /* -------------------------- Codificar ------------------------------------ */
    codificado = codificar(dicionario, texto);
    printf("\n\tTEXTO CODIFICADO: %s\n", codificado);
    
    /* -------------------------- Decodificar ---------------------------------- */
    decodificado = decodificar(codificado, arvore);
    printf("\n\tTEXTO DECODIFICADO: %s\n", decodificado);    
    
    return(0);
}
