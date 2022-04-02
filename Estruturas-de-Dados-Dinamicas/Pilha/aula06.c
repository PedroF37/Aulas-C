#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
                                        Aula 06: Notação pós-fixa polonesa (calculadoras HP)
                                        
                                        Infixa                                  Pós-fixa
                                        (51 + 13 * 12)                          51 13 12 * +                        R = 207
                                        (5 * (3 + 2) / 4 - 6)                   5 3 2 + * 4 / 6 -                   R = 0.25
                                        (5 + 3 + 2 * 4 - 6 * 7 * 1)             5 3 + 2 4 * + 6 7  * 1  * -         R = -26
                                        (5 * (3 + (2 * (4 + (6 * (7 + 1))))))   5 3 2 4 6 7 1 + * + * + *           R = 535
*/

typedef struct no
{
    float valor;
    struct no *proximo;
}
No;


/* Função para empilhar */
No* empilhar(No *topo, float valor)
{
    No *novo = malloc(sizeof(No));
    
    if (novo != NULL)
    {
        novo->valor = valor;
        novo->proximo = topo;
        return(novo);
    }
    else
    {
        printf("\nErro ao alocar memoria!\n");
    }
    
    return(NULL);
}


/* Função para desempilhar */
No* desempilhar(No **topo)
{
    No *remover = NULL;
    
    if (*topo != NULL)
    {
        remover = *topo;
        *topo = remover->proximo;
    }
    else
    {
        printf("\nPilha vazia!\n");
    }
    
    return(remover);
}


/*
    Função para descobrir a expressão
    
    soma, multiplicar, divisão ...
*/
float operacao(float a, float b, char x)
{
    switch (x)
    {
        case '+':
            return(a + b);
            break;
        case '-':
            return(a - b);
            break;
        case '*':
            return(a * b);
            break;
        case '/':
            //printf("A: %f\tB: %f\n", a, b);
            return(a / b);
            break;
        default:
            /* Caso a espressao estaja mal formada */
            return(0.0);
    }
}


/*
    Lógica da notação pós-fixa com pilha:
    
    Se encontramos um sinal (+ - / *etc), temos que
    desempilhar os dois valores (números) anteriores
    para realizar a operação (somar, multipplicar etc) com eles
    logo, usamos dois ponteiros, dois Nos;
*/
float resolverExpressao(char expressao[])   // 2 + * 4 / 6 -
{
    /*
        A função strtok, retorna um ponteiro em cada chamada
        para o token (a parte da string que foi "separada").
        Por isso, declaramos o ponteiro *pt, que vai recebendo
        esse proximo token.
    */
    char *pt;
    float resultado;
    No *n1, *n2, *topo = NULL;
    
    pt = strtok(expressao, " ");
    
    while (pt)
    {
        /* Se o pprimeiro elemento aponttado (o indice 0) por pt for um destes... */
        if (pt[0] == '+' || pt[0] == '-' || pt[0] == '*' || pt[0] == '/')
        {
            n1 = desempilhar(&topo);
            n2 = desempilhar(&topo);
            
            /*
                Aqui enviamos na ordem contrária, porque se não na exprerssao:
                2 + * 4 / 6 -, quando chegar no sinal de divisão (/), a função
                operação() iria fazer 4 / 25 e ia dar o resutado errado. 
            */
            resultado = operacao(n2->valor, n1->valor, pt[0]);
            topo = empilhar(topo, resultado);
            free(n1);
            free(n2);
        }
        else
        {
            /*
                strtol();
                
                Parametros:
                
                1 - onde está o número para converter (nste caso em pt)
                2 - se em pt estivesse: 58 anos, o segundo parametro seria um ponteiro para ponteiro "**pt"para
                    colcar o restante da string (anos). Ou seja, resultado recebia 58, e anos iam para o **pt. 
                    Como AQUI só temos números, neste segundo parametro colocamos NULL. 
                3 - A base numérica com qual queremos trabalhar, se queremos converter para decimal, octal, etc
                    Neste caso, convertemos para decimal (base 10);
            */
            resultado = strtol(pt, NULL, 10);
            topo = empilhar(topo, resultado);
        }
        
        pt = strtok(NULL, " ");
    }
    
    n1 = desempilhar(&topo);
    resultado = n1->valor;
    free(n1);
    return(resultado);
}


int main()
{
    char exp[50] = {"5 3 2 4 6 7 1 + * + * + *"};
    
    printf("\nResultado de %s :\t", exp);
    printf("%.2f\n", resolverExpressao(exp));
    
    return(0);
}